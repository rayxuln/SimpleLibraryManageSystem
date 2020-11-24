//
// Created by Raymond_Lx on 2020/11/24.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEBORROWMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEBORROWMENU_H

#include "../Menu.h"

class BorrowManageBorrowMenu : public Menu {
public:

    void Show() override;

    BorrowManageBorrowMenu();
    ~BorrowManageBorrowMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEBORROWMENU_H
