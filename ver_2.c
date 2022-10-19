/*
 * Please complete the C code below. This program
 * repeatedly takes an integer entered by the user
 * and, if the value fits into 8 bits unsigned,
 * prints the _parity_ of the input.  The parity
 * is 0 if the number of 1s in the bit representation
 * of the input is even and 1 if it is odd.
 * Complete the code by replacing the
 * body of the parity function with an appropriate
 * implementation.
 *
 *
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

int parity(unsigned char input) {
    int result = 0;
    while (input){
        result = !result;
        input = input & (input - 1);
    }
    return result;
}

int main() {
    puts("Please enter an integer, or \"q\" to quit.");
    fputs("> ", stdout);
    int input;
    while (scanf("%d", &input)) {
        if (input < 0x100) {
            printf("Parity: %d\n", parity(input));
        }
        fputs("> ", stdout);
    }
    return EXIT_SUCCESS;
}












//
