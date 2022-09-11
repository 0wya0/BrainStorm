#include "myserver.h"
#include <iostream>
MyServer::MyServer()
{
    //数据库
    m_db = new DB(nullptr, "jsetc", "jsetc", "BrainStorm");

    setLog();
    initRankMap();
}

//设置日志
void MyServer::setLog()
{
#ifdef DEBUG
    m_log = spdlog::stdout_color_mt("BrainStorm");
#else
    //在三个文件中循环输出 -- 第一个文件写满写第二个
    m_log = spdlog::rotating_logger_mt("BrainStorm", "../logs/BrainStorm.log", 1024*1024*5, 3);
    m_log->flush_on(spdlog::level::info);   //日志等级
#endif
}

//客户端连接事件 -- 重写
void MyServer::connectEvent(TcpSocket *s)
{
    m_log->info("客户端连接[{}:{}]\n", s->getIp(), s->getPort());
}

//客户端可读事件 -- 重写
void MyServer::readEvent(TcpSocket *s)
{
    //读json包
    char buf[1024] = {0};
    while(1)
    {
        int len = 0;
        s->readData(&len, sizeof(len));
        if(len <= 0)
        {
            break;
        }
        s->readData(buf, len);  //读出数据
        //数据解析
        Json::Value root;
        Json::Reader reader;    //json解析器
        if(!reader.parse(buf, root))
        {
            m_log->error("Json数据解析失败");
            return;
        }
        //提取数据
        int cmd = root["cmd"].asInt();
        switch (cmd)
        {
            case REGISTER:  //注册新用户
                Register(s, root);
                break;
            case LOGIN:     //用户登录
                Login(s, root);
                break;
            case SIGNLE_GETQUESTION:    //个人训练获取题目
                SingleGetQuestion(s);
                break;
            case RANK:      //排位赛-匹配
                Rank(s);
                break;
            case ANSWER:    //答题同步
                RankAnswer(s, root);
                break;
            case RANKOVER:  //排位赛结束
                RankOver(s, root);
                break;
            case CANCEL:    //取消匹配
                RankCancel(s);
                break;

            case ADMIN:     //admin登录
                Admin(s, root);
                break;
            case RANKLIST:  //admin查看top20
                RankList(s);
                break;
            case ADVERT:    //广告
                Advert(s, root);
                break;
            default:
                break;
        }
    }
}

//客户端可写事件 -- 重写
void MyServer::writeEvent(TcpSocket *)
{

}

//客户端关闭事件 -- 重写
void MyServer::closeEvent(TcpSocket *s, short)
{
    //用户退出，从在线列表中删除
    std::unique_lock<std::mutex> lock(m_usersLock);
#if 1
    std::map<std::string, User *>::iterator it = m_users.begin();
    for(; it != m_users.end(); it++)
    {
        if(it->second->getSocket() == s)    //用户登录了，从在线列表删除
        {
            m_users.erase(it);
            m_log->info("用户{}-[{}:{}]下线", it->second->getUserName(), s->getIp(), s->getPort());

            //处理用户在等待匹配时意外退出，将用户从排位等待列表中移除
            {
                std::unique_lock<std::mutex> lock(m_rankLock);
                int rank = it->second->getRank();
                auto it = m_ranKQueue.find(rank);
                if(it != m_ranKQueue.end())
                {
                    m_ranKQueue.erase(it);
                }
            }

            //释放User
            delete it->second;
            return;
        }
    }
    m_log->info("用户没登录[{}:{}]",s->getIp(), s->getPort());    //没有User登录的客户端
#else
    if(s->getUserName().empty())
    {
        //m_log->info("[{}:{}]",s->getIp(), s->getPort());    //没有User登录的客户端
        return;
    }
    std::map<std::string, User *>::iterator it = m_users.find(s->getUserName());
    m_users.erase(it);
    m_log->info("用户{}-[{}:{}]", it->second->getUserName(), s->getIp(), s->getPort());
    //释放User
    delete it->second;
#endif
}

//发送数据
void MyServer::writeData(TcpSocket *s, const Json::Value &inJson)
{
    std::string data = inJson.toStyledString();
    s->writeData(data.c_str(), data.length());
}
//发送数据
void MyServer::writeData(TcpSocket *s, void *data, int size)
{
    s->writeData(data, size);
}

