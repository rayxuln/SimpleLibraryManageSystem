//
// Created by Raymond_Lx on 2020/11/23.
//

#include "MainMenu.h"
#include "App.h"

#include <iostream>


int App::Run(std::vector<std::string> &args) {
    menuManager = std::shared_ptr<MenuManager>(new MenuManager(std::shared_ptr<Menu>(new MainMenu())));
    menuManager->SetApp(this);

    bookManager = std::shared_ptr<BookManager>(new BookManager("book_data.json"));
    bookManager->Load();

    is_quit = false;
    do{
        menuManager->Show();
    }while(!is_quit);


    return 0;
}



void App::Quit() {
    is_quit = true;
}