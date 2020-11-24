//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BorrowerManager.h"
#include "../Utils.h"

#include <utility>
#include <iostream>
#include <RixJson.h>

void BorrowerManager::Add(const std::string &_n){
    DataType d;
    d.id = id_count++;
    d.name = _n;
    data.push_back(d);
}


void BorrowerManager::Save(){
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

        Rix::Json::Object jo_borrow_history;
        jo_borrow_history.SetType(Rix::Json::ARRAY);
        for(auto &history:d.borrowHistory)
        {
            jo_borrow_history.Add((double)history);
        }
        jo_d.Add("borrowHistory", jo_borrow_history);

        Rix::Json::Object jo_borrowing;
        jo_borrowing.SetType(Rix::Json::ARRAY);
        for(auto &b:d.borrowing)
        {
            Rix::Json::Object jo_b;
            jo_b.SetType(Rix::Json::OBJECT);
            jo_b.Add("id", (double)b.first);
            jo_b.Add("num", (double)b.second);

            jo_borrowing.Add(jo_b);
        }
        jo_d.Add("borrowing", jo_borrowing);

        jo_data.Add(jo_d);
    }

    jo.Add("data", jo_data);

    Utils::WriteFile(dataFilePath, jo.ToStr());

    std::cout<<"Data file: "<<dataFilePath<<" saved!"<<std::endl;
}
void BorrowerManager::Load(){
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

            auto &jo_borrow_history = jo_d.Get("borrowHistory").AsArray();
            for(auto &jo_history:jo_borrow_history)
            {
                d.borrowHistory.push_back(jo_history.AsInt());
            }

            auto &jo_borrowing = jo_d.Get("borrowing").AsArray();
            for(auto &jo_b:jo_borrowing)
            {
                d.borrowing.emplace_back(jo_b.Get("id").AsInt(), jo_b.Get("num").AsInt());
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

BorrowerManager::BorrowerManager(std::string _dataFilePath):DataManager<BorrowerManager_DataType>(std::move(_dataFilePath)){}
BorrowerManager::~BorrowerManager() = default;