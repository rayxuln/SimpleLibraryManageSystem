//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BorrowerManageDelete.h"
#include "MenuManager.h"
#include "App.h"
#include "Utils.h"

#include <iostream>

void BorrowerManageDelete::Show() {
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

    borrowerManager->Remove(id);

    std::cout<<"删除成功！"<<std::endl;

    borrowerManager->Save();

    menuManager->Back();
}

BorrowerManageDelete::BorrowerManageDelete() = default;

BorrowerManageDelete::~BorrowerManageDelete() = default;
