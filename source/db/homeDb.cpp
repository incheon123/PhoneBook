#include "../../../../header/db/homeDb.h"

#include <QSqlQuery>

#define GET_VAR_NAME(var) (#var)

profileOfAnother* HomeDb::getAnotherProfile(QString userId){
    QString query_parameter = GET_VAR_NAME(userId);
    query_parameter.insert(0, ":");

    QSqlQuery sql;
    sql.prepare("select *, (select count(*) from phone_number where owner = :userId) as numOfPhoneNumber from user where user_id = :userId;");
    sql.bindValue(query_parameter, userId);
    sql.exec();

    profileOfAnother* poa = nullptr;
    if(sql.next()){
        poa = new profileOfAnother;
        poa->setUserId(sql.value(0).toString());
        poa->setUserPhone(sql.value(3).toString());
        poa->setUserCreateTime(sql.value(2).toString());
        poa->setUserNumOfPhoneNumber(sql.value(5).toString());
    }


    return poa;
}
