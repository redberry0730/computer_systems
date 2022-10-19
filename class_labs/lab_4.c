/*
* Authors)
* - Yeon Jae Cho (Skyler) - chonw@bc.edu
* - Jaime Colon - colonjg@bc.edu
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f2(int x){
  printf("f2 stack: \t%p", &x);
  printf("   %d\n", x);
}

void f1(int x){
  printf("f1 stack: \t%p", &x);
  printf("   %d\n", x);
  f2(x);
}

void heap_addrs(){
  char* sides ="5";
  char* temp = (char *)malloc((strlen(sides)+1)*sizeof(char));
  printf("Address of value of argument: %p\n", temp);
  printf("Char address of local variable: %p\n", &temp);

  char x_string[8] = {0};
  printf("Address of value of string: %p\n", x_string);
  printf("Char address of local variable for x_string: %p\n", &x_string);
}

int f3(int x, int *y){
  x = 19;
  *y = 19;
  return x+*y;
}

void f4(void (* func)(int)){
  func(37);

}

int main (int argc, char *argv[]){
  int in = 17;
  int out;

  printf("Argc: \t\t%p\n", &argc);
  printf("Argv address: \t%p\n", &argv);
  printf("Argv: \t\t%p\n", argv);
  f1(3);
  f2(3);

  heap_addrs();
  printf("Results from f3: ");
  printf("%d %d %d\n", in, out, f3(in, &out));
  printf("Calling func with a function pointer ...\n");

  f4(&f1);

  return EXIT_SUCCESS;
}
