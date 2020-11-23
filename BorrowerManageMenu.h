//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEMENU_H

#include "ItemListMenu.h"

class BorrowerManageMenu : public ItemListMenu {
public:
    void ShowBorrowers();

    void Show() override;
    void GenerateMenu() override;
    bool HandleInput(int n) override;

    BorrowerManageMenu();
    ~BorrowerManageMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEMENU_H
