/*
 * Floating-point Number Analyzer
 * The program receives a floating-point number and prints all of its bits on one line,
 * followed by the bit patterns of its three fields: sign, exponent, and mantissa.
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 */

#ifdef DOUBLE
#define FP_TYPE double
#define TYPE_SIZE (sizeof(FP_TYPE) * BYTE_SIZE)
#define INT_TYPE long
#define FORMAT_STRING "%lf"
#define U_ONE 1ul
#define SIGN_SIZE 1
#define EXPONENT_SIZE 11
#else
#define FP_TYPE float
#define TYPE_SIZE (sizeof(FP_TYPE) * BYTE_SIZE)
#define INT_TYPE int
#define FORMAT_STRING "%f"
#define U_ONE 1u
#define SIGN_SIZE 1
#define EXPONENT_SIZE 8
#endif
#define MANTISSA_SIZE (TYPE_SIZE - EXPONENT_SIZE - SIGN_SIZE)
#define BIAS ((1u << (EXPONENT_SIZE - 1)) - 1)
#define BYTE_SIZE 8

union Converter {
    FP_TYPE f;
    unsigned INT_TYPE u;
    struct {
        unsigned INT_TYPE mantissa : MANTISSA_SIZE;
        unsigned INT_TYPE exponent : EXPONENT_SIZE;
        unsigned INT_TYPE sign : SIGN_SIZE;
    } fields;
};

void print_bits(unsigned INT_TYPE input, int size);
void print_fields(union Converter input);
void print_normalized(union Converter input);
void print_denormalized(union Converter input);
void reconstitution(union Converter input);
