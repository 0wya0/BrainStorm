#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "communicate.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QTableWidgetItem>
#include <QStringList>
#include <QMessageBox>
#include <QScrollBar>
#include <QString>
#include <QFile>
#include "myftp.h"
#include <QFileDialog>
#include <QMovie>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(Communicate *com, QWidget *parent = 0);
    ~Admin();
private slots:

    //通知用户下载广告
    void advert();
    //登录
    void adminSlot(QJsonObject);

    void on_tabWidget_currentChanged(int index);

    void on_faceAdvert_Button_clicked();

    void on_mainAdvert_Button_clicked();

    void on_setButton_clicked();

private:

    //排位榜
    void rankList(QJsonObject inJson);
    void rankListInit();
    //rank段位对照表
    QString getRankText(int);
private:
    Ui::Admin *ui;
    //通信套接字
    Communicate *m_com;
    MyFTP *m_img;
    //文件存储文件路径
    QString m_filepath;

};

#endif // ADMIN_H
