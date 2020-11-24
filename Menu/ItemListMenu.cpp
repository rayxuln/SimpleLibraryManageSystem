//
// Created by Raymond_Lx on 2020/11/23.
//

#include "ItemListMenu.h"
#include "../Manager/MenuManager.h"

#include <iostream>


void ItemListMenu::GenerateMenu() {
    itemList.emplace_back("返回上一界面");
    itemList.emplace_back("返回主界面");
}



void ItemListMenu::Show() {
    itemList.clear();
    GenerateMenu();

    ShowTitle();

    ShowItemList();

    FetchInput();
}

bool ItemListMenu::HandleInput(int n) {
    auto s = itemList[n];
    if(s == "返回上一界面")
    {
        menuManager->Back();
        return true;
    }
    if(s == "返回主界面")
    {
        menuManager->Home();
        return true;
    }
    return false;
}

bool ItemListMenu::ValidInput(int n) {
    return n >= 0 && n < itemList.size();
}

ItemListMenu::ItemListMenu():title("未命名的界面") {

}

void ItemListMenu::ShowTitle() {
    std::cout<<"============================="<<std::endl;
    std::cout<<title<<std::endl;
    std::cout<<"============================="<<std::endl;
}

void ItemListMenu::ShowItemList() {
    for(int i=0; i<itemList.size(); ++i)
    {
        std::cout<<i<<". "<<itemList[i]<<std::endl;
    }
    std::cout<<std::endl;
}

void ItemListMenu::FetchInput() {
    int n;
    std::cout<<std::endl;
    std::cout<<">: ";
    std::cin>>n;
    if(ValidInput(n))
        HandleInput(n);
    else
        std::cout<<"Invalid input '"<<n<<"'!"<<std::endl;
}

ItemListMenu::~ItemListMenu() = default;
