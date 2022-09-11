#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //设置封面广告
    m_advertTimer = new QTimer;
    m_advertSec = 8;    //五秒自动关闭广告
    m_advertTimer->start(1000);
    ui->closeButton->setText(QString("%1 关闭").arg(m_advertSec));
    connect(m_advertTimer, &QTimer::timeout, [this](){
        --m_advertSec;
        ui->closeButton->setText(QString("%1 关闭").arg(m_advertSec));
        if(m_advertSec == 0)
        {
            m_advertTimer->stop();
            on_closeButton_clicked();   //关闭广告
        }
    });
    ui->stackedWidget->setCurrentWidget(ui->advert_page);
    setAdvert("../client/Res/advert/mainAdvert.gif");

    m_com = new Communicate();
    connect(m_com, &Communicate::loginSignal, this, &Login::loginSlot);
    //connect(m_com, &Communicate::advertSignal, this, &Login::advertSlot);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString id = ui->idEdit->text();
    QString psd = ui->psdEdit->text();

    //登录操作--将登录信息发送给服务器
    QJsonObject json;
    json["cmd"]      = LOGIN;
    json["username"] = id;
    json["password"] = psd;

    m_com->writeData(json); //发送
}

void Login::on_registerButton_clicked()
{
    this->hide();
    Register reg(m_com);
    reg.exec();
    this->show();
}

void Login::loginSlot(QJsonObject json)
{
    int result = json["result"].toInt();
    switch (result)
    {
        case OK:
            {
                this->hide();
                BrainStorm *dlg = new BrainStorm(m_com, json);
                dlg->show();
                dlg->setAttribute(Qt::WA_DeleteOnClose);    //自动释放
            }
            break;
        case ERROR:
            QMessageBox::critical(this, "登录", "登录失败,未知错误");
            break;
        case USERLOGIN:
            QMessageBox::critical(this, "登录", "登录失败,不允许重复登录");
            break;
        case NAMEORPASSWORD:
            QMessageBox::critical(this, "登录", "登录失败,账号或密码错误");
            break;
        default:
            break;
    }
}

void Login::advertSlot(QJsonObject json)
{

}

//设置广告
void Login::setAdvert(QString advertPath)
{
    QMovie * movie = new QMovie(advertPath);
    ui->advertlabel->setMovie(movie);
    ui->advertlabel->setScaledContents(true);
    movie->start();
}

void Login::on_closeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login_page);
}
