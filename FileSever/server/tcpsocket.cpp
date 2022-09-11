#include "tcpsocket.h"

TcpServer * TcpSocket::m_tcpServer = NULL;

TcpSocket::TcpSocket(TcpServer *tcpServer, struct bufferevent *bev, char *ip, uint16_t port)
{
    m_tcpServer = tcpServer;
    m_bev = bev;
    m_ip = ip;
    m_port = port;

    m_img = new MyFTP;
}

//可读事件回调函数
void TcpSocket::readEventCb(struct bufferevent * , void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpServer->readEvent(s);
}
//可写事件回调函数
void TcpSocket::writeEventCb(struct bufferevent * , void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpServer->writeEvent(s);
}
//可读事件回调函数
void TcpSocket::closeEventCb(struct bufferevent * , short what, void *ctx)
{
    TcpSocket *s = (TcpSocket *)ctx;
    m_tcpServer->closeEvent(s, what);

    delete s;
}

//从客户端读数据
int TcpSocket::readData(void *data, int size)
{
    return bufferevent_read(m_bev, data, size);
}
//向客户端写数据
int TcpSocket::writeData(const void *data, int size)
{
    return bufferevent_write(m_bev, data, size);
}

//获取Ip
char *TcpSocket::getIp()
{
    return m_ip;
}
//获取Port
uint16_t TcpSocket::getPort()
{
    return m_port;
}
//获取文件操作
MyFTP *TcpSocket::getImg()
{
    return m_img;
}
