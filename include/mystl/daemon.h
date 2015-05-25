//
// Created by ivan on 5/24/15.
//

#ifndef _MYSTL_DAEMON_H
#define _MYSTL_DAEMON_H

namespace mystd{
    int daemonize(const char *pname, int facility, bool do_chdir = true);
}
#endif //_MYSTL_DAEMON_H

