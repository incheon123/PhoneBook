#ifndef FINDPASSWORD_H
#define FINDPASSWORD_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class FindPassword : QWidget{
    Q_OBJECT

public:                             // variable

public:                             // method
    FindPassword();
    QString findPw(QString);
    void reset(QLineEdit*, QLabel*);
private:                            //  variable

private:                            //  method
};

#endif // FINDPASSWORD_H
