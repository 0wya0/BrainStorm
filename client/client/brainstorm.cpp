#include "brainstorm.h"
#include "ui_brainstorm.h"
#include <QDebug>

BrainStorm::BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrainStorm)
{
    ui->setupUi(this);

    m_com = com;
    m_img = new MyFTP;
    m_selfName = json["username"].toString();
    m_selfRank = json["rank"].toString();

    setAdvert("faceAdvert.jpg");
    //个人训练题目
    connect(m_com, &Communicate::singleGetQuestionSignal, this, &BrainStorm::singleGetQuestionSlot);
    //排位匹配
    connect(m_com, &Communicate::rankSignal, this, &BrainStorm::rankSlot);
    //个人训练定时器
    connect(&m_singleTimer, &QTimer::timeout, this, &BrainStorm::singleTimerOutSlot);
    //排位匹配定时器
    connect(&m_rankTimer, &QTimer::timeout, this, &BrainStorm::rankTimerOutSlot);
    //获取广告
    connect(m_com, &Communicate::advertSignal, this, &BrainStorm::advertSlot);
    //广告更新
    connect(m_img, &MyFTP::updateAdvert, [this](QString filename){
        //断开连接
        m_img->disconnectServer();
        //设置广告
        setAdvert(filename);
    });
}

BrainStorm::~BrainStorm()
{
    delete ui;
}

//设置广告
void BrainStorm::setAdvert(QString filename)
{
    QPixmap pix(QString("../client/Res/advert/").append("faceAdvert.jpg"));
    pix.scaled(ui->advertlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->advertlabel->setPixmap(pix);
    ui->advertlabel->setAlignment(Qt::AlignCenter);
    ui->advertlabel->show();
    ui->xButton->show();
}
//连接文件服务器，发送表头下载文件
void BrainStorm::advertSlot(QJsonObject json)
{
    QString fileName = json["fileName"].toString();
    qint64 fileSize = json["fileSize"].toInt();

    m_img->connectServer();
    m_img->openFile(fileName);
    m_img->sendHead(fileSize);

    qDebug() << json;
}
//关闭主页广告
void BrainStorm::on_xButton_clicked()
{
    ui->advertlabel->hide();
    ui->xButton->hide();
}

void BrainStorm::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 == 0)
    {
        ui->advertlabel->show();
        ui->xButton->show();
    }
}
/*-------------------------------------个人训练功能开始-----------------------------------*/
//个人训练计时器槽函数
void BrainStorm::singleTimerOutSlot()
{
    --m_singleSec;
    if(0 >= m_singleSec)
    {
        m_singleTimer.stop();   //关闭计时器

        ui->stackedWidget->setCurrentWidget(ui->singleScore_page);
        ui->singleResultlabel->setText("回答错误");
        QString str = QString("本次得分: %1").arg(m_singleScore);
        ui->singleScorelabel->setText(str);
    }
    ui->signlelcdNumber->display(m_singleSec);
}

//个人训练从服务器获取题目
void BrainStorm::singleGetQuestion()
{
    QJsonObject json;
    json["cmd"] = SIGNLE_GETQUESTION;

    m_com->writeData(json);
}

//个人训练设置问题
void BrainStorm::singleSetQuestion()
{
    //最后一个题目
    if(m_curSignlenQuestion == QUESTION_NUM)
    {
        m_singleTimer.stop();   //关闭计时器
        //显示成绩
        ui->stackedWidget->setCurrentWidget(ui->singleScore_page);
        ui->singleResultlabel->setText("恭喜全部答对");
        QString str = QString("本次得分: %1").arg(m_singleScore);
        ui->singleScorelabel->setText(str);
        return;
    }
    //显示题目
    ui->singleQuestionlabel->setText(m_signleQuestion["question"].toArray().at(m_curSignlenQuestion).toString());
    //显示选项
    ui->AsingleButton->setText(m_signleQuestion["selectA"].toArray().at(m_curSignlenQuestion).toString());
    ui->BsingleButton->setText(m_signleQuestion["selectB"].toArray().at(m_curSignlenQuestion).toString());
    ui->CsingleButton->setText(m_signleQuestion["selectC"].toArray().at(m_curSignlenQuestion).toString());
    ui->DsingleButton->setText(m_signleQuestion["selectD"].toArray().at(m_curSignlenQuestion).toString());
}

//个人训练答题--选择一个答案
void BrainStorm::singleAnswerQuestion(int select)
{
    //回答正确
    if(select == m_signleQuestion["answer"].toArray().at(m_curSignlenQuestion).toString().toInt())
    {
        m_singleScore += m_singleSec * 20;
        //设置下一题
        ++m_curSignlenQuestion;
        //重置定时器
        m_singleTimer.stop();
        m_singleSec = 10;
        ui->signlelcdNumber->display(m_singleSec);
        m_singleTimer.start(1000);
        //设置题目
        singleSetQuestion();
    }
    else
    {
        m_singleTimer.stop();   //关闭计时器

        ui->stackedWidget->setCurrentWidget(ui->singleScore_page);
        ui->singleResultlabel->setText("回答错误");
        QString str = QString("本次得分: %1").arg(m_singleScore);
        ui->singleScorelabel->setText(str);
    }
}

