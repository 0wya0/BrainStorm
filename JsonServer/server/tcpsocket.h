#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "tcpserver.h"
#include <string>

class TcpServer;

//通信类--负责和客户端通信
class TcpSocket
{
public:
    TcpSocket(TcpServer *tcpServer, struct bufferevent *bev, char *ip, uint16_t port);

    //可读事件回调函数
    static void readEventCb(struct bufferevent *bev, void *ctx);
    //可写事件回调函数
    static void writeEventCb(struct bufferevent *bev, void *ctx);
    //可读事件回调函数
    static void closeEventCb(struct bufferevent *bev, short what, void *ctx);

    //获取Ip
    char *getIp();
    //获取Port
    uint16_t getPort();
    //设置Username
    void setUserName(std::string);
    //获取Username
    std::string getUserName();
    //从客户端读数据
    int readData(void *data, int size);
    //向客户端写数据
    int writeData(const void *data, int size);
    //获取
    struct bufferevent *getBev()
    {
        return m_bev;
    }
private:
    //服务器对象
    static TcpServer *m_tcpServer;
    //与客户通信的句柄
    struct bufferevent *m_bev;
    //客户端Ip
    char *m_ip;
    //客户端端口
    uint16_t m_port;
    //当前套接字绑定的用户名
    std::string m_username;
};

#endif // TCPSOCKET_H
