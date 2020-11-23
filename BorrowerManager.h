//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGER_H

#include <vector>
#include <string>
#include <exception>

class BorrowerManager {
    struct DataType {
        int id;
        std::string name;
        std::vector<int> borrowHistory;
        std::vector<std::pair<int, int>> borrowing;
    };
    std::vector<DataType> data;
    int id_count{};

    std::string dataFilePath;

    class NullDataException : public std::exception {};
public:
    void Add(const std::string &_n);
    DataType &GetDataRef(int id);
    void Remove(int id);
    bool Has(int id);

    inline auto &Data(){return data;}

    void Save();
    void Load();

    explicit BorrowerManager(std::string _dataFilePath);
    ~BorrowerManager();
};


#endif //SIMPLELIBRARYMANAGESYSTEM_BORROWERMANAGER_H
