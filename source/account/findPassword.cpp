#include "../../../../header/account/findPassword.h"
#include "../../../../header/db/db.h"

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
