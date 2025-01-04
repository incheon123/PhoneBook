#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTableWidget>
#include <QListWidget>
#include <QLabel>

#include "../../../../header/db/db.h"
#include "../../../../header/profile/profile.h"

class PhoneBook;

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
    home* getUi();
    Ui::home *ui;
    void setPhoneBook(PhoneBook* ph){ this->ph = ph; }

private slots:
    void on_index_deleteBtn_clicked();

    void on_index_saveBtn_clicked();

    void on_index_table_cellClicked(int row, int column);
    void showContextMenu(const QPoint &pos);
    void on_index_sideMenu_itemClicked(QListWidgetItem *item);

    void on_profile_modify_btn_clicked();

signals:
    void on_index_table_customContextMenuRequested(const QPoint &pos);
    void decreaseNumOfPhoneNumber(QLineEdit*, int num);
    void increaseNumOfPhoneNumber(QLineEdit*, int num);

private:
    PhoneBook* ph;
    Profile* profile;
    QTableWidget* table;
    QListWidget* list;
    QLabel* welcomeLabel;
    QLabel* lastLoginDate;
    Db* db;
    UserAccount* user;
    QString oldPhoneNumber;
    QString oldName;
    QString oldUserId;
    QString newPhoneNumber;
    QString newName;
    QString newUserId;
    int selectedRow;

private:
    void msg(QString);
    void loadUser();
    bool findId(QString, QString);
    void save(QString, QString, QString, QString);
    void modify(QString, QString, QString);
    bool remove(QString, QString);
    void insertIntoTable(QString, QString, QString, QString);
    void modifyTable(QString, QString);
    void removeRowInTable(int row);
    /* 임시 method */
    // void printSelectedRows();
};

#endif // HOME_H
