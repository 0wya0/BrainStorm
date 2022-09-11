#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "communicate.h"
#include "admin.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_loginButton_clicked();

    void loginSlot(int);
private:


private:
    Ui::login *ui;

    //通信套接字
    Communicate *m_com;
};

#endif // LOGIN_H
