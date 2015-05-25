#ifndef _MYSTL_STRING_H
#define _MYSTL_STRING_H

#include<cstring>

#include <vector>
#include <string>
namespace mystd{
    std::string to_lower(std::string str);


    bool ends_with(std::string const &fullString, std::string const &ending);



    std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> &elems);


    std::vector<std::string> split(const std::string &s, char delim);
}
#endif //_MYSTL_STRING_H