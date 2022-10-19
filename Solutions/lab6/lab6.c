/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

#include "lab6.h"

void print_bits(unsigned INT_TYPE input, unsigned int size) {
    unsigned int shift = size - 1;
    unsigned INT_TYPE mask = U_ONE << shift;
    while (mask) {
        // putchar(((input & mask) >> shift) + '0');
        putchar((! (! (input & mask))) + '0');
        mask >>= 1;
        --shift;
    }
}

void print_fields(union Converter input) {
    fputs("Sign: ", stdout);
    print_bits(input.fields.sign, SIGN_SIZE);
    putchar('\n');
    fputs("Exponent: ", stdout);
    print_bits(input.fields.exponent, EXPONENT_SIZE);
    printf(" (Decimal: %d - True exponent: %d)\n",
            input.fields.exponent, input.fields.exponent - BIAS);
    fputs("Mantissa: ", stdout);
    print_bits(input.fields.mantissa, MANTISSA_SIZE);
    putchar('\n');
}
