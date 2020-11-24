//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BookManageUpdateMenu.h"
#include "../../Manager/MenuManager.h"
#include "../../App.h"
#include "../../Utils.h"

#include <iostream>

void BookManageUpdateMenu::Show() {
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

    auto &d = bookManager->GetDataRef(id);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"请输入书名("<<d.name<<"): ";
    std::string name;
    getline(std::cin, name);
    if(!name.empty()) d.name = name;

    std::cout<<"请输入作者("<<d.author<<"): ";
    std::string author;
    getline(std::cin, author);
    if(!author.empty()) d.author = author;

    std::cout<<"请输入数量("<<d.num<<"): ";
    std::string num_s;
    getline(std::cin, num_s);
    if(!num_s.empty()) d.num = Utils::StringTo<int>(num_s);

    std::cout<<"更新成功！"<<std::endl;

    bookManager->Save();

    menuManager->Back();
}

BookManageUpdateMenu::BookManageUpdateMenu() = default;

BookManageUpdateMenu::~BookManageUpdateMenu() = default;
