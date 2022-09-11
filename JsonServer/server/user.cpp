#include "user.h"

User::User(std::string username,std::string password,int rank,TcpSocket *socket)
    :m_username(username),m_password(password),m_rank(rank),m_socket(socket)
{

}
//获取用户的套接字指针
TcpSocket *User::getSocket()
{
    return m_socket;
}
//获取用户名
const char *User::getUserName()
{
    return m_username.c_str();
}
//获取用户rank
int User::getRank()
{
    return m_rank;
}
//设置用户rank
void User::setRank(int rank)
{
    if(rank <= 0)
    {
        rank = 0;
    }
    m_rank = rank;
}
