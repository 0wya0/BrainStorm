#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QJsonObject>
#include "communicate.h"
#include "comm.h"    //自定义的数据协议
#include <QMessageBox>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(Communicate *com, QWidget *parent = 0);
    ~Register();

private slots:
    void on_registerButton_clicked();

    void on_returnButton_clicked();

    void rstResultSlots(int);
private:
    Ui::Register *ui;
    //通信
    Communicate *m_com;
};

#endif // REGISTER_H
