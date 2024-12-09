#include "phonebook.h"
#include "../../../../src_h/db_h/db.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhoneBook w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    qDebug() << db.connectionName();
    return a.exec();
}
