#include "myftp.h"

MyFTP::MyFTP(QObject *parent) : QObject(parent)
{
    //连接服务器
    socket.connectToHost(QHostAddress("192.168.1.107"), 8888);
    //读取文件
    connect(&socket, &QTcpSocket::readyRead,[this](){
        QByteArray data = socket.readAll();
        if(strcmp(data.data(), "Start") == 0)
        {
            sendFile();
        }
        else if(strcmp(data.data(), "End") == 0)
        {
            QMessageBox::information(nullptr, "文件上传", "图片上传成功", QMessageBox::Yes, QMessageBox::Yes);
            emit sendOut();
        }
    });
}
MyFTP::~MyFTP()
{
    delete m_fileInfo;
    m_fileInfo = nullptr;
}

//打开文件读
void MyFTP::setReadFile(QString filepath)
{
    if(filepath.isEmpty())
    {
        QMessageBox::critical(nullptr, "文件路径", "文件路径错误", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    m_readFile = new QFile(filepath);
    if(!m_readFile->open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(nullptr, "文件打开", "文件打开失败", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    m_fileInfo = new QFileInfo(filepath);
}
//发送文件
void MyFTP::sendFile()
{
    QByteArray data = m_readFile->readAll();
    socket.write(data);

    m_readFile->close();
    m_readFile = nullptr;
}
//发送表头
void MyFTP::sendHead()
{
    ImgFile img;
    img.fileFlag = UPLORD;
    strcpy(img.fileName, m_fileInfo->fileName().toStdString().c_str());
    img.fileSize = m_fileInfo->size();

    socket.write((char *)&img, sizeof(img));
}

bool MyFTP::isEmpty()
{
    return (m_readFile == nullptr) ? true : false;
}

void MyFTP::resetFileInfo()
{
    delete m_fileInfo;
    m_fileInfo = nullptr;
}
