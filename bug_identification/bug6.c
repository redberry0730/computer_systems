#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 8

/*
 * Searches for instances of key_1 or key_2 in array and returns the counts of 
 * instances of the two keys as out-parameters count_1 and count_2, respectively.
 */
void count_instances(int * array, int n, int key_1, int key_2, int * count_1, int * count_2) {
    *count_1 = *count_2 = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i] == key_1) {
            count_1++;
        } else if (array[i] == key_2) {
            count_2++;
        }
    }
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
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % UPPER_BOUND;
    }
}

int main() {
    int n, key_1, key_2;
    puts("How big an array should we test?");
    printf("> ");
    scanf("%d", &n);
    int * array = (int *) calloc_checked(n, sizeof(int));
    init(array, n);
    key_1 = rand() % UPPER_BOUND;
    key_2 = rand() % UPPER_BOUND;
    int count_1, count_2;
    count_instances(array, n, key_1, key_2, &count_1, &count_2);
    printf("%d occurs %d times in an array of %d random numbers in [0, %d).\n",
            key_1, count_1, n, UPPER_BOUND);
    printf("%d occurs %d times.\n",
            key_2, count_2);
    return EXIT_SUCCESS;
}

