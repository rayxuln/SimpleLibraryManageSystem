//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEDELETE_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEDELETE_H

#include "Menu.h"

class BorrowerManageDelete : public Menu {
public:

    void Show() override;

    BorrowerManageDelete();
    ~BorrowerManageDelete() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGEDELETE_H
