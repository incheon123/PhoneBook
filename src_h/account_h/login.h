#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QLineEdit>
#include <QPushButton>

class Login : public QObject{
    Q_OBJECT

public:
    Login();

private:
    void login();

private:
    QLineEdit userIdLine;
    QLineEdit userPwLine;
    QPushButton loginBtn;

};
#endif // LOGIN_H
