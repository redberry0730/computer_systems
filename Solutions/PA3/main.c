/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

int div_qr(int, int, int *);

int main() {
    int dividend;
    int divisor;
    int remainder;
    puts("Please enter an integer dividend and divisor, or \"q\" to quit.");
    fputs("> ", stdout);
    while (scanf("%d %d", &dividend, &divisor)) {
        if (divisor) {
            int quotient = div_qr(dividend, divisor, &remainder);
            printf("%d / %d = %d, r %d\n", dividend, divisor, quotient, remainder);
        } else {
            puts("Division by 0 is undefined.");
        }
        fputs("> ", stdout);
    }
    return EXIT_SUCCESS;
}

