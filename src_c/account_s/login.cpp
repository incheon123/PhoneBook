#include "../../../../src_h/account_h/login.h"

/* constructor */
Login::Login(){
    // db = new Db();
    m_result = false;
}

#include "../../../../src_h/db_h/db.h"
/* 로그인 */
void Login::login(QString user_id, QString user_pw){
    db = new Db();
    m_result = false;   // 로그인 실패

    if(db->isDbConnection()){
        if(db->login(user_id, user_pw).isNull())
            return;

        QList<UserPhoneNumInfo*>* list = getUserPhoneNumList(user_id);
        setAccount(user_id, list);

        m_result = true;    // 로그인 성공
    }


    return;
}
/* 로그인한 유저가 소유하고 있는 타전화번호 목록 */
QList<UserPhoneNumInfo*>* Login::getUserPhoneNumList(QString user_id){
    QSqlQuery sql;
    sql.prepare("select pn.number, pn.name, pn.user_id, pn.create_time from user u, phone_number pn where u.user_id = :userId and  u.user_id = pn.owner;");
    sql.bindValue(":userId", user_id);
    sql.exec();

    QList<UserPhoneNumInfo*>* list = new QList<UserPhoneNumInfo*>;
    while(sql.next()){
        UserPhoneNumInfo *u;
        u = new UserPhoneNumInfo;
        u->setPhoneNumber(sql.value(0).toString());        // 전화번호
        u->setName(sql.value(1).toString());               // 별칭
        u->setPhoneNumUserId(sql.value(2).toString());     // 어떤 아이디의 전화번호인지
        u->setCreateTime(sql.value(3).toString());          // 생성 일자
        list->append(u);
    }

    return list;
}
/* 싱글톤 클래스에 로그인 유저 정보 저장 */
/* 어느 클래스에서든 접근할 수 있음 */
void Login::setAccount(QString user_id, QList<UserPhoneNumInfo *>* list){
    QSqlQuery sql;
    sql.prepare("select * from user where user_id = :userId");
    sql.bindValue(":userId", user_id);
    sql.exec();

    UserAccount* ua = UserAccount::getInstance();
    if(sql.next()){
        qDebug() << sql.value(0).toString();
        ua->setUserId(sql.value(0).toString());
        ua->setUserPw(sql.value(1).toString());
        ua->setUserCreateTime(sql.value(2).toString());
        ua->setUserPhoneNumber(sql.value(3).toString());
        ua->setUserLastLogin(sql.value(4).toString());
        ua->setUserPhoneNumInfoList(list);
        ua->updateUserLastLogin();
        ua->setUserNumOfPhoneNumber((list)->size());
    }
}

bool Login::result(){
    return m_result;
}
