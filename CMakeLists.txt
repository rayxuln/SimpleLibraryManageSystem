cmake_minimum_required(VERSION 3.17)
project(SimpleLibraryManageSystem)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./RixJson)

include_directories(./RixJson/inc)

add_executable(SimpleLibraryManageSystem
        main.cpp
        App.cpp App.h Manager/MenuManager.cpp Manager/MenuManager.h Menu/Menu.cpp Menu/Menu.h Menu/ItemListMenu.cpp Menu/ItemListMenu.h Menu/MainMenu.cpp Menu/MainMenu.h Utils.cpp Utils.h Manager/BookManager.cpp Manager/BookManager.h Menu/BookManageMenu/BookManageMenu.cpp Menu/BookManageMenu/BookManageMenu.h Menu/BookManageMenu/BookManageAddMenu.cpp Menu/BookManageMenu/BookManageAddMenu.h Menu/BookManageMenu/BookManageUpdateMenu.cpp Menu/BookManageMenu/BookManageUpdateMenu.h Menu/BookManageMenu/BookManageDeleteMenu.cpp Menu/BookManageMenu/BookManageDeleteMenu.h Manager/BorrowerManager.cpp Manager/BorrowerManager.h Menu/BorrowerManageMenu/BorrowerManageMenu.cpp Menu/BorrowerManageMenu/BorrowerManageMenu.h Menu/BorrowerManageMenu/BorrowerManageAddMenu.cpp Menu/BorrowerManageMenu/BorrowerManageAddMenu.h Menu/BorrowerManageMenu/BorrowerManageUpdateMenu.cpp Menu/BorrowerManageMenu/BorrowerManageUpdateMenu.h Menu/BorrowerManageMenu/BorrowerManageDeleteMenu.cpp Menu/BorrowerManageMenu/BorrowerManageDeleteMenu.h Manager/BorrowManager.cpp Manager/BorrowManager.h Menu/BorrowManageMenu/BorrowManageMenu.cpp Menu/BorrowManageMenu/BorrowManageMenu.h Menu/BorrowManageMenu/BorrowManageBorrowMenu.cpp Menu/BorrowManageMenu/BorrowManageBorrowMenu.h Menu/BorrowManageMenu/BorrowManageReturnMenu.cpp Menu/BorrowManageMenu/BorrowManageReturnMenu.h Menu/BorrowManageMenu/BorrowManageHistoryMenu.cpp Menu/BorrowManageMenu/BorrowManageHistoryMenu.h Menu/BorrowerManageMenu/BorrowerManageBorrowHistoryMenu.cpp Menu/BorrowerManageMenu/BorrowerManageBorrowHistoryMenu.h Menu/BorrowerManageMenu/BorrowerManageBorrowingMenu.cpp Menu/BorrowerManageMenu/BorrowerManageBorrowingMenu.h)

target_link_libraries(SimpleLibraryManageSystem RixJson)