//
// Created by ivan on 5/25/15.
//

#ifndef _MYSTL_SIGNAL_HANDLERS_H
#define _MYSTL_SIGNAL_HANDLERS_H

#include "exception.h"

namespace mystd {
    class signal_handlers_exception : public exception {
    public:
        signal_handlers_exception(int err_num, const std::string &msg) : exception(err_num,msg){}
    };

    void sigchld_handler(int s);

    void reap_dead_processes();
}

#endif //_MYSTL_SIGNAL_HANDLERS_H
