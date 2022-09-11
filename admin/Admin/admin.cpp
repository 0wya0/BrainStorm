#include "admin.h"
#include "ui_admin.h"

#include <QDebug>

Admin::Admin(Communicate *com,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    m_com = com;
    m_img = new MyFTP;
    m_filepath = "../Admin/Res";

    rankListInit();

    connect(m_com, &Communicate::admin, this, &Admin::adminSlot);
    connect(m_img, &MyFTP::sendOut, this, &Admin::advert);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::adminSlot(QJsonObject inJson)
{
    int cmd = inJson["cmd"].toInt();
    switch (cmd)
    {
        case RANKLIST:
            rankList(inJson["rankList"].toObject());
            break;
        default:
            break;
    }
}

void Admin::rankList(QJsonObject inJson)
{
    ui->rank_tableWidget->clearContents();

    QJsonArray nameArr = inJson["username"].toArray();
    QJsonArray rankArr = inJson["rank"].toArray();
    int num = nameArr.size();
    qDebug() << "rankList: " << num << " : " << inJson;
    QTableWidgetItem *tmp = nullptr;
    for(int i = 0; i < num; ++i)
    {
        //排名
        tmp = new QTableWidgetItem(QString::number(i + 1));
        tmp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->rank_tableWidget->setItem(i, 0, tmp);
        //账号
        tmp = new QTableWidgetItem(nameArr[i].toString());
        tmp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->rank_tableWidget->setItem(i, 1,tmp);
        //段位
        tmp = new QTableWidgetItem(getRankText(rankArr[i].toString().toInt()));
        tmp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->rank_tableWidget->setItem(i, 2,tmp);
    }
}

void Admin::rankListInit()
{
    //设置列数/行数
    ui->rank_tableWidget->setColumnCount(3);
    ui->rank_tableWidget->setRowCount(20);
    ui->rank_tableWidget->verticalHeader()->setVisible(false);

    ui->rank_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    ui->rank_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->rank_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
    //设置排位榜的表头
    QStringList header;
    header << "排名" << "账号" << "段位";
    ui->rank_tableWidget->setHorizontalHeaderLabels(header);
    //设置表格数据区内的所有单元格都不允许编辑
    ui->rank_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->rank_tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏滚动条
    //ui->rank_tableWidget->verticalScrollBar()->setFixedSize(0,0);
}

void Admin::on_tabWidget_currentChanged(int index)
{
    if(1 == index)  //排位榜
    {
        QJsonObject json;
        json["cmd"] = RANKLIST;
        m_com->writeData(json);
    }  
}

//rank段位对照表
QString Admin::getRankText(int i)
{
    int rank,num;
    if(i < 9)
    {
        rank = i / 3;
        num = i % 3;
        return QString("青铜%1 %2颗星").arg(3-rank).arg(num+1);
    }
    else if(i < 18)
    {
        rank = (i - 9) / 3;
        num = (i - 9) % 3;
        return QString("白银%1 %2颗星").arg(3-rank).arg(num+1);
    }
    else if(i < 34)
    {
        rank = (i - 18) / 4;
        num = (i - 18) % 4;
        return QString("黄金%1 %2颗星").arg(4-rank).arg(num+1);
    }
    else if(i < 50)
    {
        rank = (i - 34) / 4;
        num = (i - 34) % 4;
        return QString("铂金%1 %2颗星").arg(4-rank).arg(num+1);
    }
    else if(i < 75)
    {
        rank = (i - 50) / 5;
        num = (i - 50) % 5;
        return QString("钻石%1 %2颗星").arg(5-rank).arg(num+1);
    }
    else if(i < 100)
    {
        rank = (i - 75) / 5;
        num = (i - 75) % 5;
        return QString("星曜%1 %2颗星").arg(5-rank).arg(num+1);
    }
    else if(i >= 100)
    {
        return QString("王者 %2颗星").arg(i - 100);
    }
    return QString("菜鸡");
}

//封面十动图GIF
void Admin::on_faceAdvert_Button_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("打开文件"),m_filepath, "*.gif");
    if(path.isEmpty())
    {
        return;
    }
    m_img->setReadFile(path);
    //设置页面
    ui->advertNameEdit->setText(m_img->m_fileInfo->fileName());

    QMovie * movie = new QMovie(path);
    ui->advertBrowserlabel->setMovie(movie);
    ui->advertBrowserlabel->setScaledContents(true);
    movie->start();
}
//主页是jpg、jpeg
void Admin::on_mainAdvert_Button_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("打开文件"), m_filepath, "*.jpg *.jpeg");
    if(path.isEmpty())
    {
        return;
    }
    m_img->setReadFile(path);

    ui->advertNameEdit->setText(m_img->m_fileInfo->fileName());
    QPixmap pix(path);
    pix.scaled(ui->advertBrowserlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->advertBrowserlabel->setPixmap(pix);
    ui->advertBrowserlabel->setAlignment(Qt::AlignCenter);
    ui->advertBrowserlabel->show();
}
//确认设置
void Admin::on_setButton_clicked()
{
    if(m_img->isEmpty())
    {
        QMessageBox::critical(nullptr, "设置广告", "没有可设置广告, 设置失败", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    auto ret = QMessageBox::information(this, "设置广告",QString("确定设置").append(ui->advertNameEdit->text()),
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    //确认发送
    if(ret == QMessageBox::Yes)
    {
        m_img->sendHead();
    }
}
//通知用户下载广告
void Admin::advert()
{
    QJsonObject json;
    json["cmd"] = ADVERT;
    json["fileName"] = m_img->m_fileInfo->fileName();
    json["fileSize"] = m_img->m_fileInfo->size();
    m_com->writeData(json);
    //发完文件清空FileInfo
    m_img->resetFileInfo();
    qDebug() << json;
}
