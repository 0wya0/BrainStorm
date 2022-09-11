#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "register.h"
#include "communicate.h"
#include <QMessageBox>
#include <QMovie>
#include <QTimer>
#include "brainstorm.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
private:
    //设置广告
    void setAdvert(QString advertPath);

private slots:

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void loginSlot(QJsonObject json);

    void advertSlot(QJsonObject json);

    void on_closeButton_clicked();

private:
    Ui::Login *ui;

    //通信类指针，负责和服务器通信
    Communicate *m_com;

    //关闭封面广告
    QTimer *m_advertTimer;
    int m_advertSec;
};

#endif // LOGIN_H
