//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEDELETEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEDELETEMENU_H

#include "../Menu.h"

class BookManageDeleteMenu : public Menu{
public:

    void Show() override;

    BookManageDeleteMenu();
    ~BookManageDeleteMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEDELETEMENU_H
