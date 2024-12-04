#include <../../../../src_h/user_h/userAccount.h>
#include <../../../../src_h/db_h/db.h>
#include <QSqlQuery>

// UserAccount::UserAccount(){};
// UserAccount::~UserAccount(){};


QString UserAccount::getUserId(){
    return this->userId;
}
QString UserAccount::getUserPw(){
    return this->userPw;
}
QString UserAccount::getUserPhoneNumber(){
    return this->userPhoneNumber;
}
QList<UserPhoneNumInfo*>* UserAccount::getUserPhoneNumInfoList(){
    return this->userPhoneNumInfoList;
}
QString UserAccount::getUserLastLogin(){
    return this->userLastLogin;
}
/* 유저의 마지막 로그인 일시 업데이트 */
void UserAccount::updateUserLastLogin(){
    Db* db = new Db();
    QSqlQuery sql;

    sql.prepare("update user set last_login_date = current_timestamp where user_id = :userId");
    sql.bindValue(":userId", UserAccount::getInstance()->getUserId());
    sql.exec();

    db->close();
    sql.clear();
}

