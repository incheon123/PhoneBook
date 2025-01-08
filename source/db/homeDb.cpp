#include "../../../../header/db/homeDb.h"
#include "../../../../header/db/db.h"

#define VAR_NAME(var) (#var)
// --------------------------------------------------------------------
/*

 */
QSqlQuery HomeDb::sqlSelect(QString query, int count, ...){
    QSqlQuery sql;
    sql.prepare(query);

    va_list list;

    va_start(list, count);     // 임시

    char* sqlParam;

    char placeholder[20] = ":";
    QString val;
    for(int i = 0; i != count; i++){
        sqlParam = const_cast<char*>(va_arg(list, const char*));

        strcat(placeholder, sqlParam);
        val = sqlParam;

        sql.bindValue(":userId", val);

        qDebug() << placeholder;
        qDebug() << val;

        memset(placeholder, 0, sizeof placeholder);
        placeholder[0] = ':';
    }

    va_end(list);

    return sql;
}
void HomeDb::sqlUpdate(){
    QSqlQuery sql;
}
void HomeDb::sqlDelete(){
    QSqlQuery sql;
}

// --------------------------------------------------------------------
profileOfAnother* HomeDb::getAnotherProfile(QString userId){
    Db db;

    QSqlQuery sql = sqlSelect("select *, (select count(*) from phone_number where owner = :userId) as numOfPhoneNumber from user where user_id = :userId;",
                              1,
                              userId.toStdString().c_str()
                            );

    qDebug() << sql.lastQuery();
    profileOfAnother* poa = nullptr;
    sql.exec();
    if(sql.next()){
        poa = new profileOfAnother;
        poa->setUserId(              sql.value(0).toString());
        poa->setUserPhone(           sql.value(3).toString());
        poa->setUserCreateTime(      sql.value(2).toString());
        poa->setUserNumOfPhoneNumber(sql.value(5).toString());

        qDebug() << poa->getUserId();
        qDebug() << poa->getUserPhone();
    }

    db.close();
    return poa;
}
