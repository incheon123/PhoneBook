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

void PhoneBook::on_signin_clicked()
{
    db = new Db();
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
    if(db->login(user_id, user_pw).isNull()){
        QMessageBox box;
        box.setText("조회되지 않는 계정입니다");
        box.exec();
        return;
    }

    QSqlQuery sql;
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

    sql.prepare("select * from user where user_id = :userId");
    sql.bindValue(":userId", user_id);
    sql.exec();
    UserAccount* ua = UserAccount::getInstance();
    if(sql.next()){
        ua->setUserId(sql.value(0).toString());
        ua->setUserPw(sql.value(1).toString());
        ua->setUserCreateTime(sql.value(2).toString());
        ua->setUserPhoneNumber(sql.value(3).toString());
        ua->setUserLastLogin(sql.value(4).toString());
        ua->setUserPhoneNumInfoList(list);
        ua->updateUserLastLogin();
        ua->setUserNumOfPhoneNumber(list->size());
    }

    db->close();
    home* h = new home;
    // h->save(this);
    h->setPhoneBook(this);

    this->hide();
    h->show();

    delete list;
    delete u;
    sql.clear();
}

void PhoneBook::on_signup_clicked()
{
    switchPage(SIGNUP);  // to sigin up
}

/* 비밀번호 찾기 버튼 클릭 */
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
        execMsgBox("회원가입 성공하셨습니다");
        /* 화면 전환 */
        switchPage(1);
    }else{
        execMsgBox("회원가입 실패하셨습니다");
        return;
    }

    /* 초기화 */
    signup_userId->setText("");
    signup_phone_number->setText("");
    signup_userPw1->setText("");
    signup_userPw2->setText("");

    delete signup;
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
    emit click_back(1);
}


void PhoneBook::on_signup_back_btn_clicked()
{
    emit click_back(1);
}
