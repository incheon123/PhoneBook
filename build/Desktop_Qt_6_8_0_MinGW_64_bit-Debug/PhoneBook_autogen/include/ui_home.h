/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QListWidget *index_sideMenu;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *index_lastLoginDateLabel;
    QLabel *index_phoneNumLabel;
    QTableWidget *index_table;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *index_deleteBtn;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *NameInput;
    QLineEdit *userIdInput;
    QPushButton *index_saveBtn;
    QLabel *index_welcomeLabel;
    QWidget *page_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *profile_phone_input;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *profile_count_input;
    QLineEdit *profile_createTime;
    QLabel *label_2;
    QPushButton *profile_modify_btn;
    QLabel *label_3;
    QLineEdit *profile_userPw_input;
    QLabel *label;
    QLineEdit *profile_userId_input;

    void setupUi(QWidget *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName("home");
        home->resize(907, 575);
        home->setAutoFillBackground(false);
        home->setStyleSheet(QString::fromUtf8("QWidget{background-color: rgb(0, 61,102)};"));
        index_sideMenu = new QListWidget(home);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QBrush brush1(QColor(0, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(index_sideMenu);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(index_sideMenu);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setBackground(brush1);
        __qlistwidgetitem1->setForeground(brush);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(index_sideMenu);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setBackground(brush1);
        __qlistwidgetitem2->setForeground(brush);
        index_sideMenu->setObjectName("index_sideMenu");
        index_sideMenu->setGeometry(QRect(0, 0, 181, 575));
        index_sideMenu->setStyleSheet(QString::fromUtf8("QListWidget::item:hover{\n"
"background: orange;\n"
"}\n"
"QListWidget{\n"
"	border-color: white;\n"
"	background-color: white;\n"
"}\n"
"QListWidget::item{\n"
"	padding:20px;\n"
"	border-radius: 5px;\n"
"}\n"
""));
        index_sideMenu->setSpacing(20);
        index_sideMenu->setModelColumn(0);
        index_sideMenu->setUniformItemSizes(false);
        index_sideMenu->setWordWrap(false);
        index_sideMenu->setItemAlignment(Qt::AlignmentFlag::AlignHCenter);
        index_sideMenu->setSortingEnabled(false);
        stackedWidget = new QStackedWidget(home);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(181, 0, 726, 575));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget{text-align:center;}"));
        page = new QWidget();
        page->setObjectName("page");
        gridLayoutWidget = new QWidget(page);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 721, 561));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        index_lastLoginDateLabel = new QLabel(gridLayoutWidget);
        index_lastLoginDateLabel->setObjectName("index_lastLoginDateLabel");
        index_lastLoginDateLabel->setStyleSheet(QString::fromUtf8("QLabel{color:white;}"));

        horizontalLayout->addWidget(index_lastLoginDateLabel);

        index_phoneNumLabel = new QLabel(gridLayoutWidget);
        index_phoneNumLabel->setObjectName("index_phoneNumLabel");
        index_phoneNumLabel->setStyleSheet(QString::fromUtf8("QLabel{color:white;}"));

        horizontalLayout->addWidget(index_phoneNumLabel);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        index_table = new QTableWidget(gridLayoutWidget);
        if (index_table->columnCount() < 4)
            index_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        index_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        index_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        index_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        index_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        index_table->setObjectName("index_table");
        index_table->setMinimumSize(QSize(689, 0));
        index_table->setStyleSheet(QString::fromUtf8("QTableWidget{background-color:white; color:black;}"));
        index_table->horizontalHeader()->setCascadingSectionResizes(true);
        index_table->horizontalHeader()->setMinimumSectionSize(179);
        index_table->horizontalHeader()->setDefaultSectionSize(179);
        index_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        index_table->verticalHeader()->setVisible(true);
        index_table->verticalHeader()->setMinimumSectionSize(50);

        gridLayout->addWidget(index_table, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        index_deleteBtn = new QPushButton(gridLayoutWidget);
        index_deleteBtn->setObjectName("index_deleteBtn");
        index_deleteBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color: gray; color:black;}"));
        index_deleteBtn->setAutoDefault(false);

        horizontalLayout_3->addWidget(index_deleteBtn);

        horizontalLayout_3->setStretch(0, 1);

        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        NameInput = new QLineEdit(gridLayoutWidget);
        NameInput->setObjectName("NameInput");
        NameInput->setStyleSheet(QString::fromUtf8("QLineEdit{color:white;}"));

        horizontalLayout_5->addWidget(NameInput);

        userIdInput = new QLineEdit(gridLayoutWidget);
        userIdInput->setObjectName("userIdInput");
        userIdInput->setStyleSheet(QString::fromUtf8("QLineEdit{color:white;}"));

        horizontalLayout_5->addWidget(userIdInput);

        index_saveBtn = new QPushButton(gridLayoutWidget);
        index_saveBtn->setObjectName("index_saveBtn");
        index_saveBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color: gray; color:black;}"));

        horizontalLayout_5->addWidget(index_saveBtn);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        index_welcomeLabel = new QLabel(gridLayoutWidget);
        index_welcomeLabel->setObjectName("index_welcomeLabel");
        QFont font;
        font.setPointSize(26);
        index_welcomeLabel->setFont(font);
        index_welcomeLabel->setStyleSheet(QString::fromUtf8("QLabel{color: white;}"));

        gridLayout->addWidget(index_welcomeLabel, 0, 0, 2, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayoutWidget_2 = new QWidget(page_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(29, 19, 671, 541));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        profile_phone_input = new QLineEdit(gridLayoutWidget_2);
        profile_phone_input->setObjectName("profile_phone_input");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(profile_phone_input->sizePolicy().hasHeightForWidth());
        profile_phone_input->setSizePolicy(sizePolicy);
        profile_phone_input->setMinimumSize(QSize(0, 50));
        profile_phone_input->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: white; color:black;\n"
"	border-radius: 15px;\n"
"	border-color: pink;\n"
"}\n"
""));
        profile_phone_input->setReadOnly(true);

        gridLayout_2->addWidget(profile_phone_input, 2, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("QLabel{text-align : center; color:white;}"));

        gridLayout_4->addWidget(label_5, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("QLabel{text-align : center; color:white;}"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        profile_count_input = new QLineEdit(gridLayoutWidget_2);
        profile_count_input->setObjectName("profile_count_input");
        profile_count_input->setMinimumSize(QSize(0, 50));
        profile_count_input->setStyleSheet(QString::fromUtf8("QLineEdit{background-color: white; color:black; border-radius:15px;}\n"
""));
        profile_count_input->setReadOnly(true);

        gridLayout_4->addWidget(profile_count_input, 0, 1, 1, 1);

        profile_createTime = new QLineEdit(gridLayoutWidget_2);
        profile_createTime->setObjectName("profile_createTime");
        profile_createTime->setMinimumSize(QSize(0, 50));
        profile_createTime->setStyleSheet(QString::fromUtf8("QLineEdit{background-color: white; color:black;border-radius:15px;}\n"
""));
        profile_createTime->setReadOnly(true);

        gridLayout_4->addWidget(profile_createTime, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 3, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel{text-align : center; color:white;}"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setMargin(20);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        profile_modify_btn = new QPushButton(gridLayoutWidget_2);
        profile_modify_btn->setObjectName("profile_modify_btn");
        profile_modify_btn->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(profile_modify_btn, 4, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel{text-align : center; color:white;}"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3->setMargin(20);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        profile_userPw_input = new QLineEdit(gridLayoutWidget_2);
        profile_userPw_input->setObjectName("profile_userPw_input");
        sizePolicy.setHeightForWidth(profile_userPw_input->sizePolicy().hasHeightForWidth());
        profile_userPw_input->setSizePolicy(sizePolicy);
        profile_userPw_input->setMinimumSize(QSize(0, 50));
        profile_userPw_input->setStyleSheet(QString::fromUtf8("QLineEdit{background-color: white; color:black; border-radius:15px;}\n"
""));

        gridLayout_2->addWidget(profile_userPw_input, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel{text-align : center; color:white;}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setMargin(20);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        profile_userId_input = new QLineEdit(gridLayoutWidget_2);
        profile_userId_input->setObjectName("profile_userId_input");
        sizePolicy.setHeightForWidth(profile_userId_input->sizePolicy().hasHeightForWidth());
        profile_userId_input->setSizePolicy(sizePolicy);
        profile_userId_input->setMinimumSize(QSize(0, 50));
        profile_userId_input->setStyleSheet(QString::fromUtf8("QLineEdit{background-color: white; color:black; border-radius:15px}"));
        profile_userId_input->setReadOnly(true);

        gridLayout_2->addWidget(profile_userId_input, 0, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 3);
        stackedWidget->addWidget(page_2);

        retranslateUi(home);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QWidget *home)
    {
        home->setWindowTitle(QCoreApplication::translate("home", "Form", nullptr));

        const bool __sortingEnabled = index_sideMenu->isSortingEnabled();
        index_sideMenu->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = index_sideMenu->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("home", "home", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = index_sideMenu->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("home", "Profile", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = index_sideMenu->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("home", "Logout", nullptr));
        index_sideMenu->setSortingEnabled(__sortingEnabled);

        index_lastLoginDateLabel->setText(QCoreApplication::translate("home", "\353\247\210\354\247\200\353\247\211 \353\241\234\352\267\270\354\235\270\354\235\274\354\213\234 : ", nullptr));
        index_phoneNumLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = index_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("home", "PhoneNumber", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = index_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("home", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = index_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("home", "UserId", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = index_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("home", "CreateDate", nullptr));
        index_deleteBtn->setText(QCoreApplication::translate("home", "delete", nullptr));
        NameInput->setPlaceholderText(QCoreApplication::translate("home", "Name", nullptr));
        userIdInput->setPlaceholderText(QCoreApplication::translate("home", "UserId", nullptr));
        index_saveBtn->setText(QCoreApplication::translate("home", "\354\240\200\354\236\245\355\225\230\352\270\260", nullptr));
        index_welcomeLabel->setText(QCoreApplication::translate("home", "xxx\353\213\230 \355\231\230\354\230\201\355\225\251\353\213\210\353\213\244", nullptr));
        label_5->setText(QCoreApplication::translate("home", "\352\263\204\354\240\225\354\235\264 \354\203\235\354\204\261\353\220\234 \354\213\234\352\260\204", nullptr));
        label_4->setText(QCoreApplication::translate("home", "\354\240\200\354\236\245\353\220\234 \354\240\204\355\231\224\353\262\210\355\230\270 \354\210\230", nullptr));
        label_2->setText(QCoreApplication::translate("home", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        profile_modify_btn->setText(QCoreApplication::translate("home", "\353\263\200\352\262\275\355\225\230\352\270\260", nullptr));
        label_3->setText(QCoreApplication::translate("home", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        label->setText(QCoreApplication::translate("home", "\354\225\204\354\235\264\353\224\224", nullptr));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
