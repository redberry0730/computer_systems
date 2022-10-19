/*
 * Cache Locality
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define DIM 512
#define MAX_VALUE 20
#define FALSE 0
#define TRUE 1

void multiply(const int dim, const int * const a, const int * const b, int * c) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            c[i * dim + j] = 0;
            for (int k = 0; k < dim; ++k) {
                c[i * dim + j] += a[i * dim + k] * b[k * dim + j];
            }
        }
    }
}

void multiply_transpose(const int dim, const int * const a, const int * const b_t, int * c) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            c[i * dim + j] = 0;
            for (int k = 0; k < dim; ++k) {
                c[i * dim + j] += a[i * dim + k] * b_t[j * dim + k];
            }
        }
    }
}

void transpose(const int dim, int * m) {
    for (int i = 1; i < dim; ++i) {
        for (int j = 0; j < i; ++j) {
            int tmp = m[i * dim + j];
            m[i * dim + j] = m[j * dim + i];
            m[j * dim + i] = tmp;
        }
    }
}

void print(const int dim, const int * const m) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            printf("%d ", m[i * dim + j]);
        }
        putchar('\n');
    }
}

void init(const int dim, int * m) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            m[i * dim + j] = rand() % MAX_VALUE;
        }
    }
}

struct timeval run_and_time(
        void (* mult_func)(const int, const int * const, const int * const, int *), 
        const int dim,
        const int * const a,
        const int * const b,
        int * c
        ) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    mult_func(dim, a, b, c);
    gettimeofday(&end, NULL);
    struct timeval results;
    results.tv_sec = end.tv_sec - start.tv_sec;
    results.tv_usec = end.tv_usec - start.tv_usec;
    if (results.tv_usec < 0) {
        --results.tv_sec;
        results.tv_usec += 1000000;
    }
    return results;
}

int verify(const int dim, const int * const c1, const int * const c2) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            if (c1[i * dim + j] != c2[i * dim + j]) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void run_test(const int dim) {
    int * a = (int *)calloc(dim * dim, sizeof(int));
    int * b = (int *)calloc(dim * dim, sizeof(int));
    int * c1 = (int *)calloc(dim * dim, sizeof(int));
    int * c2 = (int *)calloc(dim * dim, sizeof(int));
    init(dim, a);
    init(dim, b);
    struct timeval result1 = run_and_time(&multiply, dim, a, b, c1);
    transpose(dim, b);
    struct timeval result2 = run_and_time(&multiply_transpose, dim, a, b, c2);
    int agree = verify(dim, c1, c2);
    if (agree) {
        printf("Results agree.\n");
    } else {
        fprintf(stderr, "Error: results do not agree.\n");
    }
    printf("Standard multiplication: %ld seconds, %d microseconds\n",
            (long) result1.tv_sec, (int) result1.tv_usec);
    printf("Multiplication with transpose: %ld seconds, %d microseconds\n",
            (long) result2.tv_sec, (int) result2.tv_usec);
    free(c2);
    free(c1);
    free(b);
    free(a);
}

int main() {
    run_test(DIM);
    return EXIT_SUCCESS;
}

