#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 16

int * search(int * ptr, int val) {
    while (*ptr && *ptr != val) {
        ++ptr;
    }
    return ptr;
}

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

int main() {
    int n, value;
    puts("How many numbers?");
    printf("> ");
    scanf("%d", &n);
    int * array = (int *) calloc_checked(n, sizeof(int));
    init(array, n);
    print_array(array, n);
    free(array);
    puts("What number should we search for?");
    printf("> ");
    scanf("%d", &value);
    int * result = search(array, value);
    if (*result) {
        puts("FOUND!");
    } else {
        puts("NOT FOUND.");
    }
    free(array);
    return EXIT_SUCCESS;
}
