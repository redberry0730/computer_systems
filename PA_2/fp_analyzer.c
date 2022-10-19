/*
 * Floating-point Number Analyzer
 * The program receives a floating-point number and prints all of its bits on one line,
 * followed by the bit patterns of its three fields: sign, exponent, and mantissa.
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 */

#include "pa2.h"

#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned INT_TYPE input, int size) {
    unsigned INT_TYPE mask = U_ONE << (size - 1);
    while (mask) {
        putchar((!(! (input & mask))) + '0');
        mask >>= 1;
    }
}

void print_normalized(union Converter input) {
    int new_sign;
    if (input.fields.sign == 1) {
        new_sign = -1;
    }
    else {
        new_sign = 1;
    }
    int true_exponent = input.fields.exponent - BIAS;
    FP_TYPE multiplier;
    if (true_exponent >= 0) {
        multiplier = (FP_TYPE)(U_ONE << true_exponent);
    }
    else {
        multiplier = 1.0;
        for (int i = 0; i > true_exponent; --i) {
            multiplier /= 2.0;
        }
    }
    FP_TYPE mantissa_value = (FP_TYPE) input.fields.mantissa;
    for (int i = 0; i < MANTISSA_SIZE; ++i) {
        mantissa_value /= 2.0;
    }
    FP_TYPE value = new_sign * ((1.0 + mantissa_value) * multiplier);
    printf("Original value: (-1)^{%u} x (1 + %f) x 2^{%u - %u} = %.45f\n",
    input.fields.sign, mantissa_value, input.fields.exponent, BIAS, value);
}

void print_denormalized(union Converter input) {
    int new_sign;
    if (input.fields.sign == 1) {
        new_sign = -1;
    }
    else {
        new_sign = 1;
    }
    if (! input.fields.mantissa) {
        printf("Original value: %s0.0\n", input.fields.sign ? "-" : "");
        return;
    }
    FP_TYPE mantissa_value = (FP_TYPE) input.fields.mantissa;
    for (int i = 0; i < MANTISSA_SIZE; ++i) {
        mantissa_value /= 2.0;
    }
    int exponent = 1 - BIAS;
    FP_TYPE value = mantissa_value;
    for (int i = 0; i > exponent; --i) {
        value /= 2.0;
    }
    value = new_sign * value;
    printf("Original value: (-1)^{%u} x %.45f x 2^{1 - %u} = %.45f\n",
    input.fields.sign, mantissa_value, BIAS, value);
}

void reconstitution(union Converter input) {
    if (input.fields.exponent == 0) {
        print_denormalized(input);
    }
    else {
        print_normalized(input);
    }
}

void print_fields(union Converter input) {
    printf("%f", input.f);
    putchar('\n');
    printf("All bits: ");
    print_bits(input.u, TYPE_SIZE);
    putchar('\n');
    fputs("Sign: ", stdout);
    print_bits(input.fields.sign, SIGN_SIZE);
    putchar('\n');
    fputs("Exponent: ", stdout);
    print_bits(input.fields.exponent, EXPONENT_SIZE);
    putchar('\n');
    fputs("Mantissa: ", stdout);
    print_bits(input.fields.mantissa, MANTISSA_SIZE);
    putchar('\n');
}