//注册处理函数
void MyServer::Register(TcpSocket *s, const Json::Value &inJson)
{
    std::string username = inJson["username"].asString();
    std::string password = inJson["password"].asString();
    //检查用户是否存在
    char sql[256] = {0};
    sprintf(sql, "select *from user where username = '%s' and password = '%s'",
                 username.c_str(), password.c_str());
    int result = OK;
    Json::Value outJson;
    bool ret = m_db->db_select(sql, outJson);
    if(!ret)
    {
        result = ERROR;
        m_log->error("Register select user error");
    }

    if(outJson.isMember("username"))    //用户已存在
    {
        result = USEREXIST;
    }
    else
    {
        memset(sql, 0, sizeof(sql));
        sprintf(sql, "insert into user(username, password, rank) values('%s', '%s', 0)",
                     username.c_str(), password.c_str());
        ret = m_db->db_exec(sql);
        if(!ret)    //插入失败
        {
            result = ERROR;
            m_log->error("Register insert user error");
        }
        else    //插入成功
        {
            m_log->info("Register: user({}) success", username.c_str());
        }
    }
    Json::Value json;
    json["cmd"]    = REGISTER;
    json["result"] = result;
    this->writeData(s, json);
}

//登录处理函数
void MyServer::Login(TcpSocket *s, const Json::Value &inJson)
{
    std::string username = inJson["username"].asString();
    std::string password = inJson["password"].asString();
    //检查用户是否注册
    char sql[256] = {0};
    sprintf(sql, "select *from user where username = '%s' and password = '%s'",
                 username.c_str(), password.c_str());
    int result = OK;
    Json::Value outJson;
    bool ret = m_db->db_select(sql, outJson);
    if(!ret)
    {
        result = ERROR;
        m_log->error("Login select user error");
    }
    //用户存在
    int rank = 0;
    if(outJson.isMember("username"))
    {
        std::unique_lock<std::mutex> lock(m_usersLock);
        if(m_users.find(username) != m_users.end()) //用户已登录
        {
            result = USERLOGIN;
        }
        else    //登录成功
        {
            int i = 0;
            rank = atoi(outJson["rank"][i].asString().c_str());
            User *user = new User(username, password, rank, s);
            m_users.insert(make_pair(username, user));
            m_log->info("用户{}-[{}:{}]登录成功", username, s->getIp(),s->getPort());
            s->setUserName(username);
        }
    }
    else
    {
        result = NAMEORPASSWORD;
    }

    Json::Value json;
    json["cmd"]      = LOGIN;
    json["result"]   = result;
    json["username"] = username;
    json["rank"]     = m_rankMap[rank];
    this->writeData(s, json);   //发送
}

//个人训练获取题目
void MyServer::SingleGetQuestion(TcpSocket * s)
{
    char sql[256] = {0};
    sprintf(sql, "select * from question order by rand() limit %d", QUESTION_NUM);

    int result = OK;
    Json::Value outJson;
    bool ret = m_db->db_select(sql, outJson);   //从服务器获取题目
    if(!ret || outJson["question"].size() != QUESTION_NUM)
    {
        result = ERROR;
        m_log->error("Login select user error");
    }

    Json::Value json;
    json["cmd"]      = SIGNLE_GETQUESTION;
    json["result"]   = result;
    json["question"] = outJson;
    m_log->info("用户{}-[{}:{}]获取题目: {}\n", s->getUserName(), s->getIp(), s->getPort(), json.toStyledString());
    writeData(s, json); //发送
}

//排位赛对决
void MyServer::startRank(TcpSocket *first, TcpSocket *second)
{
    //先获取题目
    char sql[256] = {0};
    sprintf(sql, "select * from question order by rand() limit %d", QUESTION_NUM);

    int result = OK;
    Json::Value outJson;
    bool ret = m_db->db_select(sql, outJson);   //从服务器获取题目
    if(!ret || outJson["question"].size() != QUESTION_NUM)
    {
        result = ERROR;
        m_log->error("startRank select question error");
    }

    Json::Value json;
    json["cmd"]       = RANK;
    json["result"]    = result;
    json["question"]  = outJson; //题目
    //发给first用户
    json["enemyname"] = second->getUserName();  //对手用户名
    json["enemyrank"] = m_rankMap[m_users[second->getUserName()]->getRank()];  //对手段位
    writeData(first, json);
    //发给second用户
    json["enemyname"] = first->getUserName();  //对手用户名
    json["enemyrank"] = m_rankMap[m_users[first->getUserName()]->getRank()];  //对手段位
    writeData(second, json);

    m_log->info("({})和({})的对决题目: {}\n",
                first->getUserName(), second->getUserName(), outJson.toStyledString());
}

