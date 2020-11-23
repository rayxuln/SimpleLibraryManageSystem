//
// Created by Raymond_Lx on 2020/11/23.
//

#include "DataManager.h"
#include "Utils.h"

#include <RixJson.h>
#include <iostream>

void DataManager::UnPackArgs(DataType &d, std::initializer_list<std::string> &args) {
    int i=0;
    for(auto arg=args.begin(); arg!=args.end(); ++arg, ++i){
        d[columns[i]] = *arg;
    }
}

void DataManager::Add(std::initializer_list<std::string> args) {
    DataType d;
    UnPackArgs(d, args);
    d["id"] = Utils::ToString(NewId());
    data.push_back(d);
}

void DataManager::Remove(SizeType id) {
    for(auto d=data.begin(); d!=data.end(); ++d)
    {
        if((*d)["id"] == Utils::ToString(id))
        {
            data.erase(d);
            return;
        }
    }
    throw DataNotFoundException();
}

void DataManager::Update(SizeType id, std::initializer_list<std::string> args) {
    for(auto &d : data)
    {
        if(d["id"] == Utils::ToString(id))
        {
            UnPackArgs(d, args);
            return;
        }
    }
    throw DataNotFoundException();
}

DataManager::DataManager(std::string _dataFilePath, std::initializer_list<std::string> _columns)
                    :id_count(0),dataFilePath(_dataFilePath),columns(_columns) {}

void DataManager::Save() {
    std::cout<<"Saving data file: "<<dataFilePath<<std::endl;

    Rix::Json::Object jo;
    jo.SetType(Rix::Json::OBJECT);
    Rix::Json::Object jo_data;
    jo.SetType(Rix::Json::ARRAY);

    jo_data.SetToastKey("data");
    jo.AddChild(jo_data);

    for(auto &d:data)
    {
        Rix::Json::Object jo_d;
        jo_d.SetType(Rix::Json::OBJECT);

        for(auto &kv:d){
            Rix::Json::Object jo_kv;
            jo_kv.SetType(Rix::Json::STRING);

            jo_kv.SetToastKey(kv.first);
            std::string value = "\"";
            value += kv.second;
            value += "\"";
            jo_kv.SetRawValue(value);

            jo_d.AddChild(jo_kv);
        }

        jo_data.AddChild(jo_d);
    }

    Utils::WriteFile(dataFilePath, jo.ToStr());

    std::cout<<"Data file: "<<dataFilePath<<" saved!"<<std::endl;
}

void DataManager::Load() {
    std::cout<<"Loading data file: "<<dataFilePath<<std::endl;
    std::string dataFileString = Utils::ReadFile(dataFilePath);
    Rix::Json::Parser parser(dataFileString);

    data.clear();

    try {
        auto jo = parser.Parse();
        auto jo_data = jo.Get("data");

        for(auto &jo_d:jo_data.GetChildren())
        {
            DataType d;
            for(auto &c:columns)
            {
                d[c] = jo_d.Get(c).AsString();
            }
            data.push_back(d);
        }

        std::cout<<"Data file: "<<dataFilePath<<" loaded!"<<std::endl;
    } catch (Rix::Json::ParserException &e) {
        std::cout<<"Loading data file("<<dataFilePath<<") fail:"<<e.what()<<std::endl;
    } catch (Rix::Json::NullObjectException &e) {
        std::cout<<"Data file is broken!"<<std::endl;
        data.clear();
    }
}


