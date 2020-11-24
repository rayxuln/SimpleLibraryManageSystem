//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowManageBorrowMenu.h"
#include "MenuManager.h"
#include "App.h"
#include "Utils.h"

#include <iostream>

void BorrowManageBorrowMenu::Show() {
    auto borrowerManager = menuManager->GetApp()->GetBorrowerManager();
    auto bookManager = menuManager->GetApp()->GetBookManager();
    auto borrowManager = menuManager->GetApp()->GetBorrowManager();

    std::cout<<"请输入借阅者编号: ";
    int borrower_id;
    std::cin>>borrower_id;
    if(!borrowerManager->Has(borrower_id))
    {
        std::cout<<"错误的借阅者编号 '"<<borrower_id<<"'!"<<std::endl;
        menuManager->Back();
        return;
    }

    auto &borrower_d = borrowerManager->GetDataRef(borrower_id);

    std::cout<<"欢迎 "<<borrower_d.name<<" 来借阅书籍~"<<std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int book_id;
    std::string book_id_s;
    int book_num;
    std::string book_num_s;
    std::vector<std::pair<int, int>> book;
    while (true)
    {
        std::cout<<"请输入要借阅的书的编号(-1): "<<std::endl;
        getline(std::cin, book_id_s);
        if(book_id_s.empty()) book_id_s = "-1";
        book_id = Utils::StringTo<int>(book_id_s);

        if(book_id == -1) break;

        if(!bookManager->Has(book_id))
        {
            std::cout<<"不存在编号为 '"<<book_id<<"' 的书籍!"<<std::endl;
            continue;
        }

        auto &b = bookManager->GetDataRef(book_id);
        std::cout<<"正在借阅 《"<<b.name<<"》[已借出 "<<b.lent<<"/"<<b.num<<"] [剩余 "<<b.num-b.lent<<"] "<<std::endl;

        if(b.num == 0 || b.num - b.lent == 0)
        {
            std::cout<<"该书的库存为0!"<<std::endl;
            continue;
        }

        book_num = 0;
        std::any_of(book.begin(), book.end(), [book_id, &book_num](std::pair<int, int> b){
            if(b.first==book_id)
            {
                book_num=b.second;
                return true;
            }
            return false;
        });

        std::cout<<"请输入要借阅的数量("<<book_num<<"): "<<std::endl;
        getline(std::cin, book_num_s);
        if(!book_num_s.empty())
            book_num = Utils::StringTo<int>(book_num_s);



        if(book_num <= 0 || book_num + b.lent > b.num)
        {
            if(book_num <= 0) std::cout<<"所借阅的数量为0！"<<std::endl;
            if(book_num + b.lent > b.num) std::cout<<"所借阅的数量太多！"<<std::endl;
            continue;
        }

        if(!std::any_of(book.begin(), book.end(), [book_id, book_num](std::pair<int, int> &b){
            if(book_id == b.first)
            {
                b.second = book_num;
                return true;
            }
            return false;
        }))
        {
            book.emplace_back(book_id, book_num);
        }
    }

    if(book.empty())
    {
        std::cout<<"未借阅任何书籍"<<std::endl;
        menuManager->Back();
        return;
    }

    borrowManager->Borrow(book, borrower_id);
    std::cout<<"借阅成功！"<<std::endl;


    menuManager->Back();
}

BorrowManageBorrowMenu::BorrowManageBorrowMenu() = default;

BorrowManageBorrowMenu::~BorrowManageBorrowMenu() = default;