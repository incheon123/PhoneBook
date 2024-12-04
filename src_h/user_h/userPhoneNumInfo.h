#ifndef USERPHONENUMINFO_H
#define USERPHONENUMINFO_H

#include <QWidget>

class UserPhoneNumInfo : public QWidget{
    Q_OBJECT

public:
    UserPhoneNumInfo(){};
    ~UserPhoneNumInfo(){};

private:
    QString owner;
    QString phoneNumUserId;
    QString phoneNumber;
    QString name;
    QString createTime;

private:

public:
    QString getOwner();
    QString getPhoneNumUserId();
    QString getPhoneNumber();
    QString getName();
    QString getCreateTime();

    void setOwner(QString);
    void setPhoneNumUserId(QString);
    void setPhoneNumber(QString);
    void setName(QString);
    void setCreateTime(QString);
};

#endif // USERPHONENUMINFO_H
