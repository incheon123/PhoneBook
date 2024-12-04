#include "phonebook.h"
#include "./ui_phonebook.h"

#include "../../../../src_h/user_h/userAccount.h"

#include <QDebug>
#include <QSqlQuery>
#include <QUiLoader>
#include <QFile>

const int WIDGET_SIZE = 3;

UserAccount* UserAccount::instance = nullptr;

PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
{
    ui->setupUi(this);
    // home h;
    // h.save(this);

    QObject::connect(this, &PhoneBook::click_back, this, &PhoneBook::switchPage);
}

PhoneBook::~PhoneBook()
{
    delete ui;
    // db->close();
}

// PhoneBook getPhoneBook(){

// }

/*
    1p is sigin-in
    2p is forget account
    3p is sign-up
*/
void PhoneBook::switchPage(int p)
{
    qDebug() << "switchPage()";
    QStackedWidget *stack = ui->stackedWidget;

    if(p >= 1 && p <= WIDGET_SIZE){
        stack->setCurrentIndex(p-1);
    }

}

void PhoneBook::on_signin_clicked()
{
    db = new Db();
    QString user_id = ui->login_userId->text();
    QString user_pw = ui->login_userPw->text();

    qDebug() << user_id << '\n';
    qDebug() << user_pw << '\n';

    /* 데이터 베이스에 있는 계정과 비밀번호와 비교 */
    ui->signin_userIdLabel->setText("");
    ui->signin_userPwLabel->setText("");
    if(user_id.isEmpty()){
        ui->signin_userIdLabel->setText("아이디를 입력해주세요");
        return;
    }
    if(user_pw.isEmpty()){
        ui->signin_userPwLabel->setText("비밀번호를 입력해주세요");
        return;
    }
    if(db->login(user_id, user_pw).isNull()){
        QMessageBox box;
        box.setText("조회되지 않는 계정입니다");
        box.exec();
        return;
    }

    QSqlQuery sql;
    sql.prepare("select * from user where user_id = :userId");
    sql.bindValue(":userId", user_id);
    sql.exec();

    UserAccount* ua = UserAccount::getInstance();
    if(sql.next()){
        ua->setUserId(sql.value(0).toString());
        ua->setUserPw(sql.value(1).toString());
        ua->setUserPhoneNumber(sql.value(3).toString());
        ua->setUserLastLogin(sql.value(4).toString());
    }

    sql.prepare("select pn.number, pn.name, pn.user_id, pn.create_time from user u, phone_number pn where u.user_id = :userId and  u.user_id = pn.owner;");
    sql.bindValue(":userId", user_id);
    sql.exec();

    QList<UserPhoneNumInfo *>* list = new QList<UserPhoneNumInfo*>;
    UserPhoneNumInfo* u;
    while(sql.next()){
        u = new UserPhoneNumInfo;
        u->setPhoneNumber(sql.value(0).toString());        // 전화번호
        u->setName(sql.value(1).toString());               // 별칭
        u->setPhoneNumUserId(sql.value(2).toString());     // 어떤 아이디의 전화번호인지
        u->setCreateTime(sql.value(3).toString());          // 생성 일자
        list->append(u);
    }
    ua->setUserPhoneNumInfoList(list);
    ua->updateUserLastLogin();

    db->close();
    h = new home;
    h->save(this);
    qDebug() << this;

    this->close();
    h->show();

    delete list;
    delete u;
    sql.clear();
}

void PhoneBook::on_signup_clicked()
{
    qDebug() << "signup";
    switchPage(SIGNUP);  // to sigin up
}

/* 비밀번호 찾기 버튼 클릭 */
void PhoneBook::on_forgetAccount_clicked()
{
    qDebug() << "forgetAccount";
    switchPage(FIND_ACCOUNT);  // to find account
}