//排位赛
void MyServer::Rank(TcpSocket * s)
{
#if 1
    //当前用户的rank积分
    int rank = m_users[s->getUserName()]->getRank();
    m_log->info("({})的rank分: {}", s->getUserName(), rank);

    TcpSocket *enemySocket = nullptr;
    std::unique_lock<std::mutex> lock(m_rankLock);
    //查找对手
    std::map<int, TcpSocket *>::iterator it = m_ranKQueue.find(rank);
    if(it != m_ranKQueue.end())   //先找同一段位
    {
        enemySocket = it->second;   //获取对手的socket
        m_ranKQueue.erase(it);      //从等待排位队列中删除
    }
    else    //再找rank段位相差不到5的对手
    {
        for(int i = 1; i <= 5; i++)
        {
            it = m_ranKQueue.find(rank + i);
            if(it != m_ranKQueue.end())
            {
                enemySocket = it->second;   //获取对手的socket
                m_ranKQueue.erase(it);      //从等待排位队列中删除
                break;
            }
            it = m_ranKQueue.find(rank - i);
            if(it != m_ranKQueue.end())
            {
                enemySocket = it->second;   //获取对手的socket
                m_ranKQueue.erase(it);      //从等待排位队列中删除
                break;
            }
        }
    }

    if(nullptr == enemySocket)  //没找到
    {
        m_ranKQueue.insert(std::make_pair(rank, s));
        m_log->info("等待排位队列当前人数: {}", m_ranKQueue.size());
    }
    else
    {
        //开始对决
        this->startRank(s, enemySocket);
    }
#else
    //当前用户的rank积分
    int rank = m_users[s->getUserName()]->getRank();

    std::map<int, TcpSocket *>::iterator enemy_it;
    std::unique_lock<std::mutex> lock(m_rankLock);
    //查找对手
    for(int i = 0; i <= 5; i++)
    {
        enemy_it = m_ranKQueue.find(rank + i);
        if(enemy_it != m_ranKQueue.end())   //先找同一段位
        {
            break;
        }
        enemy_it = m_ranKQueue.find(rank - i);
        if(enemy_it != m_ranKQueue.end())   //先找同一段位
        {
            break;
        }
    }
    if(enemy_it != m_ranKQueue.end())   //找到了对手
    {
        //先从等待排位队列中删除
        m_ranKQueue.erase(enemy_it);
        //向他们发送题目,开始对决

    }
    else
    {
        m_ranKQueue.insert(std::make_pair(rank, s));
        m_log->info("等待排位队列当前人数: {}", m_ranKQueue.size());
    }
#endif
}

//取消匹配
void MyServer::RankCancel(TcpSocket * s)
{
    std::unique_lock<std::mutex> lock(m_rankLock);
    for(auto it = m_ranKQueue.begin(); it !=m_ranKQueue.end(); ++it)
    {
        if(s == it->second)
        {
            m_ranKQueue.erase(it);
            m_log->info("{}取消了匹配", s->getUserName());
            break;
        }
    }
}

//排位赛回答问题，转发进度
void MyServer::RankAnswer(TcpSocket *s, const Json::Value &inJson)
{
    std::string enemyname = inJson["enemyname"].asString();
    Json::Value json;
    try{
        //转发进度
        User *enemy = m_users.at(enemyname);
        json["cmd"]             = ANSWER;
        json["enemyscore"]      = inJson["score"];
        json["enemyQuestionId"] = inJson["questionId"];
        writeData(enemy->getSocket(), json);
    }
    catch(std::out_of_range)
    {
        //对手在答题时掉线
        json["cmd"] = ENEMYERROR;
        writeData(s, json);
        char sql[256] = {0};
        sprintf(sql, "update user set rank = rank - 1 where username = '%s'", enemyname.c_str());
        m_db->db_exec(sql);
    }
}

