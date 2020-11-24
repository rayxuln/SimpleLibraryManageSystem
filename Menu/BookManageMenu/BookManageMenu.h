//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEMENU_H

#include "../ItemListMenu.h"

class BookManageMenu : public ItemListMenu {
public:
    void ShowBooks();

    void Show() override;
    void GenerateMenu() override;
    bool HandleInput(int n) override;

    BookManageMenu();
    ~BookManageMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEMENU_H
