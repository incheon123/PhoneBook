#ifndef HOME_H
#define HOME_H

#include <QWidget>

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
private:
    Ui::home *ui;

private:
};

#endif // HOME_H
