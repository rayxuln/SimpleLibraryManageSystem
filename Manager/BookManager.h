//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGER_H

#include "DataManager.h"

struct BookManager_DataType {
    int id;
    std::string name;
    std::string author;
    int num;
    int lent;
};

class BookManager : public DataManager<BookManager_DataType> {
    typedef BookManager_DataType DataType;
public:
    void Add(const std::string &_n, const std::string &_a, int _num);

    void Save() override;
    void Load() override;

    explicit BookManager(std::string _dataFilePath);
    ~BookManager() override;
};



#endif //SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGER_H
