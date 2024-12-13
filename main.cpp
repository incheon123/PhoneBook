#include "phonebook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhoneBook w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("129.154.51.67");
    db.setDatabaseName("product");
    db.setUserName("taekhyun");
    db.setPassword("1234");
    qDebug() << db.connectionName();
    return a.exec();
}