//个人训练获取题目槽函数
void BrainStorm::singleGetQuestionSlot(QJsonObject json)
{
    m_signleQuestion = json;
    m_curSignlenQuestion = 0;
    m_singleSec = 10;
    m_singleScore = 0;
    ui->signlelcdNumber->display(m_singleSec);
    singleSetQuestion();    //设置问题
    m_singleTimer.start(1000);  //开启定时器
    ui->stackedWidget->setCurrentWidget(ui->singleStart_page);

}

//进入个人训练页面
void BrainStorm::on_singleButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->single_page);
}

//个人训练页面返回到主页面
void BrainStorm::on_single_returnButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

//个人训练开始答题
void BrainStorm::on_single_startButton_clicked()
{
    singleGetQuestion();
}

//个人训练结果页面返回到答题页面
void BrainStorm::on_singleScore_returnButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->single_page);
}

//个人训练答题选择
void BrainStorm::on_AsingleButton_clicked()
{
    singleAnswerQuestion(1);
}
void BrainStorm::on_BsingleButton_clicked()
{
    singleAnswerQuestion(2);
}
void BrainStorm::on_CsingleButton_clicked()
{
    singleAnswerQuestion(3);
}
void BrainStorm::on_DsingleButton_clicked()
{
    singleAnswerQuestion(4);
}

/*-------------------------------------个人训练功能结束-----------------------------------*/


/*--------------------------------------排位赛功能开始-----------------------------------*/

void BrainStorm:: rankTimerOutSlot()
{
    --m_rankSec;
    if(0 == m_rankSec)
    {
        //选择按钮可用代表没有答题
        if(ui->ArankButton->isEnabled())
        {
            ++m_curRankQuestion;
        }
        rankSetQuestion();
        m_rankSec = 10;
    }
    ui->ranklcdNumber->display(m_rankSec);
}

//排位赛
void BrainStorm::rankSlot(QJsonObject json)
{
    int cmd = json["cmd"].toInt();
    if(cmd == RANK) //开始对决
    {
        m_rankQuestion = json["question"].toObject();
        m_enemyName    = json["enemyname"].toString();
        m_enemyRank    = json["enemyrank"].toString();
        m_enemyScore   = json["enemyscore"].toInt();

        m_rankSec = 10;
        m_selfScore = 0;
        ui->ranklcdNumber->display(m_rankSec);
        m_curRankQuestion = 0;
        m_enemyRankQuestion = 0;

        setEnemySocre();
        setSelfSocre();
        rankSetQuestion();

        m_rankTimer.start(1000);
        ui->stackedWidget->setCurrentWidget(ui->rankStart_page);
    }
    else if(ANSWER == cmd)  //答题过程
    {
        m_enemyScore        = json["enemyscore"].toInt();
        m_enemyRankQuestion = json["enemyQuestionId"].toInt();
        setEnemySocre();

        if(m_curRankQuestion == m_enemyRankQuestion)
        {
            m_rankTimer.stop();
            m_rankSec = 10;
            ui->ranklcdNumber->display(m_rankSec);
            m_rankTimer.start(1000);
            rankSetQuestion();
        }
    }
    else if(RANKOVER == cmd)   //对决结束
    {
        rankSetResult(json);
    }
    else if(ENEMYERROR == cmd)  //对手在答题时掉线
    {
        //qDebug() << "对手掉线\n" ;
        m_rankTimer.stop();

        QJsonObject json;
        json["cmd"]        = RANKOVER;
        json["score"]      = m_selfScore;
        json["enemyscore"] = 0;
        json["enemyname"]  = m_enemyName;
        m_com->writeData(json);
    }
}

//设置对手分数
void BrainStorm::setEnemySocre()
{
    QString str = QString("%1(%2): %3").arg(m_enemyName,-5).arg(m_enemyRank).arg(m_enemyScore);
    ui->ememylabel->setText(str);
}

//设置自己分数
void BrainStorm::setSelfSocre()
{
    QString str = QString("%1(%2): %3").arg(m_selfName,-5).arg(m_selfRank).arg(m_selfScore);
    ui->selflabel->setText(str);
}

