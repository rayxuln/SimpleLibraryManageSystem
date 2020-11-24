//
// Created by Raymond_Lx on 2020/11/24.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGERETURNMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGERETURNMENU_H

#include "Menu.h"

class BorrowManageReturnMenu : public Menu {
public:

    void Show() override;

    BorrowManageReturnMenu();
    ~BorrowManageReturnMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGERETURNMENU_H
