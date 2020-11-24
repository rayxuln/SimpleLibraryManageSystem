//
// Created by Raymond_Lx on 2020/11/24.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEBORROWINGMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEBORROWINGMENU_H

#include "Menu.h"

class BorrowerManageBorrowingMenu : public Menu {
public:

    void Show() override;

    BorrowerManageBorrowingMenu();
    ~BorrowerManageBorrowingMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEBORROWINGMENU_H
