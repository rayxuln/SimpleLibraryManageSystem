//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowerManageBorrowHistoryMenu.h"
#include "../../Manager/MenuManager.h"
#include "../../App.h"
#include "../../Utils.h"

#include <iostream>

void BorrowerManageBorrowHistoryMenu::Show() {
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();
    auto borrowManager = menuManager->GetApp()->GetBorrowManager();

    std::cout<<"请输入编号: "<<std::endl;
    int id;
    std::cin>>id;

    if(!borrowerManager->Has(id))
    {
        std::cout<<"错误的编号！"<<std::endl;
        menuManager->Back();
        return;
    }

    auto &borrower_d = borrowerManager->GetDataRef(id);

    std::cout<<borrower_d.name<<" 的借还历史记录: "<<std::endl;
    for(auto &b:borrower_d.borrowHistory)
    {
        auto &d = borrowManager->GetDataRef(b);
        std::cout<<borrowManager->ToHistoryString(d)<<std::endl;
    }
    std::cout<<std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    menuManager->Back();
}

BorrowerManageBorrowHistoryMenu::BorrowerManageBorrowHistoryMenu() = default;

BorrowerManageBorrowHistoryMenu::~BorrowerManageBorrowHistoryMenu() = default;