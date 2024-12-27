#include "../../../../src_h/account_h/findPassword.h"
#include "../../../../src_h/db_h/db.h"

/* constructor */
FindPassword::FindPassword(){

}

QString FindPassword::findPw(QString userId){
    Db *db = new Db();
    QString pw = db->findUserPw(userId);
    db->close();

    return pw;
}

void FindPassword::reset(QLineEdit* input, QLabel* lbl){
    input->setText("");
    lbl->setText("");
}
