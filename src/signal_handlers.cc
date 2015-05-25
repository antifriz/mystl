//
// Created by ivan on 5/24/15.
//

#include <mystl/signal_handlers.h>

#include <signal.h>
#include <sys/wait.h>

void ::mystd::reap_dead_processes() {
    struct sigaction sa;
    sa.sa_handler = sigchld_handler; // reap all dead processes
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1)
        throw signal_handlers_exception(-1, "reap_dead_processes");
}

void ::mystd::sigchld_handler(int s) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}