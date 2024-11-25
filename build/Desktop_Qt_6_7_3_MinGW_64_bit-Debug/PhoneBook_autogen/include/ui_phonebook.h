/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
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
    QWidget *page;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *page_2;
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
        stackedWidget->setGeometry(QRect(0, 0, 907, 553));
        stackedWidget->setMaximumSize(QSize(907, 16777215));
        page = new QWidget();
        page->setObjectName("page");
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(400, 100, 214, 50));
        lineEdit->setMaximumSize(QSize(16777215, 50));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 70, 91, 109));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(270, 160, 101, 109));
        label_4->setFont(font);
        lineEdit_4 = new QLineEdit(page);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(true);
        lineEdit_4->setGeometry(QRect(400, 190, 214, 50));
        lineEdit_4->setMaximumSize(QSize(16777215, 50));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(274, 300, 340, 51));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(280, 360, 160, 51));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(450, 360, 160, 51));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        PhoneBook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PhoneBook);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 907, 22));
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
        label->setText(QCoreApplication::translate("PhoneBook", "User ID", nullptr));
        label_4->setText(QCoreApplication::translate("PhoneBook", "User PW", nullptr));
        pushButton->setText(QCoreApplication::translate("PhoneBook", "Sign in", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PhoneBook", "Forget Account", nullptr));
        pushButton_5->setText(QCoreApplication::translate("PhoneBook", "Sigin up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhoneBook: public Ui_PhoneBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
