//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGER_H

#include "DataManager.h"

struct BorrowerManager_DataType {
    int id;
    std::string name;
    std::vector<int> borrowHistory;
    std::vector<std::pair<int, int>> borrowing;
};


class BorrowerManager : public DataManager<BorrowerManager_DataType> {
    typedef BorrowerManager_DataType DataType;
public:
    void Add(const std::string &_n);

    void Save() override;
    void Load() override;

    explicit BorrowerManager(std::string _dataFilePath);
    ~BorrowerManager() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGER_H
