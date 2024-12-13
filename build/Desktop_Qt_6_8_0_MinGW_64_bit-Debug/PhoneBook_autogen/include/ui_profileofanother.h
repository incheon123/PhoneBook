/********************************************************************************
** Form generated from reading UI file 'profileofanother.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEOFANOTHER_H
#define UI_PROFILEOFANOTHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profileOfAnother
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *anoProfile_phone;
    QLineEdit *anoProfile_userId;
    QLabel *label;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *anoProfile_count;
    QLabel *label_5;
    QLineEdit *anoProfile_createTime;

    void setupUi(QWidget *profileOfAnother)
    {
        if (profileOfAnother->objectName().isEmpty())
            profileOfAnother->setObjectName("profileOfAnother");
        profileOfAnother->resize(810, 494);
        profileOfAnother->setStyleSheet(QString::fromUtf8("background-color: lightblue;"));
        gridLayoutWidget = new QWidget(profileOfAnother);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(100, 50, 631, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        anoProfile_phone = new QLineEdit(gridLayoutWidget);
        anoProfile_phone->setObjectName("anoProfile_phone");
        anoProfile_phone->setMinimumSize(QSize(0, 50));
        anoProfile_phone->setReadOnly(true);

        gridLayout->addWidget(anoProfile_phone, 2, 1, 1, 1);

        anoProfile_userId = new QLineEdit(gridLayoutWidget);
        anoProfile_userId->setObjectName("anoProfile_userId");
        anoProfile_userId->setMinimumSize(QSize(0, 50));
        anoProfile_userId->setReadOnly(true);

        gridLayout->addWidget(anoProfile_userId, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 50));
        label->setStyleSheet(QString::fromUtf8("color: black;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 50));
        label_4->setStyleSheet(QString::fromUtf8("color : black;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color:black;"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_6);

        anoProfile_count = new QLineEdit(gridLayoutWidget);
        anoProfile_count->setObjectName("anoProfile_count");
        anoProfile_count->setMinimumSize(QSize(0, 50));
        anoProfile_count->setReadOnly(true);

        horizontalLayout->addWidget(anoProfile_count);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color:black;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_5);

        anoProfile_createTime = new QLineEdit(gridLayoutWidget);
        anoProfile_createTime->setObjectName("anoProfile_createTime");
        anoProfile_createTime->setMinimumSize(QSize(0, 50));
        anoProfile_createTime->setReadOnly(true);

        horizontalLayout->addWidget(anoProfile_createTime);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);

        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 3);

        retranslateUi(profileOfAnother);

        QMetaObject::connectSlotsByName(profileOfAnother);
    } // setupUi

    void retranslateUi(QWidget *profileOfAnother)
    {
        profileOfAnother->setWindowTitle(QCoreApplication::translate("profileOfAnother", "Form", nullptr));
        label->setText(QCoreApplication::translate("profileOfAnother", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        label_4->setText(QCoreApplication::translate("profileOfAnother", "\354\225\204\354\235\264\353\224\224", nullptr));
        label_6->setText(QCoreApplication::translate("profileOfAnother", "\354\240\204\355\231\224\353\262\210\355\230\270\354\210\230", nullptr));
        label_5->setText(QCoreApplication::translate("profileOfAnother", "\354\203\235\354\204\261\354\213\234\352\260\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profileOfAnother: public Ui_profileOfAnother {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEOFANOTHER_H
