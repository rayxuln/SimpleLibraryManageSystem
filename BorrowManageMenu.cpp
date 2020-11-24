//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowManageMenu.h"
#include "BorrowManageBorrowMenu.h"
#include "BorrowManageReturnMenu.h"
#include "MenuManager.h"
#include "App.h"

#include <iostream>

void BorrowManageMenu::GenerateMenu() {
    itemList.emplace_back("借书");
    itemList.emplace_back("还书");
    itemList.emplace_back("查询借阅历史");
    ItemListMenu::GenerateMenu();
}

bool BorrowManageMenu::HandleInput(int n) {
    if(ItemListMenu::HandleInput(n))
        return true;
    switch (n) {
        case 0:
            menuManager->Goto(std::shared_ptr<BorrowManageBorrowMenu>(new BorrowManageBorrowMenu));
            return true;
        case 1:
            menuManager->Goto(std::shared_ptr<BorrowManageReturnMenu>(new BorrowManageReturnMenu));
            return true;
        case 2:
            menuManager->Goto(std::shared_ptr<BorrowManageReturnMenu>(new BorrowManageReturnMenu));
            return true;
    }
    return false;
}

BorrowManageMenu::BorrowManageMenu() {
    title = "借阅";
}

BorrowManageMenu::~BorrowManageMenu() = default;