#include "../../../../ui/home/home.h"
#include "ui_home.h"
// #include <../../../../../phone/phonebook.h>
#include "../../../../header/user/userAccount.h"
#include "../../../../header/user/userPhoneNumInfo.h"
#include "../../../../ui/window_of_anotherProfile/profileofanother.h"
#include "../../../../phonebook.h"

#include <QUiLoader>
#include <QFile>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QRect>
#include <QTableWidgetItem>
#include <QList>
#include <QMenu>
#include <QTableView>
#include <QMouseEvent>
#include <QMessageBox>

home::home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose);    //클로즈하면 메모리에서 삭제됨

    loadUser();

    list = ui->index_sideMenu;

    ui->index_table->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->index_table, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenu(const QPoint&)));

    profile = new Profile();
    profile->init(
        ui->profile_userId_input,
        ui->profile_userPw_input,
        ui->profile_phone_input,
        ui->profile_count_input,
        ui->profile_createTime
    );

    connect(this, &home::decreaseNumOfPhoneNumber, profile, &Profile::updateNumOfPhoneNumber);
    connect(this, &home::increaseNumOfPhoneNumber, profile, &Profile::updateNumOfPhoneNumber);
}
#include "../../../../header/db/homeDb.h"
/* show contextMenu */
void home::showContextMenu(const QPoint &pos){
    QPoint globalPos = ui->index_table->mapToGlobal(pos);

    QTableWidgetItem *item = ui->index_table->itemAt(pos);
    int row = item->row();                                      // row for delete
    QString owner = UserAccount::getInstance()->getUserId();    // owner
    QString userId = ui->index_table->item(row, 2)->text();     // userId

    QMenu menu;
    menu.addAction("Delete");
    menu.addAction("프로필 보기");

    QAction* selectedItem = menu.exec(globalPos);

    if(selectedItem->text().compare("Delete") == 0){
        if(remove(userId, owner)){
            removeRowInTable(row);
            emit decreaseNumOfPhoneNumber(ui->profile_count_input, -1);
            msg("성공적으로 수행했습니다");
        }
    }else{
        /* 다른 사람 프로필 보기 */
        /* 새로운 화면 띄우기 */
        HomeDb hd;
        hd.getAnotherProfile(userId)->show();
    }

}
home::~home()
{
    delete profile;
    delete ui;
}
void home::msg(QString msg){
    QMessageBox box;
    box.setText(msg);
    box.exec();
}

