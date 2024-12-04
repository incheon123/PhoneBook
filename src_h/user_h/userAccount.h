#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QWidget>
#include <QList>
#include "./userPhoneNumInfo.h"

class UserAccount : QWidget{
    Q_OBJECT

private:
    UserAccount() = default;
    QString userId;
    QString userPw;
    QString userPhoneNumber;
    QList<UserPhoneNumInfo*>* userPhoneNumInfoList;
    QString userLastLogin;
    static UserAccount* instance;

public:
    static UserAccount* getInstance(){
        static UserAccount ua;
        return &ua;
    }
    UserAccount(const UserAccount&) = delete;
    void setUserId(QString userId)  { this->userId = userId; }
    void setUserPw(QString userPw)  { this->userPw = userPw; }
    void setUserPhoneNumber(QString userPhoneNumber){ this->userPhoneNumber = userPhoneNumber; }
    void setUserPhoneNumInfoList(QList<UserPhoneNumInfo*>* userPhoneNumInfoList){ this->userPhoneNumInfoList = userPhoneNumInfoList; }
    void setUserLastLogin(QString userLastLogin) {this->userLastLogin = userLastLogin; }
    void updateUserLastLogin();
    QString getUserId();
    QString getUserPw();
    QString getUserPhoneNumber();
    QList<UserPhoneNumInfo*>* getUserPhoneNumInfoList();
    QString getUserLastLogin();
};

#endif // USERACCOUNT_H
