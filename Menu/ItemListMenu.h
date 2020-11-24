//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_ITEMLISTMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_ITEMLISTMENU_H

#include "Menu.h"

#include <vector>
#include <string>

class ItemListMenu : public Menu {
protected:
    std::vector<std::string> itemList;
    std::string title;
public:
    void ShowTitle();
    void ShowItemList();
    void FetchInput();

    void Show() override;
    virtual void GenerateMenu();
    bool HandleInput(int n) override;

    bool ValidInput(int n) override;

    ItemListMenu();
    ~ItemListMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_ITEMLISTMENU_H
