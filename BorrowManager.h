//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGER_H

#include <vector>
#include <string>
#include <exception>

class App;

class BorrowManager {
    struct DataType {
        int id;
        std::string date;
        std::vector<std::pair<int, int>> book;
        int borrowerId;
        int action; // 0 = borrow, 1 = return
    };
    std::vector<DataType> data;
    int id_count{};

    std::string dataFilePath;

    App *app;

    class NullDataException : public std::exception {};
    class InvalidBorrowerIdException : public std::exception {};
    class InvalidBookIdException : public std::exception {};
    class BorrowingTooManyBooksException : public std::exception {};
    class ReturningTooManyBooksException : public std::exception {};
    class ReturningNotBorrowedBooksException : public std::exception {};
public:
    DataType &Add(const std::vector<std::pair<int, int>> &book, int borrowerId, int action);
    DataType &GetDataRef(int id);
    void Remove(int id);
    bool Has(int id);

    void Borrow(const std::vector<std::pair<int, int>> &book, int borrowerId);
    void Return(const std::vector<std::pair<int, int>> &book, int borrowerId);

    inline auto &Data(){return data;}

    std::string ToHistoryString(const DataType &d);

    void Save();
    void Load();

    explicit BorrowManager(std::string _dataFilePath, App *_app);
    ~BorrowManager();
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWMANAGER_H
