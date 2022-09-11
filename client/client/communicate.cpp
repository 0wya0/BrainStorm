#include "communicate.h"

Communicate::Communicate(QObject *parent) : QObject(parent)
{
    //连接服务器
    socket.connectToHost(QHostAddress("192.168.1.107"), 6666);

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
        case REGISTER:
            emit rstResult(root["result"].toInt());
            break;
        case LOGIN:
            emit loginSignal(root);
            break;
        case SIGNLE_GETQUESTION:
            emit singleGetQuestionSignal(root["question"].toObject());
            break;
        case RANK:
            emit rankSignal(root);
            break;
        case ANSWER:
            emit rankSignal(root);
            break;
        case RANKOVER:
            emit rankSignal(root);
            break;
        case ENEMYERROR:
            emit rankSignal(root);
            break;
        case ADVERT:
            qDebug() << ADVERT;
            emit advertSignal(root);
            break;
        default:
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
