#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 16

void * calloc_checked(size_t num, size_t size) {
    void * mem = calloc(num, size);
    if (! mem) {
        fprintf(stderr, "Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    return mem;
}

void init(int * array, int n) {
    int i = 0;
    for (; i < n - 1; ++i) {
        array[i] = rand() % UPPER_BOUND;
    }
    array[i] = 0;
}

void print_array(int * array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void run_trials(int n, int reps) {
    for (int i = 0; i < reps; ++i) {
        int * array = (int *) calloc_checked(n, sizeof(int));
        init(array, n);
        print_array(array, n);
    }
}

int main() {
    int n, reps;
    puts("How many numbers?");
    printf("> ");
    scanf("%d", &n);
    puts("How many trials?");
    printf("> ");
    scanf("%d", &reps);
    run_trials(n, reps);
    return EXIT_SUCCESS;
}
