#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (* signal_handler_t)(int);

signal_handler_t sigaction_checked(int sig_num, signal_handler_t handler) {
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

void segv_handler(int sig_num) {
    puts("Ouch! Invalid address there!");
}

int main() {
    sigaction_checked(SIGSEGV, segv_handler);
    puts("Please enter an integer to be used as an invalid address.");
    printf("> ");
    long address;
    while (scanf("%ld", &address)) {
        printf("Datum: %d\n", *(int *) address);
        printf("> ");
    }
    return EXIT_SUCCESS;
}
