/*
 * Lab 4: Various experiments to explore data storage and parameter passing.
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>

void f2(int arg) {
    printf("f2 stack:\t%p\t%d\n", &arg, arg);
}

void f1(int arg) {
    printf("f1 stack:\t%p\t%d\n", &arg, arg);
    f2(7);
}

void heap_addrs() {
    char * c1 = malloc(sizeof(char));
    printf("c1:\t\t%p\t%p\n", c1, &c1);
    char * s1 = malloc(sizeof(char) * 8);
    printf("s1:\t\t%p\t%p\n", s1, &s1);
}

int f3(int x, int * y) {
    x = 31;
    *y = x;
    return x + *y;
}

void f4(void (* func)(int)) {
    func(37);
}

int main(int argc, char * argv[]) {
    printf("Argc:\t\t%p\n", &argc);
    printf("Argv address:\t%p\n", &argv);
    printf("Argv:\t\t%p\n", argv);
    f1(3);
    f2(11);
    heap_addrs();
    char * s2 = malloc(sizeof(char) * 8);
    printf("s2:\t\t%p\t%p\n", s2, &s2);
    int in = 41;
    int out;
    int ret = f3(in, &out);
    printf("Results from f3: %d %d %d\n", in, out, ret); 
    printf("Calling func with a function pointer ...\n");
    f4(&f1);

    return EXIT_SUCCESS;
}

