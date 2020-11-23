//
// Created by Raymond_Lx on 2020/11/23.
//

#include "MainMenu.h"
#include "BookManageMenu.h"
#include "MenuManager.h"
#include "App.h"

MainMenu::MainMenu(){
    title = "简单图书管理系统";
}

MainMenu::~MainMenu() {

}

void MainMenu::GenerateMenu() {
    itemList.emplace_back("图书管理");
    itemList.emplace_back("借阅管理");
    itemList.emplace_back("借阅者管理");
    itemList.emplace_back("退出");
}

bool MainMenu::HandleInput(int n) {
    switch (n) {
        case 0:
            menuManager->Goto(std::shared_ptr<BookManageMenu>(new BookManageMenu()));
            return true;
        case 1:
            return true;
        case 2:
            return true;
        case 3:
            menuManager->GetApp()->Quit();
            return true;
    }
    return false;
}