/* 아이디 유효성 체크 */
bool PhoneBook::validUserId(){
    ui->signup_user_id_dp_chk_lb->setText("");

    /* 아이디 공백 체크 */
    signup_userId = ui->signup_user_id_input->text();
    if(signup_userId.isEmpty()){
        ui->signup_user_id_dp_chk_lb->setText("아이디를 입력하세요");
        duplicateChk = 0;
        return false;
    }
    /* 아이디 중복 체크 했는지 확인 */
    if(!duplicateChk){
        ui->signup_user_id_dp_chk_lb->setText("아이디 중복 검사를 하세요");
        duplicateChk = 0;
        return false;
    }

    return true;
}

/* 비밀번호 유효성 체크 */
bool PhoneBook::validUserPw(){
    signup_userPw = ui->signup_user_pw_input->text();
    QString signup_userPw2 = ui->signup_user_pw_double_input->text();

    if(signup_userPw.isEmpty() || signup_userPw2.isEmpty()){
        ui->signup_pw_chk_lb->setText("비밀번호를 입력하세요");
        return false;
    }
    /* 비밀번호 이중 확인 체크 */
    if(signup_userPw != signup_userPw2){

        ui->signup_pw_chk_lb->setText("비밀번호가 일치하지 않습니다");

        ui->signup_user_pw_input->setText("");
        ui->signup_user_pw_double_input->setText("");
        return false;
    }

    ui->signup_pw_chk_lb->setText("사용 가능한 비밀번호 입니다");
    return true;
};

/* 전화번호 유효성 체크 */
bool PhoneBook::validUserPhoneNum(){
    if(signup_phone_number.isEmpty()){
        ui->signup_phone_number_chk_lbl->setText("전화번호를 입력하세요");
        return false;
    }

    ui->signup_phone_number_chk_lbl->setText("사용 가능한 전화번호 입니다");
    return true;
};
/* 회원가입 유저 아이디 중복 확인 */
void PhoneBook::on_signup_user_id_dp_chk_btn_clicked()
{
    db = new Db();
    /* 아이디 중복 체크 */
    signup_userId = ui->signup_user_id_input->text();
    qDebug() << signup_userId << "입니다";
    QString result = db->getUserId(signup_userId);
    if(!result.isEmpty()){
        ui->signup_user_id_dp_chk_lb->setText("중복되는 아이디입니다");
        duplicateChk = 0;
        return;
    }

    duplicateChk = 1;
    ui->signup_user_id_dp_chk_lb->setText("사용가능한 아이디입니다");
    db->close();
    return;
}

/* 회원가입 유효성 체크 */
void PhoneBook::on_signup_submit_btn_clicked()
{
    db = new Db();
    signup_userId = ui->signup_user_id_input->text();
    signup_phone_number = ui->signup_user_phone_number_input->text();

    /* 회원가입 로직 */

    /* 아이디 중복 체크 */
    if(!validUserId()) return;

    /* 비밀번호 공백 체크 */
    if(!validUserPw()) return;

    /* 전화번호 공백 체크 */
    if(!validUserPhoneNum()) return;

    /* 회원가입 수행 */
    bool result = db->signup(signup_userId, signup_userPw, signup_phone_number);

    if(result)  execMsgBox("회원가입 성공하셨습니다");
    else        execMsgBox("회원가입 실패하셨습니다");
    db->close();
}

void PhoneBook::execMsgBox(QString content){

    QMessageBox mb;
    mb.setText(content);
    mb.exec();

    return;
}


void PhoneBook::on_submit_clicked()
{
    db = new Db();
    QString userId = ui->findPw_pwInput->text();
    QString findedPw;
    if((findedPw = db->findUserPw(userId)).isNull()){
        ui->findPw_pwLabel->setText("조회되지 않는 아이디입니다");
        return;
    }

    ui->findPw_pwLabel->setText(userId + "의 비밀번호는 " + findedPw + "입니다");
    db->close();
    return;
}


void PhoneBook::on_find_account_back_btn_clicked()
{
    qDebug() << "뒤로가기(비밀번호찾기)";
    emit click_back(1);
}


void PhoneBook::on_signup_back_btn_clicked()
{
    qDebug() << "뒤로가기(회원가입)";
    emit click_back(1);
}

