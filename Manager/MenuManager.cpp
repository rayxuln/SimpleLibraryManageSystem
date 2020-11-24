//
// Created by Raymond_Lx on 2020/11/23.
//

#include "MenuManager.h"

#include <iostream>

void MenuManager::Goto(std::shared_ptr<Menu> newMenu) {
    history.push(newMenu);
    newMenu->SetMenuManager(this);
}

void MenuManager::Back() {
    if(history.size() > 1)
    {
        auto m = history.top();
        history.pop();
    }
}

void MenuManager::Home() {
    while (history.size() > 1){
        auto m = history.top();
        history.pop();
    }
}

MenuManager::MenuManager(std::shared_ptr<Menu> initMenu) {
    Goto(initMenu);
}

std::shared_ptr<Menu> MenuManager::Current() {
    return history.top();
}

void MenuManager::Show() {
    Current()->Show();
}
