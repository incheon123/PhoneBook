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
    QString userCreateTime;
    QString userLastLogin;
    int userNumOfPhoneNumber;
    static UserAccount* instance;

public:
    static UserAccount* getInstance(){
        static UserAccount ua;
        return &ua;
    }
    UserAccount(const UserAccount&) = delete;
    void setUserId(QString userId)                                              { this->userId = userId; }
    void setUserPw(QString userPw)                                              { this->userPw = userPw; }
    void setUserPhoneNumber(QString userPhoneNumber)                            { this->userPhoneNumber = userPhoneNumber; }
    void setUserPhoneNumInfoList(QList<UserPhoneNumInfo*>* userPhoneNumInfoList){ this->userPhoneNumInfoList = userPhoneNumInfoList; }
    void setUserLastLogin(QString userLastLogin)                                { this->userLastLogin = userLastLogin; }
    void setUserNumOfPhoneNumber(int num)                                       { this->userNumOfPhoneNumber = num; }
    void setUserCreateTime(QString date)                                        { this->userCreateTime = date; }
    void updateUserLastLogin();
    QString getUserId();
    QString getUserPw();
    QString getUserPhoneNumber();
    QList<UserPhoneNumInfo*>* getUserPhoneNumInfoList();
    int getUserNumOfPhoneNumber();
    QString getUserLastLogin();
    QString getUserCreateTime();
};

#endif // USERACCOUNT_H
