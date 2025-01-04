#ifndef LOGOUT_H
#define LOGOUT_H

#include <QWidget>
#include "../../phonebook.h"
#include "../../ui/home/home.h"

class Logout : public QWidget{
    Q_OBJECT

public:                 // method
    void logout(PhoneBook*, home*);
    ~Logout(){};
public:                 // variable
private:                // method
private:                // variable

};

#endif // LOGOUT_H
