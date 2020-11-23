//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BorrowerManageAddMenu.h"
#include "MenuManager.h"
#include "App.h"
#include "Utils.h"

#include <iostream>

void BorrowerManageAddMenu::Show() {
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"请输入姓名: ";
    std::string name;
    getline(std::cin, name);

    borrowerManager->Add(name);
    std::cout<<"添加成功！"<<std::endl;

    borrowerManager->Save();

    menuManager->Back();
}

BorrowerManageAddMenu::BorrowerManageAddMenu() = default;

BorrowerManageAddMenu::~BorrowerManageAddMenu() = default;
