//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_DATAMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_DATAMANAGER_H

#include <vector>
#include <map>
#include <string>
#include <exception>

typedef size_t SizeType;
typedef std::map<std::string, std::string> DataType;

class DataManager {
    inline SizeType NewId(){
        return id_count++;
    }
    void UnPackArgs(DataType &out, std::initializer_list<std::string> &in);

    std::vector<DataType> data;
    std::vector<std::string> columns;
    SizeType id_count;

    std::string dataFilePath;

public:
    void Add(std::initializer_list<std::string> args);
    void Update(SizeType id, std::initializer_list<std::string> args);
    void Remove(SizeType id);

    void Save();
    void Load();

    DataManager(std::string _dataFilePath, std::initializer_list<std::string> _columns);
    ~DataManager() = default;
};

class DataNotFoundException : public std::exception{};


#endif //SIMPLELIBRARYMANAGESYSTEM_DATAMANAGER_H
