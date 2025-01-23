#include "phonebook.h"
#include "properties.h"
#include <QApplication>

#include "../../../../ui/chat/chatbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(HOST_NAME);
    db.setDatabaseName(DATABASE_NAME);
    db.setUserName(USER_NAME);
    db.setPassword(PASSWORD);

    PhoneBook w;
    w.show();
    return a.exec();
}
