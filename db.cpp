#include "db.h"

Db::Db(QString hostName, QString databaseName, QString userName, QString password, int port){
    db = QSqlDatabase::addDatabase("QMYSQL");
    qDebug() << db.drivers();

    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
    db.setPort(port);

    db.open();

    if(db.isOpen())
        qDebug() << "Db Connection Succeded";
};

// Db::~Db(){
//     db.close();
// }

void Db::close(){
    db.close();
}

QSqlDatabase Db::getDriver(){
    return db;
}

/* */
QString Db::login(QString userId, QString userPw){
    QSqlQuery sql;

    return "1";
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

/* 유저 아이디 조회 */
QString Db::getUserId(QString userId){
    QString result = NULL;
    QSqlQuery sql;

    sql.prepare("select user_id from user where user_id = :userId");
    sql.bindValue(":userId", userId);

    sql.exec();

    if(sql.next()){
        result = sql.value(0).toString();
    }
    qDebug() << "유저 아이디 조회 결과입니다 ==> " << result;

    return result;
}
