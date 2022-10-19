/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 255

pid_t fork_checked() {
    pid_t child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "Error in fork: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return child_pid;
}

pid_t waitpid_checked(pid_t child_pid, int * child_status, int options) {
    pid_t joined_pid = waitpid(child_pid, child_status, options);
    if (joined_pid == -1) {
        fprintf(stderr, "Error in waitpid: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return joined_pid;
}

void run(const char * path) {
    pid_t child_pid = fork();
    if (! child_pid) {
        char ** const argv = NULL;
        char ** const envp = NULL;
        execve(path, argv, envp);
        puts("YO!");
    }
    int child_status;
    pid_t joined_pid = waitpid(child_pid, &child_status, 0);
    if (joined_pid != child_pid) {
        printf("Unexpected child PID: %d. Expected PID: %d\n", joined_pid, child_pid);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        scanf("%s", command);
    }
    return EXIT_SUCCESS;
}
