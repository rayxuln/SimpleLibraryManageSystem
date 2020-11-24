//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEUPDATEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEUPDATEMENU_H

#include "../Menu.h"

class BookManageUpdateMenu : public Menu {
public:

    void Show() override;

    BookManageUpdateMenu();
    ~BookManageUpdateMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEUPDATEMENU_H
