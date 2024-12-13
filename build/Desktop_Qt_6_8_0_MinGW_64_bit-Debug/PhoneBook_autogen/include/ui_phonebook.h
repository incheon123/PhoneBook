/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneBook
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page1_signin;
    QLineEdit *login_userId;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *login_userPw;
    QPushButton *signin;
    QPushButton *forgetAccount;
    QPushButton *signup;
    QLabel *signin_userPwLabel;
    QLabel *signin_userIdLabel;
    QWidget *page2_findAccount;
    QLineEdit *findPw_pwInput;
    QPushButton *submit;
    QLabel *find_account_pw_lb;
    QPushButton *find_account_back_btn;
    QLabel *findPw_pwLabel;
    QWidget *page3_signup;
    QLabel *signup_user_id_lb;
    QLineEdit *signup_user_id_input;
    QPushButton *signup_user_id_dp_chk_btn;
    QLabel *signup_user_id_lb_2;
    QLineEdit *signup_user_pw_input;
    QLineEdit *signup_user_pw_double_input;
    QLabel *signup_user_id_dp_chk_lb;
    QPushButton *signup_submit_btn;
    QLabel *signup_user_id_lb_3;
    QLineEdit *signup_user_phone_number_input;
    QPushButton *signup_back_btn;
    QLabel *signup_pw_chk_lb;
    QLabel *signup_phone_number_chk_lbl;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PhoneBook)
    {
        if (PhoneBook->objectName().isEmpty())
            PhoneBook->setObjectName("PhoneBook");
        PhoneBook->resize(907, 575);
        centralwidget = new QWidget(PhoneBook);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-10, 0, 907, 553));
        stackedWidget->setMaximumSize(QSize(907, 16777215));
        page1_signin = new QWidget();
        page1_signin->setObjectName("page1_signin");
        login_userId = new QLineEdit(page1_signin);
        login_userId->setObjectName("login_userId");
        login_userId->setEnabled(true);
        login_userId->setGeometry(QRect(400, 100, 214, 50));
        login_userId->setMaximumSize(QSize(16777215, 50));
        label = new QLabel(page1_signin);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 70, 121, 109));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_4 = new QLabel(page1_signin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(270, 160, 131, 109));
        label_4->setFont(font);
        login_userPw = new QLineEdit(page1_signin);
        login_userPw->setObjectName("login_userPw");
        login_userPw->setEnabled(true);
        login_userPw->setGeometry(QRect(400, 190, 214, 50));
        login_userPw->setMaximumSize(QSize(16777215, 50));
        signin = new QPushButton(page1_signin);
        signin->setObjectName("signin");
        signin->setGeometry(QRect(274, 300, 340, 51));
        forgetAccount = new QPushButton(page1_signin);
        forgetAccount->setObjectName("forgetAccount");
        forgetAccount->setGeometry(QRect(280, 360, 160, 51));
        signup = new QPushButton(page1_signin);
        signup->setObjectName("signup");
        signup->setGeometry(QRect(450, 360, 160, 51));
        signin_userPwLabel = new QLabel(page1_signin);
        signin_userPwLabel->setObjectName("signin_userPwLabel");
        signin_userPwLabel->setGeometry(QRect(400, 260, 201, 20));
        signin_userIdLabel = new QLabel(page1_signin);
        signin_userIdLabel->setObjectName("signin_userIdLabel");
        signin_userIdLabel->setGeometry(QRect(400, 160, 201, 20));
        stackedWidget->addWidget(page1_signin);
        page2_findAccount = new QWidget();
        page2_findAccount->setObjectName("page2_findAccount");
        findPw_pwInput = new QLineEdit(page2_findAccount);
        findPw_pwInput->setObjectName("findPw_pwInput");
        findPw_pwInput->setGeometry(QRect(200, 230, 511, 51));
        QFont font1;
        font1.setPointSize(12);
        findPw_pwInput->setFont(font1);
        submit = new QPushButton(page2_findAccount);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(730, 220, 131, 71));
        find_account_pw_lb = new QLabel(page2_findAccount);
        find_account_pw_lb->setObjectName("find_account_pw_lb");
        find_account_pw_lb->setGeometry(QRect(200, 290, 501, 91));
        QFont font2;
        font2.setPointSize(15);
        find_account_pw_lb->setFont(font2);
        find_account_back_btn = new QPushButton(page2_findAccount);
        find_account_back_btn->setObjectName("find_account_back_btn");
        find_account_back_btn->setGeometry(QRect(30, 20, 93, 29));
        findPw_pwLabel = new QLabel(page2_findAccount);
        findPw_pwLabel->setObjectName("findPw_pwLabel");
        findPw_pwLabel->setGeometry(QRect(200, 310, 341, 51));
        findPw_pwLabel->setFont(font1);
        stackedWidget->addWidget(page2_findAccount);
        page3_signup = new QWidget();
        page3_signup->setObjectName("page3_signup");
        signup_user_id_lb = new QLabel(page3_signup);
        signup_user_id_lb->setObjectName("signup_user_id_lb");
        signup_user_id_lb->setGeometry(QRect(110, 90, 161, 71));
        signup_user_id_lb->setFont(font2);
        signup_user_id_input = new QLineEdit(page3_signup);
        signup_user_id_input->setObjectName("signup_user_id_input");
        signup_user_id_input->setGeometry(QRect(270, 100, 301, 51));
        signup_user_id_dp_chk_btn = new QPushButton(page3_signup);
        signup_user_id_dp_chk_btn->setObjectName("signup_user_id_dp_chk_btn");
        signup_user_id_dp_chk_btn->setGeometry(QRect(600, 100, 141, 51));
        signup_user_id_lb_2 = new QLabel(page3_signup);
        signup_user_id_lb_2->setObjectName("signup_user_id_lb_2");
        signup_user_id_lb_2->setGeometry(QRect(110, 190, 161, 71));
        signup_user_id_lb_2->setFont(font2);
        signup_user_pw_input = new QLineEdit(page3_signup);
        signup_user_pw_input->setObjectName("signup_user_pw_input");
        signup_user_pw_input->setGeometry(QRect(270, 200, 301, 51));
        signup_user_pw_double_input = new QLineEdit(page3_signup);
        signup_user_pw_double_input->setObjectName("signup_user_pw_double_input");
        signup_user_pw_double_input->setGeometry(QRect(270, 270, 301, 51));
        signup_user_id_dp_chk_lb = new QLabel(page3_signup);
        signup_user_id_dp_chk_lb->setObjectName("signup_user_id_dp_chk_lb");
        signup_user_id_dp_chk_lb->setGeometry(QRect(270, 160, 171, 20));
        signup_submit_btn = new QPushButton(page3_signup);
        signup_submit_btn->setObjectName("signup_submit_btn");
        signup_submit_btn->setGeometry(QRect(270, 460, 471, 51));
        signup_user_id_lb_3 = new QLabel(page3_signup);
        signup_user_id_lb_3->setObjectName("signup_user_id_lb_3");
        signup_user_id_lb_3->setGeometry(QRect(110, 340, 161, 71));
        signup_user_id_lb_3->setFont(font2);
        signup_user_phone_number_input = new QLineEdit(page3_signup);
        signup_user_phone_number_input->setObjectName("signup_user_phone_number_input");
        signup_user_phone_number_input->setGeometry(QRect(270, 360, 301, 51));
        signup_back_btn = new QPushButton(page3_signup);
        signup_back_btn->setObjectName("signup_back_btn");
        signup_back_btn->setGeometry(QRect(30, 20, 93, 29));
        signup_pw_chk_lb = new QLabel(page3_signup);
        signup_pw_chk_lb->setObjectName("signup_pw_chk_lb");
        signup_pw_chk_lb->setGeometry(QRect(270, 330, 171, 16));
        signup_phone_number_chk_lbl = new QLabel(page3_signup);
        signup_phone_number_chk_lbl->setObjectName("signup_phone_number_chk_lbl");
        signup_phone_number_chk_lbl->setGeometry(QRect(270, 430, 191, 16));
        stackedWidget->addWidget(page3_signup);
        PhoneBook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PhoneBook);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 907, 25));
        PhoneBook->setMenuBar(menubar);
        statusbar = new QStatusBar(PhoneBook);
        statusbar->setObjectName("statusbar");
        PhoneBook->setStatusBar(statusbar);

        retranslateUi(PhoneBook);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PhoneBook);
    } // setupUi

    void retranslateUi(QMainWindow *PhoneBook)
    {
        PhoneBook->setWindowTitle(QCoreApplication::translate("PhoneBook", "PhoneBook", nullptr));
        login_userId->setPlaceholderText(QCoreApplication::translate("PhoneBook", "userId", nullptr));
        label->setText(QCoreApplication::translate("PhoneBook", "User ID", nullptr));
        label_4->setText(QCoreApplication::translate("PhoneBook", "User PW", nullptr));
        login_userPw->setPlaceholderText(QCoreApplication::translate("PhoneBook", "userPw", nullptr));
        signin->setText(QCoreApplication::translate("PhoneBook", "Sign in", nullptr));
        forgetAccount->setText(QCoreApplication::translate("PhoneBook", "Forget Account", nullptr));
        signup->setText(QCoreApplication::translate("PhoneBook", "Sigin up", nullptr));
        signin_userPwLabel->setText(QString());
        signin_userIdLabel->setText(QString());
        findPw_pwInput->setPlaceholderText(QCoreApplication::translate("PhoneBook", "Enter Id", nullptr));
        submit->setText(QCoreApplication::translate("PhoneBook", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260", nullptr));
        find_account_pw_lb->setText(QString());
        find_account_back_btn->setText(QCoreApplication::translate("PhoneBook", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        findPw_pwLabel->setText(QString());
        signup_user_id_lb->setText(QCoreApplication::translate("PhoneBook", "\354\225\204\354\235\264\353\224\224", nullptr));
        signup_user_id_input->setPlaceholderText(QCoreApplication::translate("PhoneBook", "user_id", nullptr));
        signup_user_id_dp_chk_btn->setText(QCoreApplication::translate("PhoneBook", "\354\225\204\354\235\264\353\224\224 \354\244\221\353\263\265 \355\231\225\354\235\270", nullptr));
        signup_user_id_lb_2->setText(QCoreApplication::translate("PhoneBook", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        signup_user_pw_input->setPlaceholderText(QCoreApplication::translate("PhoneBook", "user_pw", nullptr));
        signup_user_pw_double_input->setPlaceholderText(QCoreApplication::translate("PhoneBook", "user_pw", nullptr));
        signup_user_id_dp_chk_lb->setText(QString());
        signup_submit_btn->setText(QCoreApplication::translate("PhoneBook", "\352\260\200\354\236\205\354\231\204\353\243\214", nullptr));
        signup_user_id_lb_3->setText(QCoreApplication::translate("PhoneBook", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        signup_user_phone_number_input->setPlaceholderText(QCoreApplication::translate("PhoneBook", "user_phone", nullptr));
        signup_back_btn->setText(QCoreApplication::translate("PhoneBook", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        signup_pw_chk_lb->setText(QString());
        signup_phone_number_chk_lbl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PhoneBook: public Ui_PhoneBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
