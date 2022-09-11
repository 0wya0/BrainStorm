#include "thread.h"

Thread::Thread()
{
    m_base = event_base_new();
    if(!m_base)
    {
        perror("event_base_new");
        exit(-1);
    }
    //创建管道
    int fd[2] = {0};
    if(-1 == pipe(fd))
    {
        perror("pipe");
        exit(-1);
    }
    m_pipeReadFd = fd[0];
    m_pipeWriteFd = fd[1];
    //让管道事件监听管道读段, 如果监听到管道读段有数据可读
    event_set(&m_pipeEvent, m_pipeReadFd, EV_READ | EV_PERSIST, pipeRead, this);
    //将事件添加到m_base集合中
    event_base_set(m_base, &m_pipeEvent);
    //开启事件的监听
    event_add(&m_pipeEvent, 0);
}

void Thread::pipeRead(evutil_socket_t , short, void *)
{

}

void Thread::start()
{
    //创建一个线程
    int ret = pthread_create(&m_threadId, NULL,worker, this);
    if(-1 == ret)
    {
        perror("pthread_create");
    }

    //分离属性，自动回收线程资源
    pthread_detach(m_threadId);

}

void *Thread::worker(void * arg)
{
    Thread *p = (Thread *)arg;
    p->run();

    return NULL;
}

void Thread::run()
{
//    while(1)
//    {
//        printf("thread : %d\n", m_threadId);
//        sleep(2);
//    }
    //printf("%d: start\n", m_threadId);
    //监听base事件集合
    //event_base_dispatch 死循环 用来处理事件 类似于Qt的exec()
    //如果 m_base 事件集合为空，则event_base_dispatch会立马返回
    //初始化时必须给m_base添加一个事件，让它不为空
    event_base_dispatch(m_base);
    event_base_free(m_base);

    //printf("%d: done\n", m_threadId);
}

struct event_base * Thread::getBase()
{
    return m_base;
}



























