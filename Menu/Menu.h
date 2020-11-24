//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_MENU_H
#define SIMPLELIBRARYMANAGESYSTEM_MENU_H

#include <memory>

class MenuManager;

class Menu {
protected:
    MenuManager *menuManager = nullptr;
public:
    inline void SetMenuManager(MenuManager *m){menuManager = m;}

    virtual void Show() = 0;
    virtual bool HandleInput(int n);

    virtual bool ValidInput(int n);

    virtual ~Menu() = default;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_MENU_H
