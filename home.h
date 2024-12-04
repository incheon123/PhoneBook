#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTableWidget>
#include <QListWidget>
#include <QLabel>

#include "../../../../src_h/db_h/db.h"

namespace Ui {
class home;
}

class home : public QWidget
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

public:
    void save(QWidget* widget);
    void openHome();
    void closeHome();
private slots:

    void on_index_addBtn_clicked();

    void on_index_deleteBtn_clicked();

    void on_index_updateBtn_clicked();

    void on_index_saveBtn_clicked();

signals:
    void addBtn_clicked();

private:
    Ui::home *ui;
    QTableWidget* table;
    QListWidget* list;
    QLabel* welcomeLabel;
    QLabel* lastLoginDate;
    Db* db;
    UserAccount* user;

private:
    void errorMsg(QString);
    void msg(QString);
    void loadUser();
};

#endif // HOME_H
