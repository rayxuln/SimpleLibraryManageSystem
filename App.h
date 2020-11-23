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

class App {
    std::shared_ptr<MenuManager> menuManager;
    std::shared_ptr<BookManager> bookManager;

    bool is_quit;
public:
    inline auto GetBookManager() {return bookManager;}

    int Run(std::vector<std::string> &args);

    void Quit();
};


#endif //SIMPLELIBRARYMANAGESYSTEM_APP_H
