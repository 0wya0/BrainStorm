#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    m_com = new Communicate("192.168.1.107", 6666);

    connect(m_com, &Communicate::login, this, &login::loginSlot);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    QString id = ui->idEdit->text();
    QString psd = ui->psdEdit->text();

    //登录操作--将登录信息发送给服务器
    QJsonObject json;
    json["cmd"]      = ADMIN;
    json["username"] = id;
    json["password"] = psd;

    m_com->writeData(json); //发送
}

void login::loginSlot(int result)
{
    switch (result)
    {
        case OK:
            {
                this->hide();
                Admin *admin = new Admin(m_com);
                admin->show();
                admin->setAttribute(Qt::WA_DeleteOnClose);    //自动释放
            }
            break;
        case ERROR:
            QMessageBox::critical(this, "登录", "登录失败,未知错误");
            break;
//        case USERLOGIN:
//            QMessageBox::critical(this, "登录", "登录失败,不允许重复登录");
//            break;
//        case NAMEORPASSWORD:
//            QMessageBox::critical(this, "登录", "登录失败,账号或密码错误");
//            break;
        default:
            break;
    }
}
