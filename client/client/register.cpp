#include "register.h"
#include "ui_register.h"

Register::Register(Communicate *com, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    m_com = com;

    connect(m_com, &Communicate::rstResult, this, &Register::rstResultSlots);
}

Register::~Register()
{
    delete ui;
}

void Register::on_registerButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString confirm = ui->confirmEdit->text();

    //注册操作--发送注册信息
    QJsonObject json;
    json["cmd"]      = REGISTER;
    json["username"] = username;
    json["password"] = password;

    m_com->writeData(json); //发送

}

void Register::on_returnButton_clicked()
{
    this->close();
}

void Register::rstResultSlots(int ret)
{
    switch (ret)
    {
        case OK:
            QMessageBox::information(this, "注册", "注册成功");
            break;
        case ERROR:
            QMessageBox::critical(this, "注册", "注册失败,未知错误");
            break;
        case USEREXIST:
            QMessageBox::critical(this, "注册", "注册失败,用户已注册");
            break;
        default:
            break;
    }
}
