/*
 * This program receives two integers, divides the first integer by the second integer,
 * and returns a quotient and a remainder. The assembly code has been edited to improve its efficiency.
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

int div_qr(int dividend, int divisor, int * remainder);

int main() {
    puts("Please enter an integer dividend and divisor, or \"q\" to quit.");
    printf("> ");
    int x, y;
    while (scanf("%d %d", &x, &y)) {
    	if (y==0) {
            printf("\n> ");
    	    printf("Division by 0 is undefined.");
    	}
    	else {
            int remainder;
            int quotient = div_qr(x, y, &remainder);
            printf("%d / %d = %d, r %d", x, y, quotient, remainder);
            printf("\n> ");
    	}
    }
    return EXIT_SUCCESS;
}
