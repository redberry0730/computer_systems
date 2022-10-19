/*
 * This program compares the values between two different matrices and measures the time it took to create them.
 * It returns the time it takes to create them (in seconds and microseconds) and whether their values match or not.
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define MAX_VALUE 20
#define DIM 1024
#define TRUE 1
#define FALSE 0

void multiply(const int dim, const int * const a, const int * const b, int * c);
void multiply_transpose(const int dim, const int * const a, const int * const b_t, int * c);
void transpose(const int dim, int * m);
void print(const int dim, const int * const m);
void init(const int dim, int * m);
struct timeval run_and_time(
void (* mult_func)(const int, const int * const, const int * const, int *),
const int dim,
const int * const a,
const int * const b,
int * c
);
int verify(const int dim, const int * const c1, const int * const c2);
void run_and_test(const int dim);

void multiply(const int dim, const int * const a, const int * const b, int * c) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            c[i * dim + j] = 0;
            for (int k = 0; k < dim; k++) {
                c[i * dim + j] += a[i * dim + k] * b[k * dim + j];
            }
        }
    }
}

void multiply_transpose(const int dim, const int * const a, const int * const b_t, int * c) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            c[i * dim + j] = 0;
            for (int k = 0; k < dim; k++) {
                c[i * dim + j] += a[i * dim + k] * b_t[j * dim + k];
            }
        }
    }
}

void transpose(const int dim, int * m) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < i; j++) {
            int temp = m[i * dim + j];
            m[i * dim + j] = m[j * dim + i];
            m[j * dim + i] = temp;
        }
    }
}

void print(const int dim, const int * const m) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%d ", m[i * dim + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void init(const int dim, int * m) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
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
    mult_func(DIM, a, b, c);
    gettimeofday(&end, NULL);
    struct timeval result;
    result.tv_sec = (long)end.tv_sec - (long)start.tv_sec;
    result.tv_usec = (long)end.tv_usec - (long)start.tv_usec;
    if (result.tv_usec < 0) {
        --result.tv_sec;
        result.tv_usec += 1000000;
    }
    return result;
}

int verify(const int dim, const int * const c1, const int * const c2) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (c1[i * dim + j] != c2[i * dim + j]) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void run_and_test(const int dim) {
    int * dim_1 = (int *)calloc(DIM * DIM, sizeof(int));
    int * dim_2 = (int *)calloc(DIM * DIM, sizeof(int));
    int * dim_3 = (int *)calloc(DIM * DIM, sizeof(int));
    int * dim_4 = (int *)calloc(DIM * DIM, sizeof(int));
    init(DIM, dim_1);
    init(DIM, dim_2);
    multiply(DIM, dim_1, dim_2, dim_3);
    struct timeval no_transpose = run_and_time(&multiply, DIM, dim_1, dim_2, dim_3);
    transpose(DIM, dim_2);
    multiply_transpose(DIM, dim_1, dim_2, dim_4);
    int result = verify(DIM, dim_3, dim_4);
    if (result) {
        printf("The results agree.\n");
    }
    else {
        printf("Oops, the results do not agree.\n");
    }
    struct timeval yes_transpose = run_and_time(&multiply_transpose, DIM, dim_1, dim_2, dim_4);
    printf("Standard multiplication: %ld seconds, %ld microseconds\n", no_transpose.tv_sec, no_transpose.tv_usec);
    printf("Multiplication with transpose: %ld seconds, %ld microseconds\n", yes_transpose.tv_sec, yes_transpose.tv_usec);
    free(dim_1);
    free(dim_2);
    free(dim_3);
    free(dim_4);
}

int main() {
    run_and_test(DIM);
    return EXIT_SUCCESS;
}
