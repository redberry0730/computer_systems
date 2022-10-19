/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>

#include "pa2.h"

void print_bits(unsigned INT_TYPE value, int length) {
    int shift = length - 1;
    unsigned INT_TYPE mask = ONE << shift;
    while (mask) {
        putchar(((value & mask) >> shift) + '0');
        mask >>= 1;
        --shift;
    }
    putchar('\n');
}

void print_fields(Converter input) {
        printf("%f\n", input.f);
        printf("All bits: ");
        print_bits(input.u, sizeof(input.u) * BITS_PER_BYTE);
        printf("Sign: ");
        print_bits(input.components.sign, SIGN_LENGTH);
        printf("Exponent: ");
        print_bits(input.components.exponent, EXPONENT_LENGTH);
        printf("Mantissa: ");
        print_bits(input.components.mantissa, MANTISSA_LENGTH);
}

void print_normalized(Components input) {
    int sign = input.sign ? -1 : 1;
    int true_exponent = input.exponent - BIAS;
    FP_TYPE multiplier;
    if (true_exponent >= 0) {
        multiplier = (FP_TYPE) (ONE << true_exponent);
    } else {
        multiplier = 1.0;
        for (int i = 0; i > true_exponent; --i) {
            multiplier /= 2.0;
        }
    }
    FP_TYPE mantissa_value = (FP_TYPE) input.mantissa;
    for (int i = 0; i < MANTISSA_LENGTH; ++i) {
        mantissa_value /= 2.0;
    }
    FP_TYPE value = sign * ((1.0 + mantissa_value) * multiplier);
    printf("Original value: (-1)^{%u} x (1 + %f) x 2^{%u - %u} = %.45f\n",
            input.sign, mantissa_value, input.exponent, BIAS, value);
}

void print_denormalized(Components input) {
    int sign = input.sign ? -1 : 1;
    if (! input.mantissa) {
        printf("Original value: %s0.0\n",
                input.sign ? "-" : "");
        return;
    }
    FP_TYPE mantissa_value = (FP_TYPE) input.mantissa; 
    for (int i = 0; i < MANTISSA_LENGTH; ++i) {
        mantissa_value /= 2.0;
    }
    int exponent = (1 - BIAS);
    FP_TYPE value = mantissa_value;
    for (int i = 0; i > exponent; --i) {
        value /= 2.0;
    }
    value = sign * value;
    printf("Original value: (-1)^{%u} x %.45f x 2^{1 - %u} = %.45f\n",
            input.sign, mantissa_value, BIAS, value);
}

void print_reconstitution(Components input) {
    if (input.exponent) {
        print_normalized(input);
    } else {
        print_denormalized(input);
    }
}

