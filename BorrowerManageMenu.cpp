//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BorrowerManageMenu.h"
#include "BorrowerManageAddMenu.h"
#include "BorrowerManageUpdateMenu.h"
#include "BorrowerManageDelete.h"
#include "MenuManager.h"
#include "App.h"

#include <iostream>

void BorrowerManageMenu::ShowBorrowers() {
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();
    const std::string column_wide = "--------------------------------";

    std::cout<<std::endl;
    std::cout<<"编号\t\t\t\t姓名"<<std::endl;
    std::cout<<column_wide<<column_wide<<std::endl;
    for(auto &d:borrowerManager->Data())
    {
        std::cout<<d.id;
        std::cout<<"\t\t\t\t";
        std::cout<<d.name;
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

void BorrowerManageMenu::Show() {
    ShowTitle();

    ShowBorrowers();

    itemList.clear();
    GenerateMenu();
    ShowItemList();

    FetchInput();
}

void BorrowerManageMenu::GenerateMenu() {
    itemList.emplace_back("添加");
    itemList.emplace_back("修改");
    itemList.emplace_back("删除");
    itemList.emplace_back("查询借还历史");
    itemList.emplace_back("查询在借图书");
    ItemListMenu::GenerateMenu();
}

bool BorrowerManageMenu::HandleInput(int n) {
    if(ItemListMenu::HandleInput(n))
        return true;
    switch (n) {
        case 0:
            menuManager->Goto(std::shared_ptr<BorrowerManageAddMenu>(new BorrowerManageAddMenu()));
            return true;
        case 1:
            menuManager->Goto(std::shared_ptr<BorrowerManageUpdateMenu>(new BorrowerManageUpdateMenu()));
            return true;
        case 2:
            menuManager->Goto(std::shared_ptr<BorrowerManageDelete>(new BorrowerManageDelete()));
            return true;
        case 3:
            return true;
        case 4:
            return true;
    }
    return false;
}

BorrowerManageMenu::BorrowerManageMenu() {
    title = "借阅者管理";
}

BorrowerManageMenu::~BorrowerManageMenu() = default;
