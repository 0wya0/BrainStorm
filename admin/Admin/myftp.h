#ifndef MYFTP_H
#define MYFTP_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>

#define UPLORD              true    //上传文件

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

    //打开文件读
    void setReadFile(QString filepath);
    void sendHead();
    void sendFile();
    //判断是否有文件可发送
    bool isEmpty();

    void resetFileInfo();
signals:
    //广告上传结束
    void sendOut();
public slots:

private:
    //通信套接字
    QTcpSocket socket;
    //读文件
    QFile *m_readFile;
public:
    QFileInfo *m_fileInfo;  //fileinfo包含路径所有信息
};

#endif // MYFTP_H
