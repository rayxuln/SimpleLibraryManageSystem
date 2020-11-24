//
// Created by Raymond_Lx on 2020/11/23.
//

#include "Utils.h"

#include <fstream>
#include <ctime>


void Utils::WriteFile(const std::string &path, const std::string &text) {
    std::ofstream file(path);
    file<<text;
    file.close();
}

std::string Utils::ReadFile(const std::string &path) {
    std::ifstream file(path);
    if(!file)
    {
        std::ofstream f(path);
        f.close();
        return "";
    }
    std::string line, res;
    while(!file.eof())
    {
        getline(file, line);
        if(!res.empty()) res += "\n";
        res += line;
    }
    return res;
}

std::string Utils::GetToday() {
    time_t t;
    time(&t);
    auto p = localtime(&t);
    std::stringstream ss;
    ss<<p->tm_year+1900<<"年"<<p->tm_mon+1<<"月"<<p->tm_mday<<"日";
    return ss.str();
}

