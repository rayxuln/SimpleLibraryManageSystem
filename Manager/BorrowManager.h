//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGER_H

#include "DataManager.h"

class App;

struct BorrowManager_DataType {
    int id;
    std::string date;
    std::vector<std::pair<int, int>> book;
    int borrowerId;
    int action; // 0 = borrow, 1 = return
};

class BorrowManager : public DataManager<BorrowManager_DataType> {
    typedef BorrowManager_DataType DataType;

    App *app;

    class InvalidBorrowerIdException : public std::exception {};
    class InvalidBookIdException : public std::exception {};
    class BorrowingTooManyBooksException : public std::exception {};
    class ReturningTooManyBooksException : public std::exception {};
    class ReturningNotBorrowedBooksException : public std::exception {};
public:
    DataType &Add(const std::vector<std::pair<int, int>> &book, int borrowerId, int action);

    void Borrow(const std::vector<std::pair<int, int>> &book, int borrowerId);
    void Return(const std::vector<std::pair<int, int>> &book, int borrowerId);


    std::string ToHistoryString(const DataType &d);

    void Save() override;
    void Load() override;

    explicit BorrowManager(std::string _dataFilePath, App *_app);
    ~BorrowManager() override;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGER_H
