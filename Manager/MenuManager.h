//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_MENUMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_MENUMANAGER_H

#include "../Menu/Menu.h"
#include "stack"

#include <memory>

class App;

class MenuManager {
    std::stack<std::shared_ptr<Menu>> history;
    App *app;
public:
    explicit MenuManager(std::shared_ptr<Menu> initMenu);
    ~MenuManager() = default;

    inline void SetApp(App *a){app=a;}
    inline App *GetApp(){return app;}

    std::shared_ptr<Menu> Current();

    void Goto(std::shared_ptr<Menu> newMenu);
    void Back();
    void Home();

    void Show();
};


#endif //SIMPLELIBRARYMANAGESYSTEM_MENUMANAGER_H
