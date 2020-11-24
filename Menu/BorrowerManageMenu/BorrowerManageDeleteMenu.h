//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEDELETEMENU_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEDELETEMENU_H

#include "../Menu.h"

class BorrowerManageDeleteMenu : public Menu {
public:

    void Show() override;

    BorrowerManageDeleteMenu();
    ~BorrowerManageDeleteMenu() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEDELETEMENU_H
