//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BorrowerManageUpdateMenu.h"
#include "../../Manager/MenuManager.h"
#include "../../App.h"
#include "../../Utils.h"

#include <iostream>

void BorrowerManageUpdateMenu::Show() {
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();

    std::cout<<"请输入编号: "<<std::endl;
    int id;
    std::cin>>id;

    if(!borrowerManager->Has(id))
    {
        std::cout<<"错误的编号！"<<std::endl;
        menuManager->Back();
        return;
    }

    auto &d = borrowerManager->GetDataRef(id);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"请输入姓名("<<d.name<<"): ";
    std::string name;
    getline(std::cin, name);
    if(!name.empty()) d.name = name;

    std::cout<<"更新成功！"<<std::endl;

    borrowerManager->Save();

    menuManager->Back();
}

BorrowerManageUpdateMenu::BorrowerManageUpdateMenu() = default;

BorrowerManageUpdateMenu::~BorrowerManageUpdateMenu() = default;
