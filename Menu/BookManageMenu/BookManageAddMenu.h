//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEADDMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEADDMENU_H

#include "../Menu.h"


class BookManageAddMenu : public Menu {
public:

    void Show() override;

    BookManageAddMenu();
    ~BookManageAddMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGEADDMENU_H
