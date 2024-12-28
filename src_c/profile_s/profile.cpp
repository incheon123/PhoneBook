#include "../../src_h/profile_h/profile.h"
#include "../../src_h/db_h/db.h"

#include <QSqlQuery>
#include <QLineEdit>

Profile::Profile(QWidget *parent)
    : QWidget(parent)
{
    setProfile();
}

void Profile::init(QLineEdit* userId, QLineEdit* userPw,QLineEdit* userPhoneNumber,QLineEdit* userNumOfPhoneNumber,QLineEdit* userCreateTime){
    userId->setText(this->userId);
    userPw->setText(this->userPw);
    userPhoneNumber->setText(this->userPhoneNumber);
    userNumOfPhoneNumber->setText(QString::number(this->userNumOfPhoneNumber));
    userCreateTime->setText(this->userCreateTime);
}
/* modify 버튼을 클릭시 */
bool Profile::modifyPw(QString pw){
    Db* db = new Db();
    QSqlQuery sql;
    sql.prepare("update user set user_pw = :userPw where user_id = :userId");
    sql.bindValue(":userPw", pw);
    sql.bindValue(":userId", UserAccount::getInstance()->getUserId());
    sql.exec();
    int affected = sql.numRowsAffected();

    sql.clear();
    db->close();

    return affected;
}
void Profile::setUserId(QString str){
    this->userId = UserAccount::getInstance()->getUserId();
}
void Profile::setUserPw(QString userPw){
    this->userPw = userPw;
}
void Profile::setUserPhoneNumber(QString userPhoneNumber){
    this->userPhoneNumber = userPhoneNumber;
}
void Profile::setUserNumOfPhoneNumber(int userNumOfPhoneNumber){
    this->userNumOfPhoneNumber = userNumOfPhoneNumber;
}
void Profile::setUserCreateTime(QString createTime){
    this->userCreateTime = createTime;
}

void Profile::updateNumOfPhoneNumber(QLineEdit* userNumOfPhoneNumber, int num){
    this->userNumOfPhoneNumber += num;
    userNumOfPhoneNumber->setText(QString::number(this->userNumOfPhoneNumber));
}

void Profile::setProfile(){
    setUserId(UserAccount::getInstance()->getUserId());
    setUserPw(UserAccount::getInstance()->getUserPw());
    setUserPhoneNumber(UserAccount::getInstance()->getUserPhoneNumber());
    setUserNumOfPhoneNumber(UserAccount::getInstance()->getUserNumOfPhoneNumber());
    setUserCreateTime(UserAccount::getInstance()->getUserCreateTime());
}
