#ifndef DB_H
#define DB_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "../../src_h/user_h/userAccount.h"

class Db : public QObject{
    Q_OBJECT

public:
    Db();
    ~Db();

    void close();
    QString login(QString userId, QString userPw);
    bool signup(QString userId, QString userPw, QString phone_number);
    QSqlDatabase getDriver();
    QString getUserId(QString userId);
    QString getUserPw(QString userPw);
    QString findUserPw(QString userId);
    UserAccount* getUser(QString userId);

private:

private:
    QSqlDatabase db;
};

#endif // DB_H
