//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEADDMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEADDMENU_H

#include "../Menu.h"

class BorrowerManageAddMenu : public Menu {
public:

    void Show() override;

    BorrowerManageAddMenu();
    ~BorrowerManageAddMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEADDMENU_H
