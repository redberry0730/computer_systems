/*
 * Floating-point Number Analyzer
 * The program receives a floating-point number and prints all of its bits on one line,
 * followed by the bit patterns of its three fields: sign, exponent, and mantissa.
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 */

#include "pa2.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    puts("Please enter a floating-point number or q to quit.");
    printf("> ");
    union Converter value_float;
    while (scanf(FORMAT_STRING, &value_float.f)) {
        print_fields(value_float);
        reconstitution(value_float);
        printf("> ");
    }
    return EXIT_SUCCESS;
}
