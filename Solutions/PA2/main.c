/*
 * Floating-Point Number Analyzer
 * Displays the components of a floating-point representation
 * and reconstructs the value based on the components.
 * 
 * Author: Amittai Aviram - aviram@bc.edu
 * Version: 2021-08-13
 */

#include <stdio.h>
#include <stdlib.h>

#include "pa2.h"


int main() {
    Converter input;
    printf("Please enter a floating-point number or q to quit.\n");
    printf("> ");
    while (scanf(INPUT_FORMAT, &input.f)) {
        print_fields(input);
        print_reconstitution(input.components);
        printf("> ");
    }
    return EXIT_SUCCESS;
}

