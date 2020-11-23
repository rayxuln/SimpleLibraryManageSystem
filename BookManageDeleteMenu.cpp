//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BookManageDeleteMenu.h"
#include "MenuManager.h"
#include "App.h"
#include "Utils.h"

#include <iostream>

void BookManageDeleteMenu::Show() {
    auto bookManager = menuManager->GetApp()->GetBookManager();

    std::cout<<"请输入编号: "<<std::endl;
    int id;
    std::cin>>id;

    if(!bookManager->Has(id))
    {
        std::cout<<"错误的编号！"<<std::endl;
        menuManager->Back();
        return;
    }

    bookManager->Remove(id);

    std::cout<<"删除成功！"<<std::endl;

    bookManager->Save();

    menuManager->Back();
}

BookManageDeleteMenu::BookManageDeleteMenu() = default;

BookManageDeleteMenu::~BookManageDeleteMenu() = default;
