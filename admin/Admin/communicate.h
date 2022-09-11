#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include "comm.h"    //自定义的数据协议
#include <QFile>

#define READ_JSON true
#define READ_FILE false

class Communicate : public QObject
{
    Q_OBJECT
public:
    explicit Communicate(QString ip, int port, QObject *parent = nullptr);

    void writeData(const QJsonObject &json);

    void writeData(const QByteArray &data);

signals:
    void login(int);

    void admin(QJsonObject);

public slots:
    void readData();
private:
    //通信套接字
    QTcpSocket socket;
};

#endif // COMMUNICATE_H
