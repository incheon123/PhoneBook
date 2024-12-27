#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QList>

#include "../../../../src_h/db_h/db.h"

class Login : QWidget{
    Q_OBJECT

public:                             // variable

public:                             // method
    Login();
    void login(QString, QString);
    bool result();
private:                            //  variable
    Db* db;
    bool m_result = false;
private:                            //  method
    void setAccount(QString, QList<UserPhoneNumInfo *>*);
    QList<UserPhoneNumInfo*>* getUserPhoneNumList(QString);
};

#endif // LOGIN_H
