/*
 * This program creates a few custom signal handlers and a signal handler table
 * within your own user application to work in a way similar to how the kernel's
 * default signal handler table works.
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COUNT 5
#define NUM_HANDLERS 4

typedef void (* sighandler_t)(int);

sighandler_t custom_sig[NUM_HANDLERS];
sighandler_t default_sig[NUM_HANDLERS];

static int count = 0;

sighandler_t sigaction_checked(int sig_num, sighandler_t handler) {
    struct sigaction new_handler, old_handler;
    new_handler.sa_handler = handler;
    sigemptyset(&(new_handler.sa_mask));
    sigaddset(&(new_handler.sa_mask), sig_num);
    int result = sigaction(sig_num, &new_handler, &old_handler);
    if (result < 0) {
        fprintf(stderr, "Error in sigaction: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return old_handler.sa_handler;
}

sighandler_t custom_handler(int sig_num) {
    if (count >= MAX_COUNT) {
        return sigaction_checked(sig_num, default_sig[sig_num]);
    }
    else {
        return sigaction_checked(sig_num, custom_sig[sig_num]);
    }
}

void sig_hup(int sig_num) {
    puts("Hey! Don't hang up on me!");
    count++;
    custom_handler(sig_num);
}

void sig_int(int sig_num) {
    puts("Hey! Don't interrupt me!");
    count++;
    custom_handler(sig_num);
}

void sig_quit(int sig_num) {
    puts("I refuse to quit!");
    count++;
    custom_handler(sig_num);
}

void install_handlers() {
    custom_sig[SIGHUP] = &sig_hup;
    custom_sig[SIGINT] = &sig_int;
    custom_sig[SIGQUIT] = &sig_quit;
    for (int i = 1; i < NUM_HANDLERS; i++) {
        default_sig[i] = custom_handler(i);
    }
}

int main() {
    printf("PID: %d\n", getpid());
    install_handlers();
    while (1) {}
    return EXIT_SUCCESS;
}
