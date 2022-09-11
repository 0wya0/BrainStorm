#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include "comm.h"    //自定义的数据协议

class Communicate : public QObject
{
    Q_OBJECT
public:
    explicit Communicate(QObject *parent = nullptr);

    void writeData(const QJsonObject &json);
signals:
    //注册
    void rstResult(int);
    //登录
    void loginSignal(QJsonObject);
    //个人训练获取题目
    void singleGetQuestionSignal(QJsonObject);
    //排位赛
    void rankSignal(QJsonObject);
    //广告
    void advertSignal(QJsonObject);

public slots:
    void readData();

private:
    //通信套接字
    QTcpSocket socket;

};

#endif // COMMUNICATE_H
