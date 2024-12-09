#include "profileofanother.h"
#include "ui_profileofanother.h"

profileOfAnother::profileOfAnother(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::profileOfAnother)
{
    ui->setupUi(this);
    userIdInput = ui->anoProfile_userId;
    userPhoneInput = ui->anoProfile_phone;
    userNumOfPhoneInput = ui->anoProfile_count;
    userCreateTimeInput = ui->anoProfile_createTime;
}

profileOfAnother::~profileOfAnother()
{
    qDebug() << "profileOfAnother is Destroyed";
    delete ui;
}
