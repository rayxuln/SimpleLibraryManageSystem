cmake_minimum_required(VERSION 3.17)
project(SimpleLibraryManageSystem)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./RixJson)

include_directories(./RixJson/inc)

add_executable(SimpleLibraryManageSystem
        main.cpp
        App.cpp App.h MenuManager.cpp MenuManager.h Menu.cpp Menu.h ItemListMenu.cpp ItemListMenu.h MainMenu.cpp MainMenu.h Utils.cpp Utils.h BookManager.cpp BookManager.h BookManageMenu.cpp BookManageMenu.h BookManageAddMenu.cpp BookManageAddMenu.h BookManageUpdateMenu.cpp BookManageUpdateMenu.h BookManageDeleteMenu.cpp BookManageDeleteMenu.h BorrowerManager.cpp BorrowerManager.h BorrowerManageMenu.cpp BorrowerManageMenu.h BorrowerManageAddMenu.cpp BorrowerManageAddMenu.h BorrowerManageUpdateMenu.cpp BorrowerManageUpdateMenu.h BorrowerManageDelete.cpp BorrowerManageDelete.h BorrowManager.cpp BorrowManager.h BorrowManageMenu.cpp BorrowManageMenu.h BorrowManageBorrowMenu.cpp BorrowManageBorrowMenu.h BorrowManageReturnMenu.cpp BorrowManageReturnMenu.h)

target_link_libraries(SimpleLibraryManageSystem RixJson)