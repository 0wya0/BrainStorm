#ifndef USER_H
#define USER_H

#include <string>
#include "tcpsocket.h"

class User
{
public:
    User(std::string username,std::string password,int rank,TcpSocket *socket);

    //获取用户的套接字指针
    TcpSocket *getSocket();
    //获取用户名
    const char *getUserName();
    //获取用户rank
    int getRank();
    //设置用户rank
    void setRank(int);
private:
    std::string m_username; //用户名(账号)
    std::string m_password; //用户密码
    int m_rank;             //rank分数
    TcpSocket *m_socket;    //通信套接字
};

#endif // USER_H