//设置排位赛题目
void BrainStorm::rankSetQuestion()
{
    //最后一题 -- 对决结束，将结果发给服务器
    if(m_curRankQuestion >= QUESTION_NUM)
    {
        m_rankTimer.stop();

        QJsonObject json;
        json["cmd"]        = RANKOVER;
        json["score"]      = m_selfScore;
        json["enemyscore"] = m_enemyScore;
        json["enemyname"]  = m_enemyName;
        m_com->writeData(json);
    }
    //显示题目
    ui->rankQuestionlabel->setText(m_rankQuestion["question"].toArray().at(m_curRankQuestion).toString());
    //显示选项
    ui->ArankButton->setText(m_rankQuestion["selectA"].toArray().at(m_curRankQuestion).toString());
    ui->BrankButton->setText(m_rankQuestion["selectB"].toArray().at(m_curRankQuestion).toString());
    ui->CrankButton->setText(m_rankQuestion["selectC"].toArray().at(m_curRankQuestion).toString());
    ui->DrankButton->setText(m_rankQuestion["selectD"].toArray().at(m_curRankQuestion).toString());

    //恢复选项按键
    ui->ArankButton->setEnabled(true);
    ui->BrankButton->setEnabled(true);
    ui->CrankButton->setEnabled(true);
    ui->DrankButton->setEnabled(true);
    ui->ArankButton->setStyleSheet("");
    ui->BrankButton->setStyleSheet("");
    ui->CrankButton->setStyleSheet("");
    ui->DrankButton->setStyleSheet("");
}

//排位赛答题--选择一个答案
void BrainStorm::rankAnswerQuestion(int select)
{
    if(select == m_rankQuestion["answer"].toArray().at(m_curRankQuestion).toString().toInt())
    {
        m_selfScore += m_rankSec * 20;
    }

    setSelfSocre();
    m_curRankQuestion++;
    //判断是否和对手答题同步,进入下一题
    if(m_curRankQuestion == m_enemyRankQuestion)
    {
        m_rankSec = 10;
        m_rankTimer.stop();
        ui->ranklcdNumber->display(m_rankSec);
        m_rankTimer.start(1000);
        rankSetQuestion();
    }
    {
        QJsonObject json;
        json["cmd"]        = ANSWER;
        json["enemyname"]  = m_enemyName;
        json["score"]      = m_selfScore;
        json["questionId"] = m_curRankQuestion;
        m_com->writeData(json);
    }
}

//设置排位赛结果
void BrainStorm::rankSetResult(QJsonObject &json)
{
    QString newRank = json["newRank"].toString();
    if(m_selfScore < m_enemyScore)
    {
        ui->rankResultlabel->setText("失败");
    }
    else if(m_selfScore > m_enemyScore)
    {
        ui->rankResultlabel->setText("胜利");
    }
    else
    {
        ui->rankResultlabel->setText("平局");
    }

    QString str = QString("%1 >>> %2").arg(m_selfRank).arg(newRank);
    ui->rankUpdatelabel->setText(str);
    m_selfRank = newRank;

    ui->stackedWidget->setCurrentWidget(ui->rankResult_page);
}

void BrainStorm::on_ArankButton_clicked()
{
    ui->ArankButton->setStyleSheet("background-color: rgb(170, 170, 255)");
    ui->ArankButton->setEnabled(false);
    ui->BrankButton->setEnabled(false);
    ui->CrankButton->setEnabled(false);
    ui->DrankButton->setEnabled(false);
    rankAnswerQuestion(1);
}

void BrainStorm::on_BrankButton_clicked()
{
    ui->BrankButton->setStyleSheet("background-color: rgb(170, 170, 255)");
    ui->ArankButton->setEnabled(false);
    ui->BrankButton->setEnabled(false);
    ui->CrankButton->setEnabled(false);
    ui->DrankButton->setEnabled(false);
    rankAnswerQuestion(2);
}

void BrainStorm::on_CrankButton_clicked()
{
    ui->CrankButton->setStyleSheet("background-color: rgb(170, 170, 255)");
    ui->ArankButton->setEnabled(false);
    ui->BrankButton->setEnabled(false);
    ui->CrankButton->setEnabled(false);
    ui->DrankButton->setEnabled(false);
    rankAnswerQuestion(3);
}

void BrainStorm::on_DrankButton_clicked()
{
    ui->DrankButton->setStyleSheet("background-color: rgb(170, 170, 255)");
    ui->ArankButton->setEnabled(false);
    ui->BrankButton->setEnabled(false);
    ui->CrankButton->setEnabled(false);
    ui->DrankButton->setEnabled(false);
    rankAnswerQuestion(4);
}

void BrainStorm::on_rankButton_clicked()
{
    QJsonObject json;
    json["cmd"] = RANK;
    m_com->writeData(json); //发送排位请求

    //跳转等待页面(rank_page)
    ui->stackedWidget->setCurrentWidget(ui->rank_page);
}

void BrainStorm::on_rankAgainButton_clicked()
{
    on_rankButton_clicked();
}

void BrainStorm::on_rank_returnButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

void BrainStorm::on_cancelButton_clicked()
{
    QJsonObject json;
    json["cmd"] = CANCEL;
    m_com->writeData(json); //发送排位请求

    //跳转主页面(main_page)
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

/*--------------------------------------排位赛功能结束-----------------------------------*/


