/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab6.h"

int main() {
    int value_int;
    union Converter value_float;
    puts("Please enter an integer and a floating-point number, or \"q\" to quit.");
    printf("> ");
    while (scanf(FORMAT_STRING, &value_int, &value_float.f)) {
        printf("%d\n", value_int);
        print_bits(value_int, sizeof(value_int) * BYTE_SIZE);
        putchar('\n');
        printf("%f\n", value_float.f);
        print_bits(value_float.u, TYPE_SIZE);
        putchar('\n');
        print_fields(value_float);
        printf("> ");
    }
    return EXIT_SUCCESS;
}

