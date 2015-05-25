#include <mystl/string.h>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> &mystd::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::string mystd::to_lower(std::string str) {
    std::string out_str;
    for (std::string::iterator it =  str.begin();  it !=str.end();++it) {
        out_str+= tolower(*it);
    }
    return out_str;
}

bool mystd::ends_with(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

std::vector<std::string>  mystd::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}