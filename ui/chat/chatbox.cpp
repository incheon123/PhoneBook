#include "chatbox.h"
#include "ui_chatbox.h"

#include <QListWidgetItem>

ChatBox::ChatBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatBox)
{
    /* 텍스트가 실릴 리스트위젯 */
    listWidget = ui->listWidget;
    lineEdit = ui->lineEdit;
    ui->setupUi(this);
}

ChatBox::~ChatBox()
{
    delete ui;
}

void ChatBox::sendMessage(QString message){

    QListWidgetItem* item;
    item->setText(message);

    listWidget->setItemWidget(item, this);

}

void ChatBox::on_pushButton_clicked()
{

    sendMessage(lineEdit->text());
}

