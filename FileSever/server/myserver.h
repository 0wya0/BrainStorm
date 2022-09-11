#ifndef MYSERVER_H
#define MYSERVER_H

#include "myftp.h"
#include "tcpserver.h"
#include <spdlog/spdlog.h>
#include "db.h"


#define DEBUG

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
    void closeEvent(TcpSocket *, short);
private:
    //发送数据
    void writeData(TcpSocket *s, void *data, int size);
    //设置日志
    void setLog();

    void readFile(TcpSocket *s);
    void readHead(TcpSocket *s);
private:
    //记录日志的句柄
    std::shared_ptr<spdlog::logger> m_log;
    //数据库句柄
    DB *m_db;
};

#endif // MYSERVER_H
