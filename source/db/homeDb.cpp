#include "../../../../header/db/homeDb.h"
#include "../../../../header/db/db.h"

#define MARK ":"
#define VAR_NAME(var) #var
// --------------------------------------------------------------------
/*

 */
QSqlQuery HomeDb::execQuery(QString query, int count, std::vector<QString> placeholders, std::vector<QString> vals){
    Db db;
    QSqlQuery sql;
    sql.prepare(query);

    for(int i = 0; i < count; i++){
        sql.bindValue(placeholders.at(i), vals.at(i));
    }

    sql.exec();
    db.close();


    return sql;
}


QSqlQuery sql;



QSqlQuery HomeDb::getCreatetime(QString owner, QString userId){
    QSqlQuery sql = execQuery("select create_time from phone_number where owner = :owner and user_id = :userId",
                              2,
                              std::vector<QString>{(MARK VAR_NAME(owner)), (MARK VAR_NAME(userId))},
                              std::vector<QString>{owner, userId}
                              );
    sql.next();


    return sql;
}

QSqlQuery HomeDb::findId(QString userId){
    QSqlQuery sql = execQuery("select phone_number from user where user_id = :userId",
                              1,
                              std::vector<QString>{(MARK VAR_NAME(userId))},
                              std::vector<QString>{userId}
                              );
    sql.next();

    return sql;
}
/* user의 전화번호 저장 리스트에서 찾아야됨 */
bool HomeDb::findId(QString owner, QString userId){

    QSqlQuery sql = execQuery("select user_id from phone_number where owner = :owner and user_id = :userId",
              2,
              std::vector<QString>{(MARK VAR_NAME(owner)), (MARK VAR_NAME(userId))},
              std::vector<QString>{owner, userId}
            );

    sql.next();
    QString id = sql.value(0).toString();
    sql.clear();

    return id.isNull() ? false : true;  // 없으면 삽입(true)
}
/* 데이터베이스에 삽입시 */
void HomeDb::save(QString phoneNumber, QString name, QString userId, QString owner){
    QSqlQuery sql = execQuery("insert into phone_number(number, name, user_id, owner) values(:phoneNumber, :name, :userId, :owner)",
                              4,
                              std::vector<QString>{(MARK VAR_NAME(phoneNumber)), (MARK VAR_NAME(name)), (MARK VAR_NAME(userId)), (MARK VAR_NAME(owner))},
                              std::vector<QString>{phoneNumber, name, userId, owner}
                              );

    sql.clear();
}
/* 기존 행 수정시 */
void HomeDb::modify(QString owner, QString name, QString userId){
    QSqlQuery sql = execQuery("update phone_number set name = :name where owner = :owner and user_id = :userId",
                              3,
                              std::vector<QString>{(MARK VAR_NAME(owner)), (MARK VAR_NAME(name)), (MARK VAR_NAME(userId))},
                              std::vector<QString>{owner, name, userId}
                              );
    sql.clear();
}
/* remove row in db */
bool HomeDb::remove(QString userId, QString owner){
    QSqlQuery sql = execQuery("delete from phone_number where owner = :owner and user_id = :userId",
                     2,
                  std::vector<QString>{(MARK VAR_NAME(userId)), (MARK VAR_NAME(owner))},
                  std::vector<QString>{userId, owner}
                    );


    bool result = sql.numRowsAffected();
    sql.finish();
    sql.clear();


    return result;
}
// --------------------------------------------------------------------
profileOfAnother* HomeDb::getAnotherProfile(QString userId){
    QSqlQuery sql = execQuery("select *, (select count(*) from phone_number where owner = :userId) as numOfPhoneNumber from user where user_id = :userId;",
                              1,
                              std::vector<QString>{(MARK VAR_NAME(userId))},
                              std::vector<QString>{userId}
                            );

    profileOfAnother* poa = nullptr;
    if(sql.next()){
        poa = new profileOfAnother;
        poa->setUserId(              sql.value(0).toString());
        poa->setUserPhone(           sql.value(3).toString());
        poa->setUserCreateTime(      sql.value(2).toString());
        poa->setUserNumOfPhoneNumber(sql.value(5).toString());
    }

    return poa;
}
