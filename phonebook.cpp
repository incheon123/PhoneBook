#include "phonebook.h"
#include "./ui_phonebook.h"

#include <QDebug>
#include <QtSql/QSqlDatabase>

PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();
}

PhoneBook::~PhoneBook()
{
    delete ui;
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
