#include "myftp.h"

MyFTP::MyFTP(QObject *parent) : QObject(parent)
{
    m_writeFile = nullptr;
    m_recvSize = 0;      //已经接收到文件长度
    m_fileSize = 0;      //要接受的文件大小
    //读取文件
    connect(&socket, &QTcpSocket::readyRead, this, &MyFTP::writeFile);
}

MyFTP::~MyFTP()
{
    m_writeFile->close();
}

//连接服务器
void MyFTP::connectServer(QString ip, int port)
{
    //连接服务器
    socket.connectToHost(QHostAddress(ip), port);
    qDebug() << "连接服务器 " << ip << " : " << port;
}
//断开服务器连接
void MyFTP::disconnectServer()
{
    socket.disconnectFromHost();
    socket.close();
    qDebug() << "断开连接服务器 ";
}

void MyFTP::openFile(QString fileName)
{
    m_fileName = fileName;
    if(fileName.endsWith("gif"))
    {
        m_writeFile = new QFile(QString("../client/Res/advert/").append("mainAdvert.gif"));
    }
    else
    {
        m_writeFile = new QFile(QString("../client/Res/advert/").append("faceAdvert.jpg"));
    }

    if(!m_writeFile->open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(nullptr, "文件打开", "文件打开失败", QMessageBox::Yes, QMessageBox::Yes);
        delete m_writeFile;
        m_writeFile = nullptr;
    }
}

void MyFTP::writeFile()
{
    if(nullptr == m_writeFile || socket.bytesAvailable() <= 0)
    {
        return ;
    }
    //读数据
    QByteArray data = socket.readAll();
    //写进文件
//    m_writeFile->write(data);

    m_recvSize += m_writeFile->write(data);
    //qDebug() << m_recvSize;
    //判断是否接受完
    if(m_recvSize >= m_fileSize)
    {
        m_writeFile->close();
        m_writeFile = nullptr;
        m_recvSize = 0;      //已经接收到文件长度
        m_fileSize = 0;      //要接受的文件大小
        emit updateAdvert(m_fileName);
    }
}

//发送表头
void MyFTP::sendHead(qint64 fileSize)
{
    ImgFile img;
    img.fileFlag = DOWNLORD;
    strcpy(img.fileName, m_fileName.toStdString().c_str());
    img.fileSize = fileSize;

    m_fileSize = fileSize;
    //qDebug() << fileSize;
    socket.write((char *)&img, sizeof(img));
}
