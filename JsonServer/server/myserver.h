#ifndef MYSERVER_H
#define MYSERVER_H

#include "tcpserver.h"
#include <spdlog/spdlog.h>
#include "db.h"
#include <json/json.h>
#include <json/reader.h>
#include "comm.h"
#include <map>
#include "user.h"
#include <mutex>
#include <tuple>
#include <stdio.h>
#include <fstream>

#define DEBUG
#define QUESTION_NUM 5

class MyServer : public TcpServer
{
public:
    MyServer();

    //客户端连接事件 -- 重写
    void connectEvent(TcpSocket *);
    //客户端可读事件 -- 重写
    void readEvent(TcpSocket *);
    //客户端可写事件 -- 重写
    void writeEvent(TcpSocket *);
    //客户端关闭事件 -- 重写
    void closeEvent(TcpSocket *, short );
private:
    //发送数据
    void writeData(TcpSocket *s, const Json::Value &inJson);
    //发送数据
    void writeData(TcpSocket *s, void *data, int size);
    //设置日志
    void setLog();

    //注册处理函数
    void Register(TcpSocket *s, const Json::Value &inJson);
    //登录处理函数
    void Login(TcpSocket *s, const Json::Value &inJson);
    //个人训练获取题目
    void SingleGetQuestion(TcpSocket * s);

    //排位赛
    void Rank(TcpSocket * s);
    //排位赛回答问题，转发进度
    void RankAnswer(TcpSocket *s, const Json::Value &inJson);
    //排位赛结束,处理结果
    void RankOver(TcpSocket *s, const Json::Value &inJson);
    //取消匹配
    void RankCancel(TcpSocket * s);
    //开始对决
    void startRank(TcpSocket *, TcpSocket *);
    //初始化rank段位对照表
    void initRankMap();

    //管理员登录
    void Admin(TcpSocket *s, const Json::Value &inJson);
    //管理员查看rank前x名的用户信息
    void RankList(TcpSocket *s);
    //管理员上传广告，通知用户下载
    void Advert(TcpSocket *s, const Json::Value &inJson);
private:
    //记录日志的句柄
    std::shared_ptr<spdlog::logger> m_log;
    //数据库句柄
    DB *m_db;
    //在线用户列表 -- Key: 用户名  Value: 用户指针
    std::map<std::string, User *> m_users;
    std::mutex m_usersLock;     //在线用户列表的锁

    //ranl积分对应段位表 -- Key: rank积分  Value: rank段位
    std::map<int, std::string> m_rankMap;
    //等待排位的队列 -- Key: rank积分  Value: rank的用户socket
    std::map<int, TcpSocket *> m_ranKQueue;
    std::mutex m_rankLock;  //等待排位的队列的锁
};

#endif // MYSERVER_H
