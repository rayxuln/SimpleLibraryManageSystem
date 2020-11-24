//
// Created by Raymond_Lx on 2020/11/24.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEHISTORYMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEHISTORYMENU_H

#include "ItemListMenu.h"

class BorrowManageHistoryMenu : public ItemListMenu {
public:
    void ShowHistory();

    void Show() override;
    void GenerateMenu() override;

    BorrowManageHistoryMenu();
    ~BorrowManageHistoryMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGEHISTORYMENU_H
