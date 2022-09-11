#include "myserver.h"
#include <iostream>
MyServer::MyServer()
{
    //数据库
    m_db = new DB(nullptr, "jsetc", "jsetc", "BrainStorm");
    setLog();
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
    s->getImg()->readFile(s);
}

//客户端可写事件 -- 重写
void MyServer::writeEvent(TcpSocket *)
{

}

//客户端关闭事件 -- 重写
void MyServer::closeEvent(TcpSocket *s, short)
{
    m_log->info("[{}:{}]下线",s->getIp(), s->getPort());    //没有User登录的客户端
}

//发送数据
void MyServer::writeData(TcpSocket *s, void *data, int size)
{
    s->writeData(data, size);
}


