//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowerManageBorrowingMenu.h"
#include "MenuManager.h"
#include "App.h"
#include "Utils.h"

#include <iostream>

void BorrowerManageBorrowingMenu::Show() {
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();
    auto borrowManager = menuManager->GetApp()->GetBorrowManager();
    auto bookManager = menuManager->GetApp()->GetBookManager();

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

    std::cout<<borrower_d.name<<" 正在借阅的书籍: "<<std::endl;
    for(auto &b:borrower_d.borrowing)
    {
        auto &book_d = bookManager->GetDataRef(b.first);
        auto book_num = b.second;
        std::cout<<"《"<<book_d.name<<"》"<<book_num<<"本"<<std::endl;
    }
    std::cout<<std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    menuManager->Back();
}

BorrowerManageBorrowingMenu::BorrowerManageBorrowingMenu() = default;

BorrowerManageBorrowingMenu::~BorrowerManageBorrowingMenu() = default;