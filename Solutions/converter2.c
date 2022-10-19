/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double celsius_to_fahrenheit(double celsius) {
    return (9.0 * celsius) / 5.0 + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (5.0 * (fahrenheit - 32.0)) / 9.0;
}

void usage() {
    printf("Please enter a temperature Celsius.\n");
    exit(EXIT_FAILURE);
}

double convert(double value, char unit, char * output_unit) {
    if (unit == 'C') {
        *output_unit = 'F';
        return celsius_to_fahrenheit(value);
    } else if (unit == 'F') {
        *output_unit = 'C';
        return fahrenheit_to_celsius(value);
    } else {
        return NAN;
    }
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        usage();
    }
    double celsius = strtod(argv[1], NULL);
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, celsius_to_fahrenheit(celsius));

    double value;
    char unit;
    char output_unit;

    puts("Please enter a temperature C or F, or \"q\" to quit.");
    fputs("> ", stdout);
    while (scanf("%lf %c", &value, &unit)) {
        double converted = convert(value, unit, &output_unit);
        if (! isnan(converted)) {
            printf("%.2f %c = %.2f %c\n", value, unit, converted, output_unit);
        }
        fputs("> ", stdout);
    }

    return EXIT_SUCCESS;
}
