#include "db.h"

DB::DB(const char *host, const char *username, const char *password, const char *dbname)
{
    //初始化数据库句柄
    m_mysql = mysql_init(nullptr);
    if(m_mysql == nullptr)
    {
        spdlog::get("BrainStorm")->error("数据库句柄初始化失败(mysql_init)");
        exit(-1);
    }
    //连接mysql服务器
    if(nullptr == mysql_real_connect(m_mysql, host, username, password, dbname, 0, nullptr, 0))
    {
        spdlog::get("BrainStorm")->error("mysql服务器连接失败(mysql_real_connect): {}", mysql_error(m_mysql));
        exit(-1);
    }
    //设置字符集
    if(0 != mysql_query(m_mysql, "set names utf8"))
    {
        spdlog::get("BrainStorm")->error("字符集设置失败(mysql_query): {}", mysql_error(m_mysql));
        exit(-1);
    }
}
//执行数据库语句
bool DB::db_exec(const char *sql)
{
    //数据库句柄加锁
    std::unique_lock<std::mutex> loc(m_mutex);    //智能锁
    //执行数据库语句
    if(0 != mysql_query(m_mysql, sql))
    {
        spdlog::get("BrainStorm")->error("数据库语句执行失败: {}", mysql_error(m_mysql));
        return false;
    }
    return true;
}
//数据库查询
//sql -- 查询语句(输入参数)
//outJson -- 查询结果(输出参数)
bool DB::db_select(const char *sql, Json::Value &outJson)
{
    //数据库句柄加锁
    std::unique_lock<std::mutex> lock{m_mutex};    //智能锁
    //执行数据库语句 -- 查询语句
    if(0 != mysql_query(m_mysql, sql))
    {
        spdlog::get("BrainStorm")->error("数据库查询失败(mysql_query): {}", mysql_error(m_mysql));
        return false;
    }
    //从mysql服务器下载查询结果
    MYSQL_RES *sql_res = mysql_store_result(m_mysql);
    if(nullptr == sql_res)
    {
        if(0 == mysql_errno(m_mysql))   //数据为空
        {
            return true;
        }
        else
        {
            spdlog::get("BrainStorm")->error("数据库查询失败(mysql_store_result): {}", mysql_error(m_mysql));
            return false;
        }
    }
    unsigned int num_fields = mysql_num_fields(sql_res);    //获取数据列数
    MYSQL_FIELD *fetch_field = mysql_fetch_field(sql_res);  //获取表头(字段)
    //从结果集中一行一行地取出数据
    MYSQL_ROW row;
    while(row = mysql_fetch_row(sql_res))
    {
        for(unsigned int i = 0; i < num_fields; i++)
        {
            outJson[fetch_field[i].name].append(row[i]);
        }
    }

    mysql_free_result(sql_res);
    return true;
}




