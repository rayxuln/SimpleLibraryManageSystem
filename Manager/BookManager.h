//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGER_H

#include <vector>
#include <string>
#include <exception>

class BookManager {
    struct DataType {
        int id;
        std::string name;
        std::string author;
        int num;
        int lent;
    };
    std::vector<DataType> data;
    int id_count{};

    std::string dataFilePath;

    class NullDataException : public std::exception {};
public:
    void Add(const std::string &_n, const std::string &_a, int _num);
    DataType &GetDataRef(int id);
    void Remove(int id);
    bool Has(int id);

    inline auto &Data(){return data;}

    void Save();
    void Load();

    explicit BookManager(std::string _dataFilePath);
    ~BookManager();
};



#endif //SIMPLELIBRARYMANAGESYSTEM_BOOKMANAGER_H
