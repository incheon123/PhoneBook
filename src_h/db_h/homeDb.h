#ifndef HOMEDB_H
#define HOMEDB_H

#include <QWidget>

#include "../../../../profileofanother.h"

class HomeDb : public QWidget{
    Q_OBJECT

public:
    HomeDb(){};
    ~HomeDb(){};
public:
    profileOfAnother* getAnotherProfile(QString);
private:
    void sqlSelect();
    void sqlUpdate();
    void sqlDelete();
private:

};

#endif // HOMEDB_H