void home::loadUser(){
    UserAccount* ua = UserAccount::getInstance();
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

void home::on_index_deleteBtn_clicked()
{
}
/* user의 전화번호 저장 리스트에서 찾아야됨 */
bool home::findId(QString owner, QString userId){
    QSqlQuery sql;
    sql.prepare("select user_id from phone_number where owner = :owner and user_id = :userId");
    sql.bindValue(":owner", owner);
    sql.bindValue(":userId", userId);
    sql.exec();
    sql.next();

    QString id = sql.value(0).toString();
    sql.clear();

    return id.isNull() ? false : true;  // 없으면 삽입(true)
}
/* 데이터베이스에 삽입시 */
void home::save(QString phoneNumber, QString name, QString userId, QString owner){
    QSqlQuery sql;
    sql.prepare("insert into phone_number(number, name, user_id, owner) values(:phoneNumber, :name, :userId, :owner)");
    sql.bindValue(":phoneNumber", phoneNumber);
    sql.bindValue(":name", name);
    sql.bindValue(":userId", userId);
    sql.bindValue(":owner", owner);

    sql.exec();
    sql.clear();
}
/* 기존 행 수정시 */
void home::modify(QString owner, QString name, QString userId){
    QSqlQuery sql;
    sql.prepare("update phone_number set name = :name where owner = :owner and user_id = :userId");
    sql.bindValue(":name", name);
    sql.bindValue(":owner", owner);
    sql.bindValue(":userId", userId);
    sql.exec();


    sql.clear();
}
/* remove row in db */
bool home::remove(QString userId, QString owner){
    Db *db = new Db();
    QSqlQuery sql;
    sql.prepare("delete from phone_number where owner = :owner and user_id = :userId");
    sql.bindValue(":owner", owner);
    sql.bindValue(":userId", userId);
    sql.exec();
    bool result = sql.numRowsAffected();
    sql.finish();
    sql.clear();
    db->close();

    return result;
}

/* 전화번호 저장 버튼 클릭시 --------------------------------------------------------------------------------------*/
void home::on_index_saveBtn_clicked()
{
    QString name        = ui->NameInput->text();
    QString userId      = ui->userIdInput->text();
    QString owner       = UserAccount::getInstance()->getUserId();  // 현재 로그인한 사용자 아이디 받아옴

    db = new Db();

    if(name.isEmpty()){
        msg("name를 채워주십시오");
        return;
    }
    if(userId.isEmpty()){
        msg("userId를 채워주십시오");
        return;
    }else if(db->getUserId(userId).isNull()){
        msg("조회되지 않는 userId입니다");
        ui->userIdInput->setText("");
        return;
    }

    /* 데이터베이스에 삽입/추가 */
    if(findId(owner, userId)){
        modify(owner, name, userId);
        msg("성공적으로 수정했습니다");

        modifyTable(name, userId);
    }else{
        QString phoneNumber;
        QSqlQuery sql;
        sql.prepare("select phone_number from user where user_id = :userId");
        sql.bindValue(":userId", userId);
        sql.exec();
        sql.next();
        phoneNumber = sql.value(0).toString();

        save(phoneNumber, name, userId, owner);
        msg("성공적으로 추가했습니다!");

        /* 테이블에 행 추가 */
        insertIntoTable(phoneNumber, name, userId, owner);
        emit increaseNumOfPhoneNumber(ui->profile_count_input, 1);

        sql.clear();
    }


    db->close();
}
/* remove row in tableWidget */
void home::removeRowInTable(int row){
    table = ui->index_table;
    table->removeRow(row);
}
/* 테이블에 행 삽입 메서드 */
void home::insertIntoTable(QString phoneNumber, QString name, QString userId, QString owner){
    QSqlQuery sql;
    sql.prepare("select create_time from phone_number where owner = :owner and user_id = :userId");
    sql.bindValue(":owner", owner);
    sql.bindValue(":userId", userId);
    sql.exec();
    sql.next();

    table = ui->index_table;
    table->insertRow(ui->index_table->rowCount());
    table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(phoneNumber));
    table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(name));
    table->setItem(table->rowCount() - 1, 2, new QTableWidgetItem(userId));
    table->setItem(table->rowCount() - 1, 3, new QTableWidgetItem(sql.value(0).toString()));

    sql.exec();
    sql.clear();
}
/* 테이블 행 수정하기 */
void home::modifyTable(QString name, QString userId){
    table = ui->index_table;

    table->setItem(selectedRow, 1, new QTableWidgetItem(name));
}
/* 테이블 셀 클릭시 */
void home::on_index_table_cellClicked(int row, int column)
{
    table = ui->index_table;

    QString phoneNumber = table->item(row,0)->text();
    QString name = table->item(row,1)->text();
    QString userId = table->item(row,2)->text();

    ui->NameInput->setText(name);
    ui->userIdInput->setText(userId);

    selectedRow = row;
}
#include "../../../../header/account/logout.h"
/* switch page */
void home::on_index_sideMenu_itemClicked(QListWidgetItem *item)
{
    QString menu = item->text();
    QStackedWidget* sw = ui->stackedWidget;

    if(menu.compare("home") == 0){
        sw->setCurrentIndex(0);
    }else if(menu.compare("Profile") == 0){
        sw->setCurrentIndex(1);
    }else if(menu.compare("Logout") == 0){
        Logout *logout=new Logout();
        logout->logout(ph, this);
    }
}

void home::on_profile_modify_btn_clicked()
{
    bool result = profile->modifyPw(ui->profile_userPw_input->text());
    if(result)  msg("성공적으로 수행했습니다");
    else        msg("실패하였습니다");
}
