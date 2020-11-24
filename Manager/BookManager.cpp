//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BookManager.h"
#include "../Utils.h"

#include <utility>
#include <iostream>
#include <RixJson.h>

void BookManager::Add(const std::string &_n, const std::string &_a, int _num){
    DataType d;
    d.id = id_count++;
    d.name = _n;
    d.author = _a;
    d.num = _num;
    d.lent = 0;
    data.push_back(d);
}
BookManager::DataType &BookManager::GetDataRef(int id){
    for(auto &d:data)
    {
        if(d.id == id)
        {
            return d;
        }
    }
    throw NullDataException();
}
void BookManager::Remove(int id){
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

bool BookManager::Has(int id) {
    return std::any_of(data.begin(), data.end(), [id](DataType d){return d.id==id;});
}


void BookManager::Save(){
    std::cout<<"Saving data file: "<<dataFilePath<<std::endl;

    Rix::Json::Object jo;
    jo.SetType(Rix::Json::OBJECT);
    Rix::Json::Object jo_data;
    jo_data.SetType(Rix::Json::ARRAY);


    jo.Add("id_count", (double)id_count);

    for(auto &d:data)
    {
        Rix::Json::Object jo_d;
        jo_d.SetType(Rix::Json::OBJECT);

        jo_d.Add("id", (double)d.id);
        jo_d.Add("name", d.name);
        jo_d.Add("author", d.author);
        jo_d.Add("num", (double)d.num);
        jo_d.Add("lent", (double)d.lent);

        jo_data.Add(jo_d);
    }

    jo.Add("data", jo_data);

    Utils::WriteFile(dataFilePath, jo.ToStr());

    std::cout<<"Data file: "<<dataFilePath<<" saved!"<<std::endl;
}
void BookManager::Load(){
    std::cout<<"Loading data file: "<<dataFilePath<<std::endl;
    std::string dataFileString = Utils::ReadFile(dataFilePath);
    if(dataFileString.empty())
    {
        std::cout<<"Data file: "<<dataFilePath<<" is empty."<<std::endl;
        Save();
        return;
    }
    Rix::Json::Parser parser(dataFileString);

    data.clear();

    try {
        auto jo = parser.Parse();
        auto &jo_data = jo.Get("data");
        id_count = jo.Get("id_count").AsInt();

        for(auto &jo_d:jo_data.GetChildren())
        {
            DataType d;

            d.id = jo_d.Get("id").AsInt();
            d.name = jo_d.Get("name").AsString();
            d.author = jo_d.Get("author").AsString();
            d.num = jo_d.Get("num").AsInt();
            d.lent = jo_d.Get("lent").AsInt();

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

BookManager::BookManager(std::string _dataFilePath):dataFilePath(std::move(_dataFilePath)){}
BookManager::~BookManager() = default;

