#include "tcpserver.h"

TcpServer::TcpServer(int threadNum) : m_nextThread(0)
{
    if(threadNum <= 0)
    {
        perror("threadNum <= 0");
        exit(-1);
    }
    m_threadNum = threadNum;
    //创建threaNum个线程
    m_threadPool = new Thread[threadNum];
    if(NULL == m_threadPool)
    {
        perror("threadPool create");
        exit(-1);
    }

    m_base = event_base_new();
    if(!m_base)
    {
        perror("event_base_new");
        exit(-1);
    }

}

int TcpServer::listen(int port, const char *ip)
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;   //IPv4;
    sin.sin_port = htons(port);
    if(NULL != ip)
    {
        //ip = nullptr监听任何ip
        inet_aton(ip, &sin.sin_addr);
        //sin.sin_addr = inet_addr(ip);
    }

    m_listener = evconnlistener_new_bind(m_base, listenCb, this,
                                         LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE, -1,
                                         (struct sockaddr *)&sin, sizeof(sin) );
    if(!m_listener)
    {
        perror("listener create");
        return -1;
    }

    //开启线程池
    for(int i = 0; i < m_threadNum; i++)
    {
        m_threadPool[i].start();
        printf("线程(%d)已启动!\n", i+1);
    }
    return 0;
}

void TcpServer::listenCb(struct evconnlistener * , evutil_socket_t fd, struct sockaddr *clientAddr, int , void * data)
{
    TcpServer *p = (TcpServer *)data;
    p->listenEvent(fd, (struct sockaddr_in *)clientAddr);
}
void TcpServer::listenEvent(evutil_socket_t fd, struct sockaddr_in *clientAddr)
{
    char *ip = inet_ntoa(clientAddr->sin_addr);     //客户端Ip
    uint16_t port = ntohs(clientAddr->sin_port);    //客户端的端口
    //从线程中选择一个线程去处理客户端的请求
    //以轮询的方式选择线程
    struct event_base *base = m_threadPool[m_nextThread].getBase();
    m_nextThread = (m_nextThread + 1) % m_threadNum;
    struct bufferevent *bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
    if(NULL == bev)
    {
        perror("bufferevent_socket_new");
        event_base_loopbreak(base);
        return;
    }
    //创建一个通信对象
    TcpSocket *s = new TcpSocket(this, bev, ip, port);
    //单独封装个类负责和客户端通信(读写事件)
    bufferevent_setcb(bev, s->readEventCb, s->writeEventCb, s->closeEventCb, s);
    bufferevent_enable(bev, EV_READ);    //打开读事件
    bufferevent_enable(bev, EV_WRITE);   //打开写事件
    bufferevent_enable(bev, EV_SIGNAL);   //打开信号

    //调用客户端连接事件
    connectEvent(s);
}

void TcpServer::start()
{
    event_base_dispatch(m_base);
    evconnlistener_free(m_listener);
    event_base_free(m_base);

    printf("listen done\n");
}

