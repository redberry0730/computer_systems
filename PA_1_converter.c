/*
 * "Unit Converter"
 * This program converts the temperature, length, and mass values given by the user
 * between US Customary and Metric system units, in either direction.
 * Author: Yeon Jae Cho (Skyler) - chonw@bc.edu
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_C 1.0936
#define MASS_C 2.2046
#define MAX_ARRAY 3
#define T_DENOMINATOR 9.0
#define T_NUMERATOR 5.0
#define ZERO_F 32.0

typedef enum Measure {LENGTH, MASS, TEMPERATURE} Measure;
typedef enum Operator {MULTIPLY, DIVIDE} Operator;
typedef enum System {METRIC, CUSTOMARY} System;

double f_to_c(double x) {
    double result = (x - ZERO_F) * (T_NUMERATOR / T_DENOMINATOR);
    return result;
}

double c_to_f(double x) {
    double result = x * (T_DENOMINATOR / T_NUMERATOR) + ZERO_F;
    return result;
}

void str_to_lower(char * x) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        x[i] = tolower(x[i]);
    }
}

double apply(double value, Operator Operator, double factor) {
    if (Operator == MULTIPLY) {
        return value * factor;
    }
    else {
        return value / factor;
    }
}

double convert(double value, Measure Measure, System System) {
    double factor;
    Operator Operator;
    switch (Measure) {
        case TEMPERATURE:
            if (System == METRIC) {
                return c_to_f(value);
            }
            else {
                return f_to_c(value);
            }
            break;
        case MASS:
            factor = MASS_C;
            break;
        case LENGTH:
            factor = LENGTH_C;
            break;
        default:
            fprintf(stderr, "Invalid measure value: %d\n", Measure);
            EXIT_FAILURE;
    }
    if (System == METRIC) {
        Operator = MULTIPLY;
    }
    else {
        Operator = DIVIDE;
    }
    return apply(value, Operator, factor);
}

double convert_from_tokens(double value, char * unit, char ** output_unit) {
    System System;
    Measure Measure;
    if (strcmp(unit, "F") && strcmp(unit, "C")) {
        str_to_lower(unit);
    }
    if (! strcmp(unit, "C")) {
        Measure = TEMPERATURE;
        *output_unit = "F";
        System = METRIC;
        return convert(value, Measure, System);
    }
    else if (! strcmp(unit, "F")) {
        Measure = TEMPERATURE;
        *output_unit = "C";
        System = CUSTOMARY;
        return convert(value, Measure, System);
    }
    else if (! strcmp(unit, "kg")) {
        Measure = MASS;
        *output_unit = "lb";
        System = METRIC;
        return convert(value, Measure, System);
    }
    else if (! strcmp(unit, "lb")) {
        Measure = MASS;
        *output_unit = "kg";
        System = CUSTOMARY;
        return convert(value, Measure, System);
    }
    else if (! strcmp(unit, "m")) {
        Measure = LENGTH;
        *output_unit = "yd";
        System = METRIC;
        return convert(value, Measure, System);
    }
    else if (! strcmp(unit, "yd")) {
        Measure = LENGTH;
        *output_unit = "m";
        System = CUSTOMARY;
        return convert(value, Measure, System);
    }
    else {
        printf("Invalid unit: %s", unit);
        return NAN;
    }
}

int main() {
    double value;
    char unit[MAX_ARRAY];
    char * output_unit;
    puts("Please enter a temperature, length, or mass, as a decimal numeral, followed by a unit to be converted:");
    puts("- F, lb, yd, C, kg, or m");
    puts("Enter \"q\" to quit.");
    printf("> ");
    while (scanf("%lf %s", &value, unit)) {
        double converted = convert_from_tokens(value, unit, &output_unit);
        if (! isnan(converted)) {
            printf("%.2lf %s = %.2lf %s\n", value, unit, converted, output_unit);
            printf("> ");
        }
        else {
            printf("\n> ");
            continue;
        }
    }
    return EXIT_SUCCESS;
}
