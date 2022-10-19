#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 5
#define SUCCESS 0
#define FAILURE -1

void populate(int n, int * array) {
    for (int i = 0; i < n; ++i) {
        array[i] = 1 << i;
    }
}

void print_array(int n, int * array) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int check_num(int num) {
    if (num < MIN_SIZE) {
       return FAILURE;
    }
   return SUCCESS;
} 

int main() {
    int num;
    printf("Please enter an integer not less than %d.\n", MIN_SIZE);
    printf("> ");
    scanf("%d", &num);
    int * array = (int *) calloc(check_num(num), sizeof(int));
    populate(num, array);
    print_array(num, array);
    return 0;
}

