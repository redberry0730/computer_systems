/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    printf("%d %s\n", argc, argv[0]);
    printf("%s\n", argv[0]);
    if (argc > 1) {
        printf("%s\n", argv[1]);
    }
    if (argc > 2) {
        printf("%s\n", argv[2]);
        int arg2 = atoi(argv[2]);
        printf("%d\n", arg2 * 2);
    }
    return EXIT_SUCCESS;
}

