/*
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define FP_TYPE float
#define TYPE_SIZE (sizeof(FP_TYPE) * BYTE_SIZE)
#define INT_TYPE int
#define FORMAT_STRING "%f"
#define U_ONE 1u
#define SIGN_SIZE 1
#define EXPONENT_SIZE 8
#define MANTISSA_SIZE (TYPE_SIZE - EXPONENT_SIZE - SIGN_SIZE)
#define BIAS ((1u << (EXPONENT_SIZE - 1)) -1)
#define BYTE_SIZE 8

union Converter {
    FP_TYPE f;
    unsigned INT_TYPE u;
    struct{
        unsigned INT_TYPE mantissa : MANTISSA_SIZE;
        unsigned INT_TYPE exponent : EXPONENT_SIZE;
        unsigned INT_TYPE sign : SIGN_SIZE;
    } fields;
};

void print_normalized(union Converter converter){
    unsigned INT_TYPE exponent;
    unsigned INT_TYPE mantissa;
    FP_TYPE m = (FP_TYPE) mantissa;
    for (int i = 0; i < MANTISSA_SIZE; ++i){
        m /= 2.0;
    }
    exponent -= BIAS;
    if (exponent > 0){
        FP_TYPE multiplier = (U_ONE << (EXPONENT_SIZE - 1)) - BIAS;
    }
    else{
        multiplier = (FP_TYPE)1.0;
        exponent = -exponent;
        for (int i = 0; i < exponent; ++i){
            multiplier /= 2.0;
        }
    }
    FP_TYPE value = (1.0 + m) * multiplier;
    if (conver.fields.sign){
        value = -value;
    }
    printf();


}

void print_bits(unsigned INT_TYPE input, unsigned INT_TYPE size) {
    unsigned int mask = U_ONE << (size - 1);
    while (mask) {
        putchar((!(! (input & mask))) + '0');
        mask >>= 1;
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
    printf(" (Decimal: %d - True exponent: %d)", input.fields.exponent, input.fields.exponent - BIAS);
    putchar('\n');
    fputs("Mantissa: ", stdout);
    print_bits(input.fields.mantissa, MANTISSA_SIZE);
    putchar('\n');
}

int main() {
    puts("Please enter a floating-point number or \"q\" to quit.");
    printf("> ");
    union Converter value_float;
    while (scanf(FORMAT_STRING, &value_float.f)) {
        print_fields(value_float);
        printf("> ");
    }
    return EXIT_SUCCESS;
}
