#include "../../../../header/account/signUp.h"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent){
    duplicateChk = 0;
}
SignUp::~SignUp(){

}
bool SignUp::validUserId(QString userId, QLabel *label){

    qDebug() << duplicateChk;
    /* 아이디 공백 체크 */
    if(userId.isEmpty()){
        label->setText("아이디를 입력하세요");
        duplicateChk = 0;
        return false;
    }
    /* 아이디 중복 체크 했는지 확인 */
    if(!duplicateChk){
        label->setText("아이디 중복 검사를 하세요");
        return false;
    }

    return true;
}
/* 회원가입 유저 아이디 중복 확인 */
void SignUp::chkDuplicate(QLineEdit* userId, QLabel* lbl)
{
    Db* db = new Db();
    /* 아이디 중복 체크 */

    QString result = db->getUserId(userId->text());
    if(!result.isEmpty()){
        lbl->setText("중복되는 아이디입니다");
        duplicateChk = 0;
        return;
    }

    duplicateChk = 1;
    lbl->setText("사용가능한 아이디입니다");
    db->close();
    return;
}

//signup_pw_chk_lb
/* 비밀번호 공백 체크 */
bool SignUp::validUserPw(QString pw1, QString pw2, QLabel* label){

    if(pw1.isEmpty() || pw2.isEmpty()){
        label->setText("비밀번호를 입력하세요");
        return false;
    }
    /* 비밀번호 이중 확인 체크 */
    if(pw1 != pw2){
        label->setText("비밀번호가 일치하지 않습니다");
        return false;
    }
    label->setText("사용 가능한 비밀번호 입니다");
    return true;
}
/* 전화번호 공백 체크 */
bool SignUp::validUserPhoneNum(QString ph, QLabel* label){
    if(ph.isEmpty()){
        label->setText("전화번호를 입력하세요");
        return false;
    }
    return true;
}
/* 전화번호 체크 */
bool SignUp::chkPhoneNumExists(QString ph, QLabel* label){

    if(!validUserPhoneNum(ph, label)) return false;

    Db* db = new Db();
    QSqlQuery sql;
    sql.prepare("select phone_number from user where phone_number = :phoneNumber");
    sql.bindValue(":phoneNumber", ph);
    sql.exec();
    sql.next();

    bool result = sql.value(0).toString().isEmpty();

    sql.clear();
    db->close();
    /* true는 중복되는 전화번호 없음. */

    if(!result){
        label->setText("가입된 전화번호입니다");
        return false;
    }
    label->setText("사용가능한 전화번호입니다");
    return true;
}
/* 회원가입 수행 */
bool SignUp::signUp(QString userId, QString userPw, QString ph){
    Db* db = new Db();
    bool isSuccess = db->signup(userId, userPw, ph);

    db->close();

    if(isSuccess)   return true;
    return false;
}
