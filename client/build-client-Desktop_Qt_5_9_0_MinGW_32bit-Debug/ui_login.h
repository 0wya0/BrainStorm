/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_6;
    QStackedWidget *stackedWidget;
    QWidget *login_page;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLineEdit *idEdit;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *psdEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *advert_page;
    QLabel *advertlabel;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(600, 450);
        Login->setMinimumSize(QSize(600, 450));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pics/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        gridLayout_2 = new QGridLayout(Login);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_6 = new QSpacerItem(20, 129, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(Login);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        login_page = new QWidget();
        login_page->setObjectName(QStringLiteral("login_page"));
        verticalLayout_2 = new QVBoxLayout(login_page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(login_page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(600, 450));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(400, 100));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        idEdit = new QLineEdit(widget);
        idEdit->setObjectName(QStringLiteral("idEdit"));
        idEdit->setMinimumSize(QSize(300, 50));

        verticalLayout->addWidget(idEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        psdEdit = new QLineEdit(widget);
        psdEdit->setObjectName(QStringLiteral("psdEdit"));
        psdEdit->setMinimumSize(QSize(300, 50));
        psdEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout->addWidget(psdEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setMinimumSize(QSize(125, 45));

        horizontalLayout->addWidget(loginButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setMinimumSize(QSize(125, 45));

        horizontalLayout->addWidget(registerButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 1, 1);


        verticalLayout_2->addWidget(widget);

        stackedWidget->addWidget(login_page);
        advert_page = new QWidget();
        advert_page->setObjectName(QStringLiteral("advert_page"));
        advertlabel = new QLabel(advert_page);
        advertlabel->setObjectName(QStringLiteral("advertlabel"));
        advertlabel->setGeometry(QRect(0, 0, 600, 450));
        advertlabel->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(advert_page);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(514, 15, 66, 33));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(247, 247, 247, 200);\n"
"	border: 0px;\n"
"	border-radius: 10px;\n"
"	color: rgba(135, 135, 135, 200);\n"
"	\n"
"	font: 10pt \"\346\245\267\344\275\223\";\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(200, 200, 200, 168);\n"
"}"));
        stackedWidget->addWidget(advert_page);

        gridLayout_2->addWidget(stackedWidget, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 129, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 2, 1, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">\346\254\242\350\277\216\344\275\277\347\224\250 BrainStorm</span></p></body></html>", Q_NULLPTR));
        idEdit->setText(QApplication::translate("Login", "\350\267\257\351\243\236", Q_NULLPTR));
        idEdit->setPlaceholderText(QApplication::translate("Login", "\350\264\246 \345\217\267", Q_NULLPTR));
        psdEdit->setText(QApplication::translate("Login", "lf", Q_NULLPTR));
        psdEdit->setPlaceholderText(QApplication::translate("Login", "\345\257\206 \347\240\201", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", Q_NULLPTR));
        registerButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214", Q_NULLPTR));
        advertlabel->setText(QApplication::translate("Login", "\345\271\277\345\221\212", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Login", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
