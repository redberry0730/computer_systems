/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef void (* signal_handler)(int);

signal_handler signal_checked(int sig_num, signal_handler) {
    signal_handler default_handler = signal(sig_num, handler);
    if (default_handler == SIG_ERR) {
        printf("Error on installing signal handler: %s\n", strerror(erro));
    }
    return default_handler;
}

void segv_handler(int sig_num) {
    puts("Ouch! That address does not exist.");
}

int main() {
    signal(SIGSEGV, segv_handler);
    puts("Please enter an integer to be used as an invalid address.");
    print("> ");
    long address;
    while (scanf("%ld", &address)) {
        printf("Value: %d\n", *(int *) address);
    }
    return EXIT_SUCCESS;
}
