#include "phonebook.h"
#include "./ui_phonebook.h"

#include <QDebug>
#include <QSqlQuery>
#include <QUiLoader>
#include <QFile>

const int WIDGET_SIZE = 3;

PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
{
    ui->setupUi(this);
    db = new Db("129.154.51.67", "product", "taekhyun", "1234", 3306);

    QObject::connect(this, &PhoneBook::click_back, this, &PhoneBook::switchPage);
}

PhoneBook::~PhoneBook()
{
    delete ui;
    db->close();
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
    QString user_id = ui->login_userId->text();
    QString user_pw = ui->login_userPw->text();

    qDebug() << user_id << '\n';
    qDebug() << user_id << '\n';

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
    if ( user_id.compare(db->getUserId(user_id)) != 0) {
        // id is correct
        ui->signin_userIdLabel->setText("아이디가 일치하지 않습니다");
        return;
    }
    if ( user_pw.compare(db->getUserPw(user_pw)) != 0) {
        ui->signin_userPwLabel->setText("비밀번호가 일치하지 않습니다");
        return;
    }

    h = new home;
    h->save(this);
    qDebug() << this;

    this->close();
    h->show();

    // switchPage(SIGNIN);  // to home
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
    /* 아이디 중복 체크 */
    QString result = db->getUserId(signup_userId);
    if(!result.isEmpty()){
        ui->signup_user_id_dp_chk_lb->setText("중복되는 아이디입니다");
        duplicateChk = 0;
        return;
    }

    duplicateChk = 1;
    ui->signup_user_id_dp_chk_lb->setText("사용가능한 아이디입니다");
    return;
}

/* 회원가입 유효성 체크 */
void PhoneBook::on_signup_submit_btn_clicked()
{
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
}

void PhoneBook::execMsgBox(QString content){

    QMessageBox mb;
    mb.setText(content);
    mb.exec();

    return;
}


void PhoneBook::on_submit_clicked()
{
    QString userId = ui->findPw_pwInput->text();
    QString findedPw;
    if((findedPw = db->findUserPw(userId)).isNull()){
        ui->findPw_pwLabel->setText("조회되지 않는 아이디입니다");
        return;
    }

    ui->findPw_pwLabel->setText(userId + "의 비밀번호는 " + findedPw + "입니다");
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