//排位赛结束,处理结果
void MyServer::RankOver(TcpSocket *s, const Json::Value &inJson)
{
    char sql[256] = {0};

    int score = inJson["score"].asInt();
    int enemyscore = inJson["enemyscore"].asInt();

    std::unique_lock<std::mutex> lock(m_usersLock);
    User *user = m_users[s->getUserName()];
    if(score < enemyscore)  //失败
    {
        user->setRank(user->getRank() - 1);
    }
    else if(score > enemyscore) //胜利
    {
        user->setRank(user->getRank() + 1);
    }

    sprintf(sql, "update user set rank = %d where username = '%s'", user->getRank(), user->getUserName());
    m_db->db_exec(sql);

    Json::Value json;
    json["cmd"] = RANKOVER;
    json["newRank"] = m_rankMap[user->getRank()];

    writeData(s, json);
}

//初始化rank段位对照表
void MyServer::initRankMap()
{
    char buf[50] = {0};
    int rank = 0;   //保存段位
    int num = 0;    //保存星数
    for(int i = 0; i < 100; i++)
    {
        if(i < 9)
        {
            rank = i / 3;
            num = i % 3;
            sprintf(buf, "青铜%d %d颗星",3-rank, num+1);
        }
        else if(i < 18)
        {
            rank = (i - 9) / 3;
            num = (i - 9) % 3;
            sprintf(buf, "白银%d %d颗星",3-rank, num+1);
        }
        else if(i < 34)
        {
            rank = (i - 18) / 4;
            num = (i - 18) % 4;
            sprintf(buf, "黄金%d %d颗星",4-rank, num+1);
        }
        else if(i < 50)
        {
            rank = (i - 34) / 4;
            num = (i - 34) % 4;
            sprintf(buf, "铂金%d %d颗星",4-rank, num+1);
        }
        else if(i < 75)
        {
            rank = (i - 50) / 5;
            num = (i - 50) % 5;
            sprintf(buf, "钻石%d %d颗星",5-rank, num+1);
        }
        else if(i < 100)
        {
            rank = (i - 75) / 5;
            num = (i - 75) % 5;
            sprintf(buf, "星曜%d %d颗星",5-rank, num+1);
        }
        //printf("%s\n", buf);
        m_rankMap.insert(std::make_pair(i, buf));
    }
}

//管理员登录
void MyServer::Admin(TcpSocket *s, const Json::Value &inJson)
{
    std::string username = inJson["username"].asString();
    std::string password = inJson["password"].asString();

    Json::Value json;
    json["cmd"] = ADMIN;
    //检查用户是否注册
    char sql[256] = {0};
    sprintf(sql, "select *from admin where name = '%s' and pswd = '%s'",
                 username.c_str(), password.c_str());
    Json::Value outJson;
    bool ret = m_db->db_select(sql, outJson);
    if(!ret)
    {
        json["result"] = ERROR;
        m_log->error("Admin login error");
    }
    //用户存在
    if(outJson.isMember("name"))
    {
        std::unique_lock<std::mutex> lock(m_usersLock);
        if(m_users.find(username) != m_users.end()) //用户已登录
        {
            json["result"] = ERROR;
        }
        else    //登录成功
        {
            User *user = new User(username, password, -1 , s);
            m_users.insert(make_pair(username, user));
            m_log->info("管理员{}-[{}:{}]登录成功", username, s->getIp(),s->getPort());
            s->setUserName(username);

            json["result"] = OK;
        }
    }
    else
    {
        json["result"] = ERROR;
    }

    this->writeData(s, json);   //发送
}

void MyServer::RankList(TcpSocket *s)
{
    Json::Value outJson;
    char sql[256] = "select username, rank from user order by rank desc limit 20";
    m_db->db_select(sql, outJson);

    Json::Value json;
    json["cmd"] = RANKLIST;
    json["rankList"] = outJson;

    writeData(s, json);
    m_log->info("{}参看(Rank Top 20)成功", s->getUserName());
}

//管理员上传广告，通知用户下载
void MyServer::Advert(TcpSocket *s, const Json::Value &inJson)
{
    for(auto it = m_users.begin(); it != m_users.end(); it++)
    {
        writeData(it->second->getSocket(), inJson);
    }

    m_log->info("管理员通知用户下载广告成功", s->getUserName());
}
