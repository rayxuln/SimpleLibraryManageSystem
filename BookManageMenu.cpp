//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BookManageMenu.h"
#include "BookManageAddMenu.h"
#include "BookManageUpdateMenu.h"
#include "BookManageDeleteMenu.h"
#include "MenuManager.h"
#include "App.h"

#include <iostream>

void BookManageMenu::Show() {
    ShowTitle();

    ShowBooks();

    itemList.clear();
    GenerateMenu();
    ShowItemList();

    FetchInput();
}

void BookManageMenu::GenerateMenu() {
    itemList.emplace_back("添加");
    itemList.emplace_back("修改");
    itemList.emplace_back("删除");
    ItemListMenu::GenerateMenu();
}

bool BookManageMenu::HandleInput(int n) {
    if(ItemListMenu::HandleInput(n))
        return true;
    switch (n) {
        case 0:
            menuManager->Goto(std::shared_ptr<BookManageAddMenu>(new BookManageAddMenu()));
            return true;
        case 1:
            menuManager->Goto(std::shared_ptr<BookManageUpdateMenu>(new BookManageUpdateMenu()));
            return true;
        case 2:
            menuManager->Goto(std::shared_ptr<BookManageDeleteMenu>(new BookManageDeleteMenu()));
            return true;
    }
    return false;
}

BookManageMenu::BookManageMenu() {
    title = "图书管理";
}

void BookManageMenu::ShowBooks() {
    auto bookManager = menuManager->GetApp()->GetBookManager();
    const std::string column_wide = "--------------------------------";

    std::cout<<std::endl;
    std::cout<<"编号\t\t\t\t名称\t\t\t\t作者\t\t\t\t数量\t\t\t\t借出"<<std::endl;
    std::cout<<column_wide<<column_wide<<column_wide<<column_wide<<column_wide<<std::endl;
    for(auto &d:bookManager->Data())
    {
        std::cout<<d.id;
        std::cout<<"\t\t\t\t";
        std::cout<<d.name;
        std::cout<<"\t\t\t\t";
        std::cout<<d.author;
        std::cout<<"\t\t\t\t";
        std::cout<<d.num;
        std::cout<<"\t\t\t\t";
        std::cout<<d.lent;
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

BookManageMenu::~BookManageMenu() = default;
