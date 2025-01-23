#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class ChatBox;
}

class ChatBox : public QWidget
{
    Q_OBJECT

public:
    explicit ChatBox(QWidget *parent = nullptr);
    ~ChatBox();

private slots:
    void on_pushButton_clicked();

private:
    void sendMessage(QString message);

private:
    Ui::ChatBox *ui;
    QListWidget* listWidget;
    QLineEdit* lineEdit;
};

#endif // CHATBOX_H
