//
// Created by Raymond_Lx on 2020/11/24.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEMENU_H

#include "../ItemListMenu.h"

class BorrowManageMenu : public ItemListMenu {
public:
    void GenerateMenu() override;
    bool HandleInput(int n) override;

    BorrowManageMenu();
    ~BorrowManageMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEMENU_H
