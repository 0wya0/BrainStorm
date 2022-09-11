/********************************************************************************
** Form generated from reading UI file 'brainstorm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAINSTORM_H
#define UI_BRAINSTORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrainStorm
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *rankButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *singleButton;
    QWidget *widget_advert;
    QLabel *advertlabel;
    QPushButton *xButton;
    QWidget *single_page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_single;
    QPushButton *single_startButton;
    QPushButton *single_returnButton;
    QWidget *singleStart_page;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_singleStart;
    QLCDNumber *signlelcdNumber;
    QSpacerItem *horizontalSpacer_4;
    QLabel *singleQuestionlabel;
    QVBoxLayout *verticalLayout_3;
    QPushButton *AsingleButton;
    QPushButton *BsingleButton;
    QPushButton *CsingleButton;
    QPushButton *DsingleButton;
    QWidget *singleScore_page;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QLabel *singleResultlabel;
    QLabel *singleScorelabel;
    QSpacerItem *verticalSpacer_5;
    QPushButton *singleScore_returnButton;
    QWidget *rank_page;
    QLabel *label_rank;
    QPushButton *cancelButton;
    QWidget *rankStart_page;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *selflabel;
    QLabel *ememylabel;
    QLCDNumber *ranklcdNumber;
    QSpacerItem *horizontalSpacer_5;
    QLabel *rankQuestionlabel;
    QVBoxLayout *verticalLayout_6;
    QPushButton *ArankButton;
    QPushButton *BrankButton;
    QPushButton *CrankButton;
    QPushButton *DrankButton;
    QWidget *rankResult_page;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_7;
    QLabel *rankResultlabel;
    QLabel *rankUpdatelabel;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_9;
    QPushButton *rank_returnButton;
    QPushButton *rankAgainButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *BrainStorm)
    {
        if (BrainStorm->objectName().isEmpty())
            BrainStorm->setObjectName(QStringLiteral("BrainStorm"));
        BrainStorm->resize(453, 750);
        BrainStorm->setMinimumSize(QSize(453, 750));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        BrainStorm->setWindowIcon(icon);
        BrainStorm->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";"));
        gridLayout = new QGridLayout(BrainStorm);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(BrainStorm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(450, 750));
        stackedWidget->setMaximumSize(QSize(450, 750));
        main_page = new QWidget();
        main_page->setObjectName(QStringLiteral("main_page"));
        main_page->setMinimumSize(QSize(450, 750));
        main_page->setMaximumSize(QSize(450, 750));
        layoutWidget = new QWidget(main_page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 570, 161, 122));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rankButton = new QPushButton(layoutWidget);
        rankButton->setObjectName(QStringLiteral("rankButton"));
        rankButton->setMinimumSize(QSize(150, 40));

        verticalLayout->addWidget(rankButton);

        verticalSpacer_3 = new QSpacerItem(30, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        singleButton = new QPushButton(layoutWidget);
        singleButton->setObjectName(QStringLiteral("singleButton"));
        singleButton->setMinimumSize(QSize(150, 40));

        verticalLayout->addWidget(singleButton);

        widget_advert = new QWidget(main_page);
        widget_advert->setObjectName(QStringLiteral("widget_advert"));
        widget_advert->setGeometry(QRect(0, 0, 450, 300));
        advertlabel = new QLabel(widget_advert);
        advertlabel->setObjectName(QStringLiteral("advertlabel"));
        advertlabel->setGeometry(QRect(0, 0, 450, 300));
        advertlabel->setScaledContents(true);
        advertlabel->setAlignment(Qt::AlignCenter);
        xButton = new QPushButton(widget_advert);
        xButton->setObjectName(QStringLiteral("xButton"));
        xButton->setGeometry(QRect(400, 14, 36, 36));
        xButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	font: 16pt \"Arial\";\n"
"	border-radius: 18px;\n"
"	background-color: rgba(200, 200, 200, 200);\n"
"	color: rgba(180, 180, 180, 180);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgba(21, 181, 255, 200);\n"
"}"));
        stackedWidget->addWidget(main_page);
        single_page = new QWidget();
        single_page->setObjectName(QStringLiteral("single_page"));
        single_page->setMinimumSize(QSize(450, 750));
        single_page->setMaximumSize(QSize(450, 750));
        verticalLayout_2 = new QVBoxLayout(single_page);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 0, 5, 20);
        label_single = new QLabel(single_page);
        label_single->setObjectName(QStringLiteral("label_single"));

        verticalLayout_2->addWidget(label_single);

        single_startButton = new QPushButton(single_page);
        single_startButton->setObjectName(QStringLiteral("single_startButton"));
        single_startButton->setMinimumSize(QSize(0, 45));

        verticalLayout_2->addWidget(single_startButton);

        single_returnButton = new QPushButton(single_page);
        single_returnButton->setObjectName(QStringLiteral("single_returnButton"));
        single_returnButton->setMinimumSize(QSize(0, 45));

        verticalLayout_2->addWidget(single_returnButton);

        stackedWidget->addWidget(single_page);
        singleStart_page = new QWidget();
        singleStart_page->setObjectName(QStringLiteral("singleStart_page"));
        verticalLayout_4 = new QVBoxLayout(singleStart_page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 16, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_singleStart = new QLabel(singleStart_page);
        label_singleStart->setObjectName(QStringLiteral("label_singleStart"));

        horizontalLayout->addWidget(label_singleStart);

        signlelcdNumber = new QLCDNumber(singleStart_page);
        signlelcdNumber->setObjectName(QStringLiteral("signlelcdNumber"));
        signlelcdNumber->setMinimumSize(QSize(60, 60));
        signlelcdNumber->setMaximumSize(QSize(100, 100));
        signlelcdNumber->setDigitCount(3);

        horizontalLayout->addWidget(signlelcdNumber);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_4->addLayout(horizontalLayout);

        singleQuestionlabel = new QLabel(singleStart_page);
        singleQuestionlabel->setObjectName(QStringLiteral("singleQuestionlabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        singleQuestionlabel->setFont(font);
        singleQuestionlabel->setAlignment(Qt::AlignCenter);
        singleQuestionlabel->setWordWrap(true);
        singleQuestionlabel->setMargin(0);

        verticalLayout_4->addWidget(singleQuestionlabel);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, -1, 10, 20);
        AsingleButton = new QPushButton(singleStart_page);
        AsingleButton->setObjectName(QStringLiteral("AsingleButton"));
        AsingleButton->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(AsingleButton);

        BsingleButton = new QPushButton(singleStart_page);
        BsingleButton->setObjectName(QStringLiteral("BsingleButton"));
        BsingleButton->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(BsingleButton);

        CsingleButton = new QPushButton(singleStart_page);
        CsingleButton->setObjectName(QStringLiteral("CsingleButton"));
        CsingleButton->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(CsingleButton);

        DsingleButton = new QPushButton(singleStart_page);
        DsingleButton->setObjectName(QStringLiteral("DsingleButton"));
        DsingleButton->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(DsingleButton);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(1, 7);
        verticalLayout_4->setStretch(2, 5);
        stackedWidget->addWidget(singleStart_page);
        singleScore_page = new QWidget();
        singleScore_page->setObjectName(QStringLiteral("singleScore_page"));
        verticalLayout_5 = new QVBoxLayout(singleScore_page);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, 0, 10, 16);
        verticalSpacer_4 = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        singleResultlabel = new QLabel(singleScore_page);
        singleResultlabel->setObjectName(QStringLiteral("singleResultlabel"));
        singleResultlabel->setMinimumSize(QSize(0, 150));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        singleResultlabel->setFont(font1);
        singleResultlabel->setStyleSheet(QString::fromUtf8("font: 22pt \"\346\245\267\344\275\223\";"));
        singleResultlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(singleResultlabel);

        singleScorelabel = new QLabel(singleScore_page);
        singleScorelabel->setObjectName(QStringLiteral("singleScorelabel"));
        singleScorelabel->setMinimumSize(QSize(0, 150));
        singleScorelabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(singleScorelabel);

        verticalSpacer_5 = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        singleScore_returnButton = new QPushButton(singleScore_page);
        singleScore_returnButton->setObjectName(QStringLiteral("singleScore_returnButton"));
        singleScore_returnButton->setMinimumSize(QSize(0, 40));
        singleScore_returnButton->setMaximumSize(QSize(16777215, 40));

        verticalLayout_5->addWidget(singleScore_returnButton);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(3, 2);
        stackedWidget->addWidget(singleScore_page);
        rank_page = new QWidget();
        rank_page->setObjectName(QStringLiteral("rank_page"));
        label_rank = new QLabel(rank_page);
        label_rank->setObjectName(QStringLiteral("label_rank"));
        label_rank->setGeometry(QRect(0, 0, 450, 450));
        cancelButton = new QPushButton(rank_page);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(145, 600, 160, 60));
        stackedWidget->addWidget(rank_page);
        rankStart_page = new QWidget();
        rankStart_page->setObjectName(QStringLiteral("rankStart_page"));
        verticalLayout_8 = new QVBoxLayout(rankStart_page);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 28, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, -1);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        selflabel = new QLabel(rankStart_page);
        selflabel->setObjectName(QStringLiteral("selflabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        selflabel->setFont(font2);
        selflabel->setStyleSheet(QString::fromUtf8("font: 13pt \"\346\245\267\344\275\223\";"));

        verticalLayout_7->addWidget(selflabel);

        ememylabel = new QLabel(rankStart_page);
        ememylabel->setObjectName(QStringLiteral("ememylabel"));
        ememylabel->setFont(font2);
        ememylabel->setStyleSheet(QString::fromUtf8("font: 13pt \"\346\245\267\344\275\223\";"));

        verticalLayout_7->addWidget(ememylabel);


        horizontalLayout_2->addLayout(verticalLayout_7);

        ranklcdNumber = new QLCDNumber(rankStart_page);
        ranklcdNumber->setObjectName(QStringLiteral("ranklcdNumber"));
        ranklcdNumber->setDigitCount(3);

        horizontalLayout_2->addWidget(ranklcdNumber);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 6);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout_8->addLayout(horizontalLayout_2);

        rankQuestionlabel = new QLabel(rankStart_page);
        rankQuestionlabel->setObjectName(QStringLiteral("rankQuestionlabel"));
        rankQuestionlabel->setMinimumSize(QSize(0, 300));
        rankQuestionlabel->setFont(font);
        rankQuestionlabel->setAlignment(Qt::AlignCenter);
        rankQuestionlabel->setWordWrap(true);
        rankQuestionlabel->setMargin(0);

        verticalLayout_8->addWidget(rankQuestionlabel);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(10, -1, 10, 20);
        ArankButton = new QPushButton(rankStart_page);
        ArankButton->setObjectName(QStringLiteral("ArankButton"));
        ArankButton->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(ArankButton);

        BrankButton = new QPushButton(rankStart_page);
        BrankButton->setObjectName(QStringLiteral("BrankButton"));
        BrankButton->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(BrankButton);

        CrankButton = new QPushButton(rankStart_page);
        CrankButton->setObjectName(QStringLiteral("CrankButton"));
        CrankButton->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(CrankButton);

        DrankButton = new QPushButton(rankStart_page);
        DrankButton->setObjectName(QStringLiteral("DrankButton"));
        DrankButton->setMinimumSize(QSize(0, 40));

        verticalLayout_6->addWidget(DrankButton);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_8->setStretch(0, 2);
        verticalLayout_8->setStretch(1, 7);
        verticalLayout_8->setStretch(2, 5);
        stackedWidget->addWidget(rankStart_page);
        rankResult_page = new QWidget();
        rankResult_page->setObjectName(QStringLiteral("rankResult_page"));
        verticalLayout_11 = new QVBoxLayout(rankResult_page);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(10, 0, 10, 20);
        verticalSpacer_7 = new QSpacerItem(20, 127, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_7);

        rankResultlabel = new QLabel(rankResult_page);
        rankResultlabel->setObjectName(QStringLiteral("rankResultlabel"));
        rankResultlabel->setMinimumSize(QSize(0, 150));
        rankResultlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(rankResultlabel);

        rankUpdatelabel = new QLabel(rankResult_page);
        rankUpdatelabel->setObjectName(QStringLiteral("rankUpdatelabel"));
        rankUpdatelabel->setMinimumSize(QSize(0, 100));
        rankUpdatelabel->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(rankUpdatelabel);

        verticalSpacer_6 = new QSpacerItem(20, 258, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        rank_returnButton = new QPushButton(rankResult_page);
        rank_returnButton->setObjectName(QStringLiteral("rank_returnButton"));
        rank_returnButton->setMinimumSize(QSize(0, 40));

        verticalLayout_9->addWidget(rank_returnButton);

        rankAgainButton = new QPushButton(rankResult_page);
        rankAgainButton->setObjectName(QStringLiteral("rankAgainButton"));
        rankAgainButton->setMinimumSize(QSize(0, 40));

        verticalLayout_9->addWidget(rankAgainButton);


        verticalLayout_11->addLayout(verticalLayout_9);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(3, 2);
        stackedWidget->addWidget(rankResult_page);

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(424, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 724, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(BrainStorm);

        QMetaObject::connectSlotsByName(BrainStorm);
    } // setupUi

    void retranslateUi(QDialog *BrainStorm)
    {
        BrainStorm->setWindowTitle(QApplication::translate("BrainStorm", "BrainStorm", Q_NULLPTR));
        rankButton->setText(QApplication::translate("BrainStorm", "\346\216\222\344\275\215\350\265\233", Q_NULLPTR));
        singleButton->setText(QApplication::translate("BrainStorm", "\344\270\252\344\272\272\350\256\255\347\273\203", Q_NULLPTR));
        advertlabel->setText(QApplication::translate("BrainStorm", "\345\271\277\345\221\212", Q_NULLPTR));
        xButton->setText(QApplication::translate("BrainStorm", "X", Q_NULLPTR));
        label_single->setText(QApplication::translate("BrainStorm", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:600;\">\350\277\236\347\273\255\347\255\224\345\257\271\344\272\224\351\201\223\351\242\230</span></p><p align=\"center\"><span style=\" font-size:14pt;\">\347\255\224\345\257\271\347\273\247\347\273\255 \347\255\224\351\224\231\347\246\273\345\234\272</span></p></body></html>", Q_NULLPTR));
        single_startButton->setText(QApplication::translate("BrainStorm", "\345\274\200\345\247\213\347\255\224\351\242\230", Q_NULLPTR));
        single_returnButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        label_singleStart->setText(QApplication::translate("BrainStorm", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">\344\270\252\344\272\272\350\256\255\347\273\203</span></p></body></html>", Q_NULLPTR));
        singleQuestionlabel->setText(QApplication::translate("BrainStorm", "\344\270\252\344\272\272\350\256\255\347\273\203", Q_NULLPTR));
        AsingleButton->setText(QApplication::translate("BrainStorm", "A", Q_NULLPTR));
        BsingleButton->setText(QApplication::translate("BrainStorm", "B", Q_NULLPTR));
        CsingleButton->setText(QApplication::translate("BrainStorm", "C", Q_NULLPTR));
        DsingleButton->setText(QApplication::translate("BrainStorm", "D", Q_NULLPTR));
        singleResultlabel->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        singleScorelabel->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        singleScore_returnButton->setText(QApplication::translate("BrainStorm", "\350\277\224 \345\233\236", Q_NULLPTR));
        label_rank->setText(QApplication::translate("BrainStorm", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\346\255\243\345\234\250\345\214\271\351\205\215\345\257\271\346\211\213...</span></p></body></html>", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("BrainStorm", "\345\217\226\346\266\210\345\214\271\351\205\215", Q_NULLPTR));
        selflabel->setText(QApplication::translate("BrainStorm", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">  \346\210\221(\351\273\204\351\207\2211\351\242\227\346\230\237): 000\345\210\206</span></p></body></html>", Q_NULLPTR));
        ememylabel->setText(QApplication::translate("BrainStorm", "<html><head/><body><p align=\"center\">\345\257\271\346\211\213(\351\273\204\351\207\2211\351\242\227\346\230\237): 000\345\210\206</p></body></html>", Q_NULLPTR));
        rankQuestionlabel->setText(QApplication::translate("BrainStorm", "\346\216\222\344\275\215\350\265\233", Q_NULLPTR));
        ArankButton->setText(QApplication::translate("BrainStorm", "A", Q_NULLPTR));
        BrankButton->setText(QApplication::translate("BrainStorm", "B", Q_NULLPTR));
        CrankButton->setText(QApplication::translate("BrainStorm", "C", Q_NULLPTR));
        DrankButton->setText(QApplication::translate("BrainStorm", "D", Q_NULLPTR));
        rankResultlabel->setText(QApplication::translate("BrainStorm", "\350\203\234\345\210\251", Q_NULLPTR));
        rankUpdatelabel->setText(QApplication::translate("BrainStorm", "(\351\273\204\351\207\221\344\270\200 2\351\242\227\346\230\237)\345\215\207\344\270\272(\351\273\204\351\207\221\344\270\200 3\351\242\227\346\230\237)", Q_NULLPTR));
        rank_returnButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        rankAgainButton->setText(QApplication::translate("BrainStorm", "\345\206\215\346\235\245\344\270\200\345\261\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrainStorm: public Ui_BrainStorm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAINSTORM_H
