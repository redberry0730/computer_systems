#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 8

union Converter {
    float f;
    unsigned int u;
};

void print_bits(unsigned int input, unsigned int size) {
    unsigned mask = 1u << (size - 1);
    while (mask) {
        putchar((! (! (input & mask))) + '0');
        mask >>= 1;
    }
    putchar('\n');
}

int main() {
    int value_int;
    union Converter value_float;
    puts("Please enter an integer and a floating-point number, or \"q\" to quit.");
    printf("> ");
    while (scanf("%d %f", &value_int, &value_float.f)) {
        printf("%d\n", value_int);
        print_bits(value_int, sizeof(value_int) * BYTE_SIZE);
        printf("%f\n", value_float.f);
        print_bits(value_float.u, sizeof(float) * BYTE_SIZE);
        printf("> ");
    }
    return EXIT_SUCCESS;
}
