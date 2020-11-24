//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowManageHistoryMenu.h"
#include "BookManageAddMenu.h"
#include "BookManageUpdateMenu.h"
#include "BookManageDeleteMenu.h"
#include "MenuManager.h"
#include "App.h"

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
        auto &borrower_d = borrowerManager->GetDataRef(d.borrowerId);
        std::cout<<d.date<<", "<<borrower_d.name<<" "<<(d.action==0?"借了 ":"还了 ");
        for(size_t i=0; i<d.book.size(); ++i)
        {
            auto &book_d = bookManager->GetDataRef(d.book[i].first);
            std::cout<<d.book[i].second<<"本《"<<book_d.name<<"》";
            if(i < d.book.size()-1)
                std::cout<<",";
        }
        std::cout<<std::endl<<std::endl;
    }
}

BorrowManageHistoryMenu::~BorrowManageHistoryMenu() = default;