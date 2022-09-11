#ifndef MYFTP_H
#define MYFTP_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>

#define DOWNLORD false   //下载文件

typedef struct
{
    bool fileFlag;
    char fileName[512];
    uint64_t fileSize;
} ImgFile;

class MyFTP : public QObject
{
    Q_OBJECT
public:
    explicit MyFTP(QObject *parent = nullptr);
    ~MyFTP();

    void openFile(QString fileName);

    void writeFile();

    //发送表头,向服务器下载文件
    void sendHead(qint64 fileSize);

    //连接服务器
    void connectServer(QString ip = "192.168.1.107", int port = 8888);
    //断开服务器连接
    void disconnectServer();
signals:
    //通知主线程广告获取成功
    void updateAdvert(QString m_fileName);
public slots:

private:
    //通信套接字
    QTcpSocket socket;

    //写文件
    QString m_fileName;
    QFile *m_writeFile;
    qint64 m_recvSize;      //已经接收到文件长度
    qint64 m_fileSize;      //要接受的文件大小
};

#endif // MYFTP_H
