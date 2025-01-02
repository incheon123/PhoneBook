#include "../../src_h/db_h/db.h"

Db::Db(){

#ifndef DB_OPENED
#define DB_OPENED
    db = QSqlDatabase::database();  // 기존 db 객체 가져옴
    db.open();
    qDebug() << "db is open";
#endif

    if(db.isOpen()){
        qDebug() << "Database Connection success";
        connectionStat = true;
    }else{
        qDebug() << "Database Connection failed";
        connectionStat = false;
    }

    return;
}
Db::~Db(){
    db.close();
}

void Db::close(){
    db.close();
}

QSqlDatabase Db::getDriver(){
    return db;
}

/* */
QString Db::login(QString userId, QString userPw){
    QString result = NULL;
    QSqlQuery sql;

    sql.prepare("select user_id from user where user_id = :userId and user_pw = :userPw");
    sql.bindValue(":userId", userId);
    sql.bindValue(":userPw", userPw);

    sql.exec();

    if(sql.next()){
        result = sql.value(0).toString();
    }
    return result;
}

/* 회원가입 */
bool Db::signup(QString userId, QString userPw, QString phone_number){
    QSqlQuery sql;

    sql.prepare("insert into user(user_id, user_pw, phone_number) values(:userId, :userPw, :phone_number)");
    sql.bindValue(":userId", userId);
    sql.bindValue(":userPw", userPw);
    sql.bindValue(":phone_number", phone_number);

    sql.exec();

    return sql.numRowsAffected() ? true : false;
}

/* 유저 아이디 조회(문제있음) */
QString Db::getUserId(QString userId){
    QString result = NULL;
    QSqlQuery sql;

    sql.prepare("select user_id from user where user_id = :userId");
    sql.bindValue(":userId", userId);

    sql.exec();

    if(sql.next()){
        result = sql.value(0).toString();
    }
    return result;
}

/* 비밀번호 찾는 함수 */
QString Db::findUserPw(QString userId){
    QString id = getUserId(userId);

    if(id.isNull()) return NULL;

    QString result = NULL;
    QSqlQuery sql;

    sql.prepare("select user_pw from user where user_id = :userId");
    sql.bindValue(":userId", userId);
    sql.exec();

    if(sql.next()){
        result = sql.value(0).toString();
    }

    return result;
}

UserAccount* Db::getUser(QString userId){
    QSqlQuery sql;

    sql.prepare("select * from user where user_id = :userId");
    sql.bindValue(":userId", userId);
    sql.exec();

    UserAccount* ua = UserAccount::getInstance();
    if(sql.next()){
        ua->setUserId(sql.value(0).toString());
        ua->setUserPw(sql.value(1).toString());
        ua->setUserLastLogin(sql.value(4).toString());
        ua->setUserPhoneNumber(sql.value(3).toString());
        // ua->setUserPhoneNumberList();
    }

    return ua;
}
