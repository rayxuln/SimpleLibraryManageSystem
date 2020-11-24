//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowManageHistoryMenu.h"
#include "../BookManageMenu/BookManageAddMenu.h"
#include "../BookManageMenu/BookManageUpdateMenu.h"
#include "../BookManageMenu/BookManageDeleteMenu.h"
#include "../../Manager/MenuManager.h"
#include "../../App.h"

#include <iostream>

void BorrowManageHistoryMenu::Show() {
    ShowTitle();

    ShowHistory();

    itemList.clear();
    GenerateMenu();
    ShowItemList();

    FetchInput();
}

void BorrowManageHistoryMenu::GenerateMenu() {
    ItemListMenu::GenerateMenu();
}

BorrowManageHistoryMenu::BorrowManageHistoryMenu() {
    title = "借阅历史记录";
}

void BorrowManageHistoryMenu::ShowHistory() {
    auto borrowManager = menuManager->GetApp()->GetBorrowManager();
    auto bookManager = menuManager->GetApp()->GetBookManager();
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();

    for(auto &d:borrowManager->Data())
    {
        std::cout<<borrowManager->ToHistoryString(d);
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
}

BorrowManageHistoryMenu::~BorrowManageHistoryMenu() = default;