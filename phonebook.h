#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QLineEdit>

#include "src_h/db_h/db.h"
#include "home.h"

#define SIGNIN 1
#define FIND_ACCOUNT 2
#define SIGNUP 3

QT_BEGIN_NAMESPACE
namespace Ui {
class PhoneBook;
}
QT_END_NAMESPACE

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

public:
    Db *db;
    home *h;

public:
    PhoneBook getPhoneBook();

signals:
    void click_back(int p);

private slots:
    void on_signin_clicked();

    void on_signup_clicked();

    void on_forgetAccount_clicked();

    void on_signup_user_id_dp_chk_btn_clicked();

    void on_signup_submit_btn_clicked();

    void on_submit_clicked();

    void on_find_account_back_btn_clicked();    // back

    void on_signup_back_btn_clicked();  // back

private:
    Ui::PhoneBook *ui;

    QString id = "opportunity13";
    QString pw = "rlghlek153@";
    QLineEdit* signup_userId;
    QLineEdit* signup_userPw;
    QLineEdit* signup_userChkPw;
    QLineEdit* signup_phone_number;
    bool duplicateChk = 0;

private:
    void switchPage(int p);
    bool validUserId();
    bool validUserPw();
    bool validUserPhoneNum();
    void execMsgBox(QString content);
    bool chkPhoneNumExists(QString phoneNumber);
};
#endif // PHONEBOOK_H
