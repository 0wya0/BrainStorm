/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *advert_tab;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *advertNameEdit;
    QLabel *advertBrowserlabel;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *mainAdvert_Button;
    QPushButton *faceAdvert_Button;
    QSpacerItem *verticalSpacer_4;
    QPushButton *setButton;
    QWidget *rank_tab;
    QVBoxLayout *verticalLayout;
    QLabel *label_rank;
    QHBoxLayout *horizontalLayout;
    QTableWidget *rank_tableWidget;
    QWidget *user_tab;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *user_treeWidget;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QStringLiteral("Admin"));
        Admin->resize(450, 600);
        Admin->setMinimumSize(QSize(450, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Admin->setWindowIcon(icon);
        gridLayout = new QGridLayout(Admin);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Admin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(450, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabBarAutoHide(false);
        advert_tab = new QWidget();
        advert_tab->setObjectName(QStringLiteral("advert_tab"));
        advert_tab->setFont(font);
        verticalLayout_3 = new QVBoxLayout(advert_tab);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(25, 30, 25, 0);
        advertNameEdit = new QLineEdit(advert_tab);
        advertNameEdit->setObjectName(QStringLiteral("advertNameEdit"));
        advertNameEdit->setMinimumSize(QSize(0, 45));
        advertNameEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(advertNameEdit);

        advertBrowserlabel = new QLabel(advert_tab);
        advertBrowserlabel->setObjectName(QStringLiteral("advertBrowserlabel"));
        advertBrowserlabel->setMinimumSize(QSize(400, 300));
        advertBrowserlabel->setMaximumSize(QSize(400, 300));

        verticalLayout_3->addWidget(advertBrowserlabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        mainAdvert_Button = new QPushButton(advert_tab);
        mainAdvert_Button->setObjectName(QStringLiteral("mainAdvert_Button"));
        mainAdvert_Button->setMinimumSize(QSize(0, 60));
        mainAdvert_Button->setAutoDefault(false);
        mainAdvert_Button->setFlat(false);

        verticalLayout_2->addWidget(mainAdvert_Button);

        faceAdvert_Button = new QPushButton(advert_tab);
        faceAdvert_Button->setObjectName(QStringLiteral("faceAdvert_Button"));
        faceAdvert_Button->setMinimumSize(QSize(0, 60));
        faceAdvert_Button->setLayoutDirection(Qt::LeftToRight);
        faceAdvert_Button->setAutoDefault(false);
        faceAdvert_Button->setFlat(false);

        verticalLayout_2->addWidget(faceAdvert_Button);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_2->addLayout(verticalLayout_2);

        setButton = new QPushButton(advert_tab);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setMinimumSize(QSize(120, 120));
        setButton->setMaximumSize(QSize(120, 120));

        horizontalLayout_2->addWidget(setButton);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(advert_tab, QString());
        rank_tab = new QWidget();
        rank_tab->setObjectName(QStringLiteral("rank_tab"));
        verticalLayout = new QVBoxLayout(rank_tab);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_rank = new QLabel(rank_tab);
        label_rank->setObjectName(QStringLiteral("label_rank"));
        label_rank->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_rank);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rank_tableWidget = new QTableWidget(rank_tab);
        rank_tableWidget->setObjectName(QStringLiteral("rank_tableWidget"));
        rank_tableWidget->setStyleSheet(QString::fromUtf8("/*\350\241\250\346\240\274\347\232\204\344\270\200\347\247\215\347\276\216\345\214\226\346\226\271\345\274\217*/\n"
"QHeaderView\n"
"{\n"
"    background:transparent;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    font-size:14px;\n"
"    font-family:\"Microsoft YaHei\";\n"
"    color:#FFFFFF;\n"
"    background:#60669B;\n"
"    border:none;\n"
"    text-align:left;\n"
"    min-height:49px;\n"
"    max-height:49px;\n"
"    margin-left:0px;\n"
"    padding-left:0px;\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"    background:#FFFFFF;\n"
"    border:none;\n"
"\n"
"    font-size:20px;\n"
"    font-family:\"\346\245\267\344\275\223\";\n"
"    color:#666666;\n"
"}\n"
"QTableWidget::item\n"
"{\n"
"    border-bottom:1px solid #EEF1F7 ;\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"    color:red;\n"
"    background:#EFF4FF;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"    background: rgba(255,255,255,20%);\n"
"    border: 0px solid grey;\n"
"    border-radius:3px;\n"
"    width: 8px;\n"
"}\n"
"\n"
"QSc"
                        "rollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"    background:rgba(255,255,255,10%);\n"
"}\n"
"\n"
"\n"
"QScollBar::add-line:vertical, QScrollBar::sub-line:vertical\n"
"{\n"
"    background:transparent;\n"
"}\n"
""));
        rank_tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        rank_tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        rank_tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        rank_tableWidget->setAutoScroll(true);
        rank_tableWidget->setAutoScrollMargin(0);

        horizontalLayout->addWidget(rank_tableWidget);

        horizontalLayout->setStretch(0, 12);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);
        tabWidget->addTab(rank_tab, QString());
        user_tab = new QWidget();
        user_tab->setObjectName(QStringLiteral("user_tab"));
        verticalLayout_4 = new QVBoxLayout(user_tab);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        user_treeWidget = new QTreeWidget(user_tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("\346\234\252\345\206\231"));
        user_treeWidget->setHeaderItem(__qtreewidgetitem);
        user_treeWidget->setObjectName(QStringLiteral("user_treeWidget"));

        verticalLayout_4->addWidget(user_treeWidget);

        tabWidget->addTab(user_tab, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(106, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(Admin);

        tabWidget->setCurrentIndex(0);
        mainAdvert_Button->setDefault(false);
        faceAdvert_Button->setDefault(false);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "BrainStorm \347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        advertNameEdit->setText(QString());
        advertBrowserlabel->setText(QApplication::translate("Admin", "<html><head/><body><p align=\"center\">\345\233\276\347\211\207\346\265\217\350\247\210</p></body></html>", Q_NULLPTR));
        mainAdvert_Button->setText(QApplication::translate("Admin", "\344\270\273\351\241\265\345\271\277\345\221\212", Q_NULLPTR));
        faceAdvert_Button->setText(QApplication::translate("Admin", "\345\260\201\351\235\242\345\271\277\345\221\212", Q_NULLPTR));
        setButton->setText(QApplication::translate("Admin", "\350\256\276\347\275\256", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(advert_tab), QApplication::translate("Admin", "\345\271\277\345\221\212\347\256\241\347\220\206", Q_NULLPTR));
        label_rank->setText(QApplication::translate("Admin", "BrainStrom Top 20", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(rank_tab), QApplication::translate("Admin", "\346\216\222\344\275\215\346\246\234", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(user_tab), QApplication::translate("Admin", "\346\211\200\346\234\211\347\224\250\346\210\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
