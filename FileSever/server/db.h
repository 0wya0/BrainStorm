#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <mutex>
#include <spdlog/spdlog.h>
#include <json/json.h>

class DB
{
public:
    DB(const char *host, const char *username, const char *password, const char *dbname);

    //执行数据库语句 -- 增删改
    bool db_exec(const char *sql);
    //数据库查询
    //sql -- 查询语句(输入参数)
    //outJson -- 查询结果(输出参数)
    bool db_select(const char *sql, Json::Value &outJson);
private:
    //数据库句柄
    MYSQL *m_mysql;
    //数据库句柄互斥锁
    std::mutex m_mutex;
};

#endif // DB_H
