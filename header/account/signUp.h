#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QLabel>
#include <QSqlQuery>
#include <QLineEdit>

#include "../../../../header/db/db.h"

class SignUp : public QWidget{
    Q_OBJECT

signals:

private:                            //  variable
    inline static int duplicateChk = 0;
private:                            //  method

public:                             // variable

public:                             // method
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    /* 아이디 유효성 체크 */
    bool validUserId(QString, QLabel*);
    /* 아이디 중복 확인 */
    void chkDuplicate(QLineEdit*, QLabel*);
    /* 비밀번호 공백 체크 */
    bool validUserPw(QString, QString, QLabel*);
    /* 전화번호 공백 체크 */
    bool validUserPhoneNum(QString, QLabel*);
    /* 전화번호 체크 */
    bool chkPhoneNumExists(QString phoneNum, QLabel*);
    /* 회원가입 수행 */
    bool signUp(QString, QString, QString);
};

#endif // SIGNUP_H
