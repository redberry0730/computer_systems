/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

char decode(int count, int set_bits[]) {
    char output = 0;
    for (int i = 0; i < count; ++i) {
        output |= (1 << set_bits[i]);
    }
    return output;
}

void read_and_decode_file(char * file_name) {
    FILE * in = fopen(file_name, "r");
    if (! in) {
        fprintf(stderr, "Failed to open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    int bits[8];
    int count;
    int numeral;
    while ((numeral = fgetc(in)) != EOF) {
        count = numeral - '0';
        for (int i = 0; i < count; ++i) {
            numeral = fgetc(in);
            if (numeral == EOF) {
                fprintf(stderr, "Error reading input file.\n");
                exit(EXIT_FAILURE);
            }
            bits[i] = numeral - '0';
        }
        putchar(decode(count, bits));
    }
    fclose(in);
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please enter an input file name.\n");
        exit(EXIT_FAILURE);
    }
    read_and_decode_file(argv[1]);
    return EXIT_SUCCESS;
}

