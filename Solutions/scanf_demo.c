#include <stdio.h>
#include <stdlib.h>

double fake(double value, char unit, char * output_unit) {
    if (unit == 'C') {
        *output_unit = 'F';
    } else if (unit == 'F') {
        *output_unit = 'C';
    } else {
        *output_unit = 'X';
    }
    return value * 2.0;
}


int main() {
    double value;
    char unit;

    puts("Please enter a temperature and a unit, or \"q\" to quit.");
    printf("> ");
    while(scanf("%lf %c", &value, &unit)) {
        char output_unit;
        double output_value = fake(value, unit, &output_unit);
        printf("%.2f %.2f %c %c\n", value, output_value, unit, output_unit);
        printf("> ");
    }
    puts("Done!");
    return EXIT_SUCCESS;
}

