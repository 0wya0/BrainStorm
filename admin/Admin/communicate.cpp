#include "communicate.h"

Communicate::Communicate(QString ip, int port, QObject *parent) : QObject(parent)
{
    //连接服务器
    socket.connectToHost(QHostAddress(ip), port);

    connect(&socket, &QTcpSocket::readyRead, this, &Communicate::readData);

}

void Communicate::readData()
{
    QByteArray data;
    while(socket.bytesAvailable())
    {
        data += socket.readAll();
    }
    //数据解析
    QJsonDocument dt = QJsonDocument::fromJson(data);
    if(dt.isEmpty())
    {
        return;
    }
    //处理数据
    QJsonObject root = dt.object();
    int cmd = root["cmd"].toInt();
    switch (cmd)
    {
        case ADMIN:
            emit login(root["result"].toInt());
            break;
        case RANKLIST:
            emit admin(root);
            break;
    }
}

void Communicate::writeData(const QJsonObject &json)
{
    QJsonDocument dt(json);
    QByteArray data = dt.toJson();
    //先发送数据长度再发生数据
    int len = data.size();
    socket.write((char *)&len, sizeof(int));
    socket.write(data);
}
