//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BookManageAddMenu.h"
#include "../../Manager/MenuManager.h"
#include "../../App.h"
#include "../../Utils.h"

#include <iostream>

void BookManageAddMenu::Show() {
    auto bookManager = menuManager->GetApp()->GetBookManager();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"请输入书名: ";
    std::string name;
    getline(std::cin, name);

    std::cout<<"请输入作者: ";
    std::string author;
    getline(std::cin, author);

    std::cout<<"请输入数量: ";
    std::string num_s;
    getline(std::cin, num_s);
    if(num_s.empty()) num_s = "0";

    bookManager->Add(name, author, Utils::StringTo<int>(num_s));
    std::cout<<"添加成功！"<<std::endl;

    bookManager->Save();

    menuManager->Back();
}

BookManageAddMenu::BookManageAddMenu() = default;

BookManageAddMenu::~BookManageAddMenu() = default;
