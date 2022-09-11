#ifndef THREAD_H
#define THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/event_compat.h>
//线程类
class Thread
{
public:
    Thread();
    //线程运行
    void start();
    //获取事件集合
    struct event_base *getBase();

protected:
    //线程工作函数 -- 类的回调函数只能是静态成员函数
    static void *worker(void *);
    //线程逻辑处理函数
    void run();

private:
    //事件集合
    struct event_base *m_base;
    //
    static void pipeRead(evutil_socket_t, short, void *);
    //线程Id
    pthread_t m_threadId;
    //管道Id
    int m_pipeReadFd;
    int m_pipeWriteFd;
    //管道事件
    struct event m_pipeEvent;
};

#endif // THREAD_H

















