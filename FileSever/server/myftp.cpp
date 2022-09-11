#include "myftp.h"

MyFTP::MyFTP()
{
    //读表头还是数据
    m_fileFlag = false;
    //标志数据当前进度
    m_fileSzie = 0;
    m_currSize = 0;
    m_fp = nullptr;
}

void MyFTP::readFile(TcpSocket *s)
{
    if(m_fileFlag)  //读文件
    {
        readContent(s);
    }
    else    //读表头
    {
        readHead(s);
    }
}
//读表头
void MyFTP::readHead(TcpSocket *s)
{
    ImgFile img;
    s->readData(&img, sizeof(img));

    if(img.fileFlag)     //上传文件: true
    {
        char pathname[1024] = {0};
        sprintf(pathname, "../Res/%s", img.fileName);
        m_fp = fopen(pathname, "wb");
        if(nullptr == m_fp)
        {
            return;
        }
        m_fileName = new char[strlen(img.fileName)];
        strcpy(m_fileName, img.fileName);
        m_fileSzie = img.fileSize;
        m_currSize = 0;
        m_fileFlag = true;

        //让客户端开始发送
        s->writeData("Start", sizeof("Start"));
    }
    else    //下载文件
    {
        //打开文件
        char pathname[1024] = {0};
        sprintf(pathname, "../Res/%s", img.fileName);
        m_fp = fopen(pathname, "rb");
        if(nullptr == m_fp)
        {
            return;
        }
        //发送给客户端
        int ret = 0;
        char buf[1024] = {0};
        int sum = 0;
        while(ret = fread(buf, 1, sizeof(buf), m_fp))
        {
            s->writeData(buf, ret);
            sum += ret;
            memset(buf, 0, sizeof(buf));
        }
        fclose(m_fp);
        spdlog::get("BrainStorm")->info("客户端[{} : {}]获取图片({})成功: {}",
                                        s->getIp(), s->getPort(), img.fileName, sum);
    }
}

//读文件
void MyFTP::readContent(TcpSocket *s)
{
    char buf[4096] = {0};
    int ret = s->readData(buf, 4096);
    if(fwrite(buf, ret, 1, m_fp) != 1)
    {
        reset();    //恢复最初状态
        return;
    }
    m_currSize += ret;
    if(m_currSize >= m_fileSzie)
    {
        //告知客户端上传成功
        s->writeData("End", sizeof("End"));
        spdlog::get("BrainStorm")->info("图片({})上传成功[{} : {}]",m_fileName, m_fileSzie, m_currSize);
        reset();
    }
}

void MyFTP::reset()
{
    m_fileFlag = false;
    m_fileSzie = 0;
    m_currSize = 0;
    delete []m_fileName;
    fclose(m_fp);
}
