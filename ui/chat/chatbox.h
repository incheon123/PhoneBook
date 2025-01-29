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
    ~ChatBox();
    explicit ChatBox(QWidget *parent = nullptr);
    void receiveMessage(QString message);

private slots:
    void on_pushButton_clicked();

public slots:
    void sendMessage(QString message);

private:
    Ui::ChatBox *ui;
    QListWidget* listWidget;
    QLineEdit* lineEdit;



};

#endif // CHATBOX_H
