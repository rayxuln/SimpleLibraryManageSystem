//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEUPDATEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEUPDATEMENU_H

#include "Menu.h"

class BorrowerManageUpdateMenu : public Menu {
public:

    void Show() override;

    BorrowerManageUpdateMenu();
    ~BorrowerManageUpdateMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEUPDATEMENU_H
