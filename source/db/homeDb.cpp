#include "../../../../header/db/homeDb.h"
#include "../../../../header/db/db.h"

#define MARK ":"
#define VAR_NAME(var) #var
// --------------------------------------------------------------------
/*

 */
QSqlQuery HomeDb::sqlSelect(QString query, int count, std::vector<QString> placeholders, std::vector<QString> vals){
    QSqlQuery sql;
    sql.prepare(query);

    for(int i = 0; i < count; i++){
        qDebug() << placeholders.at(i) << Qt::endl;
        qDebug() << vals.at(i) << Qt::endl;
        sql.bindValue(placeholders.at(i), vals.at(i));
    }

    sql.exec();
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
                              std::vector<QString>{(MARK VAR_NAME(userId))},
                              std::vector<QString>{userId}
                            );

    profileOfAnother* poa = nullptr;
    if(sql.next()){
        qDebug() << "Fuck";
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
