//
// Created by ivan on 5/25/15.
//

#ifndef _MYSTL_IO_H
#define _MYSTL_IO_H


#include "exception.h"

namespace mystd {

    class io_exception : public exception {

    public:
        io_exception(int err_num, std::string const &msg) : exception(err_num, msg) { }
    };

    std::string get_cwd();

    std::vector<std::string> read_dir(std::string dir_path);

    long file_size(std::string filename);

    char getch(bool display_char = true);

}

#endif //_MYSTL_IO_H
