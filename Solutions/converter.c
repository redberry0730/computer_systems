/*
 * Author: Amittai Aviram - aviram@bc.edu
 */
#include <stdio.h>
#include <stdlib.h>

double celsius_to_fahrenheit(double celsius) {
    return (9.0 * celsius) / 5.0 + 32.00;
}

void usage() {
    printf("Please enter a temperature Celsius.\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        usage();
    }
    double celsius = strtod(argv[1], NULL);
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, celsius_to_fahrenheit(celsius));

    return EXIT_SUCCESS;
}
