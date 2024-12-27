#include "phonebook.h"
#include "./ui_phonebook.h"

#include "../../../../src_h/user_h/userAccount.h"
#include "../../../../home.h"

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

    QObject::connect(this, &PhoneBook::click_back, this, &PhoneBook::switchPage);
    signup = new SignUp();
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
    QStackedWidget *stack = ui->stackedWidget;

    if(p >= 1 && p <= WIDGET_SIZE){
        stack->setCurrentIndex(p-1);
    }
}
#include "../../../../src_h/account_h/login.h"
/* login  */
void PhoneBook::on_signin_clicked()
{
    Login *login = new Login();
    QString user_id = ui->login_userId->text();
    QString user_pw = ui->login_userPw->text();

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

    /* 로그인 */
    login->login(user_id, user_pw);

    /* 만약 로그인 실패시 */
    if(!login->result()){
        // if false
        alertMsgBox("조회되지 않는 계정입니다");
        return;
    }

    home* const h = createHome();

    h->setPhoneBook(this);
    this->hide();
    h->show();

    delete login;
}
/* go to signup page */
void PhoneBook::on_signup_clicked()
{
    switchPage(SIGNUP);  // to sigin up
}

/* go to find-account page */
void PhoneBook::on_forgetAccount_clicked()
{
    switchPage(FIND_ACCOUNT);  // to find account
}
void PhoneBook::on_signup_user_id_dp_chk_btn_clicked(){
    signup->chkDuplicate(ui->signup_user_id_input, ui->signup_user_id_dp_chk_lb);
}
#include "../../../../src_h/account_h/signUp.h"
/* 회원가입 유효성 체크 */
void PhoneBook::on_signup_submit_btn_clicked()
{
    signup_userId       = ui->signup_user_id_input;
    signup_userPw1       = ui->signup_user_pw_input;
    signup_userPw2    = ui->signup_user_pw_double_input;
    signup_phone_number = ui->signup_user_phone_number_input;

    /* ******************************************회원가입****************************************** */
    /* 아이디 중복 체크 */
    if(!signup->validUserId(signup_userId->text(), ui->signup_user_id_dp_chk_lb)) return;

    /* 비밀번호 체크 */
    if(!signup->validUserPw(signup_userPw1->text(), signup_userPw2->text(), ui->signup_pw_chk_lb)){
        ui->signup_user_pw_input->setText("");
        ui->signup_user_pw_double_input->setText("");
        return;
    }

    /* 전화번호 체크 */
    if(!signup->chkPhoneNumExists(signup_phone_number->text(), ui->signup_phone_number_chk_lbl)){
        ui->signup_user_phone_number_input->setText("");
        return;
    }

    /* 회원가입 수행 */
    bool result = signup->signUp(signup_userId->text(), signup_userPw1->text(), signup_phone_number->text());

    /* ***************************************************************************************** */

    if(result) {
        alertMsgBox("회원가입 성공하셨습니다");
        /* 화면 전환 */
        switchPage(1);
    }else{
        alertMsgBox("회원가입 실패하셨습니다");
        return;
    }

    /* 초기화 */
    signup_userId->setText("");
    signup_phone_number->setText("");
    signup_userPw1->setText("");
    signup_userPw2->setText("");

    delete signup;
}

void PhoneBook::alertMsgBox(QString content){

    QMessageBox mb;
    mb.setWindowTitle("경고!");
    mb.setText(content);
    mb.exec();

    return;
}
#include "../../../../src_h/account_h/findPassword.h"
/* find pw */
void PhoneBook::on_submit_clicked()
{
    FindPassword fp;
    QString userId = ui->findPw_pwInput->text();
    QString findedPw = fp.findPw(userId);

    if(findedPw.isNull()){
        ui->findPw_pwLabel->setText("조회되지 않는 아이디입니다");
        return;
    }

    ui->findPw_pwLabel->setText(userId + "의 비밀번호는 " + findedPw + "입니다");

    return;
}


void PhoneBook::on_find_account_back_btn_clicked()
{
    FindPassword fp;
    fp.reset(ui->findPw_pwInput, ui->findPw_pwLabel);

    emit click_back(1);
}


void PhoneBook::on_signup_back_btn_clicked()
{
    emit click_back(1);
}
