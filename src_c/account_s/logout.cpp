#include "../../../../src_h/account_h/logout.h"

void Logout::logout(PhoneBook* ph, home* home){
    // ph->setWindowFlags(Qt::Window);
    // ph->setAttribute(Qt::WA_DeleteOnClose, true);
    // ph->setVisible(true);
    ph->show();
    home->close();
}
