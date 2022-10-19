/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include "mem_alloc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    mem_init();
    char * x = (char *)mem_alloc(20 * sizeof(char));
    print_list();
    puts("");
    mem_free(x);
    char * y = (char *)mem_alloc(20 * sizeof(char));
    print_list();
    puts("");
    mem_free(y);
    (char *) mem_alloc(20 * sizeof(char));
    print_list();
    puts("");
    (char *) mem_alloc(20 * sizeof(char));
    print_list();
    puts("");
    (char *) mem_alloc(20 * sizeof(char));
    print_list();
    puts("");
    (int *) mem_alloc(1000 * sizeof(int));
    print_list();
    puts("");
    int * z = (int *) mem_alloc(1000 * sizeof(int));
    print_list();
    puts("");
    print_header(x);
    puts("");
    print_header(z);
    return EXIT_SUCCESS;
}
