#ifndef HOMEDB_H
#define HOMEDB_H

#include <QWidget>
#include <QSqlQuery>
#include <cstdarg>

#include "../../ui/window_of_anotherProfile/profileofanother.h"

class HomeDb : public QWidget{
    Q_OBJECT

public:
    HomeDb(){};
    ~HomeDb(){};
public:
    profileOfAnother* getAnotherProfile(QString);
private:
    QSqlQuery sqlSelect(QString, int n, ...);
    void sqlUpdate();
    void sqlDelete();
private:

};

#endif // HOMEDB_H
