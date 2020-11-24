//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_MAINMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_MAINMENU_H

#include "ItemListMenu.h"

class MainMenu : public ItemListMenu {
public:

    void GenerateMenu() override;
    bool HandleInput(int n) override;

    MainMenu();
    ~MainMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_MAINMENU_H
