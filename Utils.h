//
// Created by Raymond_Lx on 2020/11/23.
//

#ifndef SIMPLELIBRARYMANAGESYSTEM_UTILS_H
#define SIMPLELIBRARYMANAGESYSTEM_UTILS_H

#include <string>
#include <sstream>

class Utils {
public:
    static void WriteFile(const std::string &path, const std::string &text);
    static std::string ReadFile(const std::string &path);

    template<typename T>
    static std::string ToString(T v){
        std::stringstream ss;
        ss<<v;
        std::string res;
        ss>>res;
        return res;
    }

    template<typename T>
    static T StringTo(const std::string &v){
        std::stringstream ss;
        ss<<v;
        T res;
        ss>>res;
        return res;
    }
};


#endif //SIMPLELIBRARYMANAGESYSTEM_UTILS_H
