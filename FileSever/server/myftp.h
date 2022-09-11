#ifndef MYFTP_H
#define MYFTP_H

#include <stdio.h>
#include <spdlog/spdlog.h>
#include "tcpsocket.h"

#define UPLORD              true    //上传文件
#define DOWNLORD            false   //下载文件

typedef struct
{
    bool fileFlag;
    char fileName[512];
    uint64_t fileSize;
} ImgFile;

class TcpSocket;

class MyFTP
{
public:
    MyFTP();

    void readFile(TcpSocket *s);
    //读表头
    void readHead(TcpSocket *s);
    //读文件
    void readContent(TcpSocket *s);
    //0状态
    void reset();
private:
    //图片名称
    char *m_fileName;
    //读表头还是数据
    bool m_fileFlag;
    //标志数据当前进度
    FILE *m_fp;
    uint64_t m_fileSzie;
    uint64_t m_currSize;
};

#endif // MYFTP_H
