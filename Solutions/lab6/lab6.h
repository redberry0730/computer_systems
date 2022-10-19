/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#define BYTE_SIZE 8

#define FLOAT

#ifdef FLOAT
#define FP_TYPE float
#define FORMAT_STRING "%d %f"
#define U_ONE 1u
#define INT_TYPE int
#define EXPONENT_SIZE 8
#else
#define FP_TYPE double
#define FORMAT_STRING "%d %lf"
#define U_ONE 1ul
#define INT_TYPE long
#define EXPONENT_SIZE 11
#endif

#define TYPE_SIZE (sizeof(FP_TYPE) * BYTE_SIZE)
#define SIGN_SIZE 1
#define MANTISSA_SIZE (TYPE_SIZE - SIGN_SIZE - EXPONENT_SIZE)
#define BIAS ((1u << (EXPONENT_SIZE - 1)) - 1)

union Converter {
    FP_TYPE f;
    unsigned INT_TYPE u;
    struct {
        unsigned INT_TYPE mantissa : MANTISSA_SIZE;
        unsigned INT_TYPE exponent : EXPONENT_SIZE;
        unsigned INT_TYPE sign : SIGN_SIZE;
    } fields;
};

void print_bits(unsigned INT_TYPE input, unsigned int size);

void print_fields(union Converter input);
