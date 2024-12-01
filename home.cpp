#include "home.h"
#include "ui_home.h"
#include <../../../../../phone/phonebook.h>

#include <QUiLoader>
#include <QFile>
#include <QVBoxLayout>

home::home(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::home)
{
    ui->setupUi(this);

}

home::~home()
{
    delete ui;
}

void home::save(QWidget* widget){
    QUiLoader loader;
    QFile file("C:\\Users\\oppor\\Documents\\phone\\home.ui");
    file.open(QFile::ReadOnly);

    QWidget *myWidget = loader.load(&file, widget);
    file.close();

    // QVBoxLayout *layout = new QVBoxLayout;
    // layout->addWidget(myWidget);
    // setLayout(layout);

}
void home::openHome(){

}
void home::closeHome(){

}
