#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "thread.h"
#include "tcpsocket.h"
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>

class TcpSocket;

//Tcp服务器的基类
class TcpServer
{
    friend class TcpSocket;
public:
    TcpServer(int threadNum = 8);

    int listen(int port, const char *ip = NULL);

    //服务器开始运行
    void start();

    void openRead(TcpSocket *s);
    void closeRead(TcpSocket *s);
protected:
    //监听回调函数,由客户连接时会调用
    static void listenCb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int , void *);

    //监听处理函数
    void listenEvent(evutil_socket_t, struct sockaddr_in *);

    /*-------------------------------------------虚函数-----------------------------------------*/
    //客户端连接事件
    virtual void connectEvent(TcpSocket *) {}
    //客户端可读事件
    virtual void readEvent(TcpSocket *) {}
    //客户端可写事件
    virtual void writeEvent(TcpSocket *) {}
    //客户端关闭事件
    virtual void closeEvent(TcpSocket *, short ) {}
private:
    //线程池
    Thread *m_threadPool;
    //线程个数
    int m_threadNum;

    struct event_base *m_base;
    //监听客户端连接
    struct evconnlistener *m_listener;
    //下一个客户连接，负责处理的线程的下标
    int m_nextThread;

};
#endif
