//
// Created by ivan on 5/24/15.
//

#include <mystl/daemon.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/syslog.h>

#define MAXFD 64
int mystd::daemonize(const char *pname, int facility, bool do_chdir) {
    int		    i;
    pid_t	    pid;

    if ((pid = fork()) < 0)
        return (-1);
    else if (pid)
        _exit(0);		/* parent terminates */

    /* child 1 continues... */

    if (setsid() < 0)		/* become session leader */
        return (-1);

    signal(SIGHUP, SIG_IGN);
    if ((pid = fork()) < 0)
        return (-1);
    else if (pid)
        _exit(0);		/* child 1 terminates */

    /* child 2 continues... */

    if(do_chdir)chdir("/");			/* change working directory */

    /* close off file descriptors */
    for (i = 0; i < MAXFD; i++)
        close(i);

    /* redirect stdin, stdout, and stderr to /dev/null */
    open("/dev/null", O_RDONLY);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_RDWR);

    openlog(pname, LOG_PID, facility);

    return (0);			/* success */
}