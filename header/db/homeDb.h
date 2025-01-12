#ifndef HOMEDB_H
#define HOMEDB_H

#include <QWidget>
#include <QSqlQuery>
#include <cstdarg>
#include <vector>

#include "../../ui/window_of_anotherProfile/profileofanother.h"

class HomeDb : public QWidget{
    Q_OBJECT

public:
    HomeDb(){};
    ~HomeDb(){};
public:
    profileOfAnother* getAnotherProfile(QString);
    bool findId(QString owner, QString userId);
    QSqlQuery findId(QString userId);
    void save(QString phoneNumber, QString name, QString userId, QString owner);
    void modify(QString owner, QString name, QString userId);
    bool remove(QString userId, QString owner);
    QSqlQuery getCreatetime(QString owner, QString userId);
private:
    QSqlQuery execQuery(QString, int n, std::vector<QString>, std::vector<QString>);

private:

};

#endif // HOMEDB_H
