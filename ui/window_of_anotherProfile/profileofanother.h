#ifndef PROFILEOFANOTHER_H
#define PROFILEOFANOTHER_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class profileOfAnother;
}

class profileOfAnother : public QWidget
{
    Q_OBJECT

public:
    explicit profileOfAnother(QWidget *parent = nullptr);
    ~profileOfAnother();

private:
    Ui::profileOfAnother *ui;
    QLineEdit* userIdInput;
    QLineEdit* userPhoneInput;
    QLineEdit* userNumOfPhoneInput;
    QLineEdit* userCreateTimeInput;
    QString userId;
    QString userPhone;
    QString userNumOfPhoneNumber;
    QString userCreateTime;

public:
    QString getUserId(){return this->userId;}
    QString getUserPhone(){return this->userPhone;}
    QString getUserNumOfPhoneNumber(){return this->userNumOfPhoneNumber;}
    QString getUserCreateTime(){return this->userCreateTime;}
    void setUserId(QString userId){
        this->userId = userId;
        userIdInput->setText(this->userId);
    }
    void setUserPhone(QString userPhone){
        this->userPhone = userPhone;
        userPhoneInput->setText(this->userPhone);
    }
    void setUserNumOfPhoneNumber(QString userNumOfPhoneNumber){
        this->userNumOfPhoneNumber = userNumOfPhoneNumber;
        userNumOfPhoneInput->setText(this->userNumOfPhoneNumber);
    }
    void setUserCreateTime(QString userCreateTime){
        this->userCreateTime = userCreateTime;
        userCreateTimeInput->setText(this->userCreateTime);
    }
};

#endif // PROFILEOFANOTHER_H
