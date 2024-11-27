#include "phonebook.h"
#include "./ui_phonebook.h"

#include <QDebug>
#include <QSqlQuery>

PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    qDebug() << db.drivers();

    db.setHostName("129.154.51.67");
    db.setDatabaseName("product");
    db.setUserName("taekhyun");
    db.setPassword("1234");
    db.setPort(3306);

    db.open();

    QSqlQuery sql;
    sql.exec("select * from food;");

    if(sql.exec())
    {
        qDebug() << "success sql executing";

        while (sql.next())
        {
            // Retrieve Values from select statement
            QString inputWord = sql.value(0).toString();
            QString wordDefinition = sql.value(1).toString();

            // Display values
            qDebug() << wordDefinition;
        }
    } else {
        qDebug() << "query failed to execute";
    }
}

PhoneBook::~PhoneBook()
{
    delete ui;
    db.close();
}

void PhoneBook::switchPage()
{
    QStackedWidget *stack = ui->stackedWidget;
    if (stack->currentIndex() == 0) {
        stack->setCurrentIndex(1);
    } else if (stack->currentIndex() == 1) {
        stack->setCurrentIndex(2);
    } else {
        stack->setCurrentIndex(0);
    }
}

void PhoneBook::on_pushButton_clicked()
{
    QString user_id = ui->user_id->text();
    QString user_pw = ui->user_pw->text();

    if (user_id == id) {
        // id is correct

        if (user_pw == pw) {
            //pw is correct
        }
    }

    switchPage();
}
