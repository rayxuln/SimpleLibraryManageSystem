//
// Created by Raymond_Lx on 2020/11/23.
//

#include "BorrowManager.h"
#include "../Utils.h"
#include "../App.h"

#include <utility>
#include <iostream>
#include <RixJson.h>


BorrowManager::DataType &BorrowManager::Add(const std::vector<std::pair<int, int>> &book, int borrowerId, int action){
    DataType d;
    d.id = id_count++;
    d.date = Utils::GetToday();
    d.book = book;
    d.borrowerId = borrowerId;
    d.action = action;
    data.push_back(d);
    return data.back();
}

void BorrowManager::Save(){
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
        jo_d.Add("date", d.date);

        Rix::Json::Object jo_book;
        jo_book.SetType(Rix::Json::ARRAY);
        for(auto &b:d.book)
        {
            Rix::Json::Object jo_b;
            jo_b.SetType(Rix::Json::OBJECT);

            jo_b.Add("id", (double)b.first);
            jo_b.Add("num", (double)b.second);

            jo_book.Add(jo_b);
        }
        jo_d.Add("book", jo_book);

        jo_d.Add("borrowerId", (double)d.borrowerId);
        jo_d.Add("action", (double)d.action);

        jo_data.Add(jo_d);
    }

    jo.Add("data", jo_data);

    Utils::WriteFile(dataFilePath, jo.ToStr());

    std::cout<<"Data file: "<<dataFilePath<<" saved!"<<std::endl;
}
void BorrowManager::Load(){
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
            d.date = jo_d.Get("date").AsString();

            auto &jo_book = jo_d.Get("book").AsArray();
            for(auto &jo_b:jo_book)
            {
                d.book.emplace_back(jo_b.Get("id").AsInt(), jo_b.Get("num").AsInt());
            }

            d.borrowerId = jo_d.Get("borrowerId").AsInt();
            d.action = jo_d.Get("action").AsInt();

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

void BorrowManager::Borrow(const std::vector<std::pair<int, int>> &book, int borrowerId) {
    auto bookManager = app->GetBookManager();
    auto borrowerManager = app->GetBorrowerManager();

    if(borrowerManager->Has(borrowerId))
    {
        auto &borrower_d = borrowerManager->GetDataRef(borrowerId);

        // update book
        for(auto &b:book)
        {
            if(bookManager->Has(b.first))
            {
                auto &book_d = bookManager->GetDataRef(b.first);

                if(b.second <= book_d.num - book_d.lent)
                {
                    book_d.lent += b.second;
                }else throw BorrowingTooManyBooksException();
            }else throw InvalidBookIdException();
        }

        // update borrowing
        for(auto &b:book)
        {
            bool updated = false;
            for(auto &bb:borrower_d.borrowing)
            {
                if(bb.first == b.first)
                {
                    updated = true;
                    bb.second += b.second;
                    break;
                }
            }
            if(!updated)
            {
                borrower_d.borrowing.emplace_back(b.first, b.second);
            }
        }

        // record
        auto borrow_d = Add(book, borrowerId, 0);
        borrower_d.borrowHistory.push_back(borrow_d.id);

        bookManager->Save();
        borrowerManager->Save();
        Save();
    }else{
        throw InvalidBorrowerIdException();
    }
}

void BorrowManager::Return(const std::vector<std::pair<int, int>> &book, int borrowerId) {
    auto bookManager = app->GetBookManager();
    auto borrowerManager = app->GetBorrowerManager();

    if(borrowerManager->Has(borrowerId))
    {
        auto &borrower_d = borrowerManager->GetDataRef(borrowerId);

        // update book
        for(auto &b:book)
        {
            if(bookManager->Has(b.first))
            {
                auto &book_d = bookManager->GetDataRef(b.first);

                if(b.second <= book_d.lent)
                {
                    book_d.lent -= b.second;
                }else throw ReturningTooManyBooksException();
            }else throw InvalidBookIdException();
        }

        // update borrowing
        for(auto &b:book)
        {
            bool updated = false;
            for(auto &bb:borrower_d.borrowing)
            {
                if(bb.first == b.first)
                {
                    updated = true;
                    bb.second -= b.second;
                    break;
                }
            }
            if(!updated)
            {
                throw ReturningNotBorrowedBooksException();
            }
        }

        auto borrower_d_book = std::vector<std::pair<int, int>>(borrower_d.borrowing.begin(), borrower_d.borrowing.end());
        borrower_d.borrowing.clear();
        for(auto &b:borrower_d_book)
        {
            if(b.second > 0)
            {
                borrower_d.borrowing.push_back(b);
            }
        }

        // record
        auto borrow_d = Add(book, borrowerId, 1);
        borrower_d.borrowHistory.push_back(borrow_d.id);

        bookManager->Save();
        borrowerManager->Save();
        Save();
    }else{
        throw InvalidBorrowerIdException();
    }
}

std::string BorrowManager::ToHistoryString(const BorrowManager::DataType &d) {
    auto bookManager = app->GetBookManager();
    auto borrowerManager = app->GetBorrowerManager();

    std::stringstream ss;

    auto &borrower_d = borrowerManager->GetDataRef(d.borrowerId);
    ss<<d.date<<", "<<borrower_d.name<<" "<<(d.action==0?"借了 ":"还了 ");
    for(size_t i=0; i<d.book.size(); ++i)
    {
        auto &book_d = bookManager->GetDataRef(d.book[i].first);
        ss<<d.book[i].second<<"本《"<<book_d.name<<"》";
        if(i < d.book.size()-1)
            ss<<",";
    }

    return ss.str();
}

BorrowManager::BorrowManager(std::string _dataFilePath, App *_app):DataManager<BorrowManager_DataType>(std::move(_dataFilePath)),app(_app){}

BorrowManager::~BorrowManager() = default;