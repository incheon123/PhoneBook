#include "home.h"
#include "ui_home.h"
#include <../../../../../phone/phonebook.h>
#include <../../../../src_h/user_h/userAccount.h>
#include "../../../../src_h/user_h/userPhoneNumInfo.h"

#include <QUiLoader>
#include <QFile>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QRect>
#include <QTableWidgetItem>
#include <QList>

home::home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);

    loadUser();
}

home::~home()
{
    delete ui;
}

void home::save(QWidget* widget){
    QUiLoader loader;
    QFile file("C:\\Users\\oppor\\Documents\\phone\\home.ui");
    file.open(QFile::ReadOnly);

    QWidget *myWidget = loader.load(&file, widget);
    file.close();

    // connect(this, &home::addBtn_clicked, this, &home::on_index_addBtn_clicked);
    // emit void addBtn_clicked();

}
void home::openHome(){

}
void home::closeHome(){

}

void home::errorMsg(QString msg){
    QMessageBox box;
    box.setText(msg);
    box.exec();
}
void home::msg(QString msg){
    QMessageBox box;
    box.setText(msg);
    box.exec();
}

void home::loadUser(){
    UserAccount* ua = UserAccount::getInstance();
    qDebug() << ua->getUserLastLogin();
    ui->index_lastLoginDateLabel->setText(QString("마지막 로그인일시 : ") + ua->getUserLastLogin());
    ui->index_welcomeLabel->setText(ua->getUserId() + QString("님 환영합니다"));
    ui->index_phoneNumLabel->setText(QString("전화번호 : ") + ua->getUserPhoneNumber());

    /* 테이블에 행 추가 */
    QTableWidget* table = ui->index_table;

    for(UserPhoneNumInfo* list : ua->getUserPhoneNumInfoList()->toList()){
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(list->getPhoneNumber()));
        table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(list->getName()));
        table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem(list->getPhoneNumUserId()));
        table->setItem(table->rowCount() - 1, 3, new QTableWidgetItem(list->getCreateTime()));
    }

}

void home::on_index_addBtn_clicked()
{
}
void home::on_index_deleteBtn_clicked()
{
    qDebug() << "clicked delete";
}
void home::on_index_updateBtn_clicked()
{
    qDebug() << "clicked update";
}

void home::on_index_saveBtn_clicked()
{
    QString phoneNumber = ui->phoneNumberInput->text();
    QString name        = ui->NameInput->text();
    QString userId      = ui->userIdInput->text();
    QString owner       = UserAccount::getInstance()->getUserId();  // 현재 로그인한 사용자 아이디 받아옴

    db = new Db();

    if(phoneNumber.isEmpty()){
        errorMsg("phoneNumber를 채워주십시오");
        return;
    }else if(phoneNumber.length() != 11){
        errorMsg("phoneNumber는 11자여야 합니다");
        return;
    }
    if(name.isEmpty()){
        errorMsg("name를 채워주십시오");
        return;
    }
    if(userId.isEmpty()){
        errorMsg("userId를 채워주십시오");
        return;
    }else if(db->getUserId(userId).isNull()){
        errorMsg("조회되지 않는 userId입니다");
        ui->userIdInput->setText("");
        return;
    }

    QSqlQuery sql;
    QString result = NULL;
    sql.prepare("insert into phone_number(number, name, user_id, owner) values(:phoneNumber, :name, :userId, :owner)");
    sql.bindValue(":phoneNumber", phoneNumber);
    sql.bindValue(":name", name);
    sql.bindValue(":userId", userId);
    sql.bindValue(":owner", owner);

    sql.exec();

    msg("성공적으로 추가했습니다!");
    db->close();
    // table->setItem(0,0 , new QTableWidgetItem(phoneNumber));
}
