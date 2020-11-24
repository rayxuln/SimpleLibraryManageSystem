//
// Created by Raymond_Lx on 2020/11/24.
//

#include "BorrowManageReturnMenu.h"
#include "MenuManager.h"
#include "App.h"
#include "Utils.h"

#include <iostream>

void BorrowManageReturnMenu::Show() {
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto &borrower_d = borrowerManager->GetDataRef(borrower_id);

    std::cout<<"欢迎 "<<borrower_d.name<<" 来借阅书籍~"<<std::endl;

    std::cout<<"您所借阅了的书籍有: "<<std::endl;
    for(auto &b:borrower_d.borrowing)
    {
        auto &b_d = bookManager->GetDataRef(b.first);
        std::cout<<"["<<b.first<<"]"<<"《"<<b_d.name<<"》 "<<b.second<<"本"<<std::endl;
    }
    std::cout<<std::endl;

    int book_id;
    std::string book_id_s;
    int book_num;
    std::string book_num_s;
    std::vector<std::pair<int, int>> book;
    while (true)
    {
        std::cout<<"请输入要归还的书的编号(-1): "<<std::endl;
        getline(std::cin, book_id_s);
        if(book_id_s.empty()) book_id_s = "-1";
        book_id = Utils::StringTo<int>(book_id_s);

        if(book_id == -1) break;

        if(!std::any_of(borrower_d.borrowing.begin(), borrower_d.borrowing.end(), [book_id](std::pair<int, int> &b){return b.first==book_id;}))
        {
            std::cout<<"您并没有借阅编号为 '"<<book_id<<"' 的书籍!"<<std::endl;
            continue;
        }

        auto &bb = *std::find_if(borrower_d.borrowing.begin(), borrower_d.borrowing.end(), [book_id](std::pair<int, int> &b){return b.first==book_id;});
        auto &b = bookManager->GetDataRef(bb.first);
        std::cout<<"正在归还 《"<<b.name<<"》[借了 "<<bb.second<<" 本] "<<std::endl;

        book_num = 0;
        std::any_of(book.begin(), book.end(), [book_id, &book_num](std::pair<int, int> b){
            if(b.first==book_id)
            {
                book_num=b.second;
                return true;
            }
            return false;
        });

        std::cout<<"请输入要归还的数量("<<book_num<<"): "<<std::endl;
        getline(std::cin, book_num_s);
        if(!book_num_s.empty())
            book_num = Utils::StringTo<int>(book_num_s);

        if(book_num <= 0 || book_num > bb.second)
        {
            if(book_num <= 0) std::cout<<"所归还的数量为0！"<<std::endl;
            if(book_num > bb.second) std::cout<<"所归还的数量太多！"<<std::endl;
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
        std::cout<<"未归还任何书籍"<<std::endl;
        menuManager->Back();
        return;
    }

    borrowManager->Return(book, borrower_id);
    std::cout<<"归还成功！"<<std::endl;


    menuManager->Back();
}

BorrowManageReturnMenu::BorrowManageReturnMenu() = default;

BorrowManageReturnMenu::~BorrowManageReturnMenu() = default;