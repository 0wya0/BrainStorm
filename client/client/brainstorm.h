#ifndef BRAINSTORM_H
#define BRAINSTORM_H

#include <QDialog>
#include "communicate.h"
#include "myftp.h"
#include <QJsonObject>
#include <QJsonArray>
#include "comm.h"
#include <QTimer>

namespace Ui {
class BrainStorm;
}

class BrainStorm : public QDialog
{
    Q_OBJECT

public:
    explicit BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent = 0);
    ~BrainStorm();
private:
    //个人训练从服务器获取题目
    void singleGetQuestion();
    //个人训练设置问题
    void singleSetQuestion();
    //个人训练答题--选择一个答案
    void singleAnswerQuestion(int select);

    //设置对手分数
    void setEnemySocre();
    //设置自己的分数
    void setSelfSocre();
    //设置排位赛题目
    void rankSetQuestion();
    //设置排位赛结果
    void rankSetResult(QJsonObject &json);
    //排位赛答题--选择一个答案
    void rankAnswerQuestion(int select);

signals:


private slots:
    //个人训练获取题目
    void singleGetQuestionSlot(QJsonObject json);
    //排位赛
    void rankSlot(QJsonObject json);
    //设置广告
    void setAdvert(QString path);
    //连接文件服务器，发送表头下载文件
    void advertSlot(QJsonObject json);

    void singleTimerOutSlot();

    void rankTimerOutSlot();

    void on_singleButton_clicked();

    void on_single_returnButton_clicked();

    void on_single_startButton_clicked();

    void on_singleScore_returnButton_clicked();

    void on_AsingleButton_clicked();

    void on_BsingleButton_clicked();

    void on_CsingleButton_clicked();

    void on_DsingleButton_clicked();

    void on_rankButton_clicked();

    void on_ArankButton_clicked();

    void on_BrankButton_clicked();

    void on_CrankButton_clicked();

    void on_DrankButton_clicked();

    void on_rankAgainButton_clicked();

    void on_rank_returnButton_clicked();

    void on_cancelButton_clicked();

    void on_xButton_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::BrainStorm *ui;

    //通信类指针，负责和服务器通信
    Communicate *m_com;
    //获取广告
    MyFTP *m_img;

    //个人训练题目
    QJsonObject m_signleQuestion;
    int m_curSignlenQuestion; //当前个人训练题目下标
    //个人训练计时器
    QTimer m_singleTimer;
    int m_singleSec;    //个人训练答题时间
    //个人训练得分
    int m_singleScore;

    //自己的名称
    QString m_selfName;
    //自己的段位
    QString m_selfRank;

    //排位赛的题目
    QJsonObject m_rankQuestion;
    //当前排位赛题目下标
    int m_curRankQuestion;
    //对手排位赛题目下标
    int m_enemyRankQuestion;
    //排位赛计时器
    QTimer m_rankTimer;
    //对手名称
    QString m_enemyName;
    //对手段位
    QString m_enemyRank;
    //对手得分
    int m_enemyScore;
    //排位赛的答题时间
    int m_rankSec;
    //自己的得分
    int m_selfScore;
};

#endif // BRAINSTORM_H
