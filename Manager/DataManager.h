//
// Created by Raymond_Lx on 2020/11/24.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_DATAMANAGER_H
#define SIMPLELIBRARYMANAGESYSTEM_DATAMANAGER_H

#include <vector>
#include <string>
#include <exception>

template<typename DataType>
class DataManager {
protected:
    std::vector<DataType> data;
    int id_count{};

    std::string dataFilePath;

    class NullDataException : public std::exception {};
public:
    DataType &GetDataRef(int id){
        for(auto &d:data)
        {
            if(d.id == id)
            {
                return d;
            }
        }
        throw NullDataException();
    }
    void Remove(int id){
        for(auto d=data.begin(); d!=data.end(); ++d)
        {
            if((*d).id == id)
            {
                data.erase(d);
                return;
            }
        }
        throw NullDataException();
    }
    bool Has(int id) {
        return std::any_of(data.begin(), data.end(), [id](DataType d){return d.id==id;});
    }

    inline auto &Data(){return data;}

    virtual void Save() = 0;
    virtual void Load() = 0;

    explicit DataManager(std::string _dataFilePath):dataFilePath(std::move(_dataFilePath)){}
    virtual ~DataManager() = default;
};


#endif //SIMPLELIBRARYMANAGESYSTEM_DATAMANAGER_H
