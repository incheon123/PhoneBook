#ifndef PROFILE_H
#define PROFILE_H

#include <QLineEdit>

#include <QWidget>

class Profile : public QWidget{
    Q_OBJECT

public slots:
    void updateNumOfPhoneNumber(QLineEdit*, int);

public:
    explicit Profile(QWidget *parent = nullptr);

private:
    QString userId;
    QString userPw;
    QString userPhoneNumber;
    int userNumOfPhoneNumber;
    QString userCreateTime;
private:

public:
    void init(QLineEdit*, QLineEdit*,QLineEdit*,QLineEdit*,QLineEdit*);
    bool modifyPw(QString pw);
    void setUserId(QString str);
    void setUserPw(QString str);
    void setUserPhoneNumber(QString str);
    void setUserNumOfPhoneNumber(int str);
    void setUserCreateTime(QString str);

};

#endif // PROFILE_H
