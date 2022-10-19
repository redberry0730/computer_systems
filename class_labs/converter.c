/******************************************************************************
Temperature Converter
Takes in a Celsius/Fahrenheit temperature and converts to the other one.
Authors)
- Jaime Colon: colonjg@bc.edu
- Yeon Jae Cho (Skyler): chonw@bc.edu
- Lupita Peralta: peraltlu@bc.edu
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double convert_toF(double x){
  double y = x*(9.0/5.0) + 32;
  return y;
}

double convert_toC(double x){
  double y = (x-32)*(5.0/9.0);
  return y;
}

double convert(double value, char unit, char * output_unit){
  if (unit=='C'){
    value = convert_toF(value);
    *output_unit = 'F';
  }
  else if (unit=='F'){
    value = convert_toC(value);
    *output_unit = 'C';
  }
  else{
    *output_unit = 'X';
  }
  return value;
}

int main (){
  double value;
  char unit;

  puts("Please enter a temperature in C or F, or \"q\" to quit.");
  printf("> ");

  while(scanf("%lf %c", &value, &unit)){
    char output_unit;
    double output_value = convert(value, unit, &output_unit);

    if (output_unit!='X'){
      printf("%.2lf %c = %.2lf %c\n", value, unit, output_value, output_unit);
      printf("> ");
    }
    else{
      printf("> ");
      continue;
      }
    }
    return EXIT_SUCCESS;
}
