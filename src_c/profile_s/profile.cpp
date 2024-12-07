#include "../../../../src_h/profile_h/profile.h"
#include "../../../../src_h/db_h/db.h"

#include <QSqlQuery>
#include <QLineEdit>

Profile::Profile(QWidget *parent)
    : QWidget(parent)
{

}

// Profile::Profile(){
//     // this->userId = userId;
//     // this->userPw = userPw;
//     // this->userPhoneNumber = phoneNumber;
//     // this->userNumOfPhoneNumber = numOfPhoneNumber;
//     // this->userCreateTime = createTime;
// }
void Profile::init(QLineEdit* userId, QLineEdit* userPw,QLineEdit* userPhoneNumber,QLineEdit* userNumOfPhoneNumber,QLineEdit* userCreateTime){
    userId->setText(this->userId);
    userPw->setText(this->userPw);
    userPhoneNumber->setText(this->userPhoneNumber);
    userNumOfPhoneNumber->setText(QString::number(this->userNumOfPhoneNumber));
    userCreateTime->setText(this->userCreateTime);
}
/* modify 버튼을 클릭시 */
bool Profile::modify(){
    Db* db = new Db();
    QSqlQuery sql;
    sql.prepare("update user set user_pw = :userPw");
    sql.exec();
    int affected = sql.numRowsAffected();

    sql.clear();
    db->close();

    return affected;
}
// QString select(QString query){
//     QSqlQuery sql;
//     sql.prepare(query);
//     sql.exec();
//     sql.next();
//     sql.clear();
//     return sql.value(0).toString();
// };
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
