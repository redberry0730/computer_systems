/*
 * Converter
 * Converts units between Metric and US Customary systems
 * for lengths, weights, and temperatures, interactively.
 *
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNIT_LENGTH 8
#define M_TO_YD 1.093613
#define KG_TO_LB 2.20462262

typedef enum Measure { TEMP, LENGTH, MASS } Measure;
typedef enum System { METRIC, US_CUSTOMARY } System;
typedef enum Op { MULT, DIV } Op;


double centigrade(double fahrenheit) {
    return 5.0 * (fahrenheit - 32.0) / 9.0;
}

double fahrenheit(double centigrade) {
    return ((9.0 * centigrade) / 5.0) + 32.0;
}

double apply(double input, Op op, const double factor) {
    if (op == MULT) {
        return input * factor;
    } else {
        return input / factor;
    }
}

double convert(double input, Measure measure, System system) {
    double factor;
    switch(measure) {
        case TEMP:
            return (system == METRIC) ? fahrenheit(input) : centigrade(input);
        case LENGTH:
            factor = M_TO_YD;
            break;
        case MASS:
            factor = KG_TO_LB;
            break;
        default:
            fprintf(stderr, "Unrecognized measure category: %d\n", measure);
            exit(EXIT_FAILURE);
    }
    const Op op = (system == METRIC) ? MULT : DIV;
    return apply(input, op, factor);
}

void str_to_lower(char * string) {
    for (int i = 0; i < strlen(string); ++i) {
        string[i] = tolower((unsigned char) string[i]);
    }
}

double convert_from_tokens(double value, char * unit, char ** output_unit) {
    if (strcmp(unit, "F") && strcmp(unit, "C")) {
        str_to_lower(unit);
    }
    Measure measure;
    System system;
    if (! strcmp(unit, "yd") || ! strcmp(unit, "lb") || ! strcmp(unit, "F")) {
        system = US_CUSTOMARY;
        if (! strcmp(unit, "yd")) {
            measure = LENGTH;
            *output_unit = "m";
        } else if (! strcmp(unit, "lb")) {
            measure = MASS;
            *output_unit = "kg";
        } else {
            measure = TEMP;
            *output_unit = "C";
        }
    } else if (! strcmp(unit, "m") || ! strcmp(unit, "kg") || ! strcmp(unit, "C")) {
        system = METRIC;
        if (! strcmp(unit, "m")) {
            measure = LENGTH;
            *output_unit = "yd";
        } else if (! strcmp(unit, "kg")) {
            measure = MASS;
            *output_unit = "lb";
        } else {
            measure = TEMP;
            *output_unit = "F";
        }
    } else {
        printf("Invalid unit: %s\n", unit);
        return NAN;
    }
    return convert(value, measure, system);
}

int main() {
    double value;
    char unit[MAX_UNIT_LENGTH];
    char * output_unit;
    puts("Please enter a temperature, length, or mass, as a decimal numeral, ");
    puts("followed by a unit to be converted:");
    puts("- F, lb, yd, C, kg, or m");
    puts("Enter \"q\" to quit.");
    fputs("> ", stdout);
    while (scanf("%lf %s", &value, unit)) {
        double converted = convert_from_tokens(value, unit, &output_unit);
        if (! isnan(converted)) { 
            printf("%.2f %s = %.2f %s\n", value, unit, converted, output_unit);
        }
        fputs("> ", stdout);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
