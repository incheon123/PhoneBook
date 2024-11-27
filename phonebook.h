#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <QSql>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class PhoneBook;
}
QT_END_NAMESPACE

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PhoneBook *ui;
    QSqlDatabase db;
    void switchPage();

private:
    QString id = "opportunity13";
    QString pw = "rlghlek153@";
};
#endif // PHONEBOOK_H
