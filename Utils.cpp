//
// Created by Raymond_Lx on 2020/11/23.
//

#include "Utils.h"

#include <fstream>


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

