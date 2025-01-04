#include <QMessageBox>

void error(QString errMsg){
    QMessageBox box;
    box.setText(errMsg);
    box.exec();

    return;
}
