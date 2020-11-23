//
// Created by Raymond_Lx on 2020/11/23.
//

#include "MainMenu.h"
#include "App.h"


int App::Run(std::vector<std::string> &args) {
    menuManager = std::shared_ptr<MenuManager>(new MenuManager(std::shared_ptr<Menu>(new MainMenu())));
    menuManager->SetApp(this);

    bookManager = std::shared_ptr<BookManager>(new BookManager("book_data.json"));
    bookManager->Load();

    borrowerManager = std::shared_ptr<BorrowerManager>(new BorrowerManager("borrower_data.json"));
    borrowerManager->Load();

    borrowManager = std::shared_ptr<BorrowManager>(new BorrowManager("borrow_data.json", this));
    borrowManager->Load();

    is_quit = false;
    do{
        menuManager->Show();
    }while(!is_quit);


    return 0;
}



void App::Quit() {
    is_quit = true;
}