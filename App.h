//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_APP_H
#define SIMPLELIBRARYMANAGESYSTEM_APP_H

#include <vector>
#include <string>
#include <memory>

#include "MenuManager.h"
#include "BookManager.h"
#include "BorrowerManager.h"
#include "BorrowManager.h"

class App {
    std::shared_ptr<MenuManager> menuManager;
    std::shared_ptr<BookManager> bookManager;
    std::shared_ptr<BorrowerManager> borrowerManager;
    std::shared_ptr<BorrowManager> borrowManager;

    bool is_quit;
public:
    inline auto GetBookManager() {return bookManager;}
    inline auto GetBorrowerManager() {return borrowerManager;}
    inline auto GetBorrowManager() {return borrowManager;}

    int Run(std::vector<std::string> &args);

    void Quit();
};


#endif //SIMPLELIBRARYMANAGESYSTEM_APP_H
