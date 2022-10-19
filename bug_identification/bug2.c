#include <stdio.h>
#include <stdlib.h>

#define DIM 16
#define VALUE_UPPER_BOUND 16

/*
 *  * Computes y = ax and returns it as an out-parameter.
 *   * a is a dim-by-dim matrix.
 *    * x and y are column vectors of dimension dim.
 *     */
void multiply_matrix_vector(int dim, int * a, int * x, int * y) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            y[i] += a[i * dim + j] * x[j];
        }
    }
}

void init_vector(int dim, int * v) {
    for (int i = 0; i < dim; ++i) {
        v[i] = rand() % VALUE_UPPER_BOUND;
    }
}

void init_matrix(int dim, int * m) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            m[i * dim + j] = rand() % VALUE_UPPER_BOUND;
        }
    }
}

void print_vector(int dim, int * v) {
    for (int i = 0; i < dim; ++i) {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

void print_matrix(int dim, int * m) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            printf("%d ", m[i * dim + j]);
        }
        putchar('\n');
    }
}

void other_function(int dim) {
    int * y = (int *) malloc(dim * sizeof(int));
    for (int i = 0; i < dim; ++i) {
        y[i] = -rand();
    }
    free(y);
}

int main() {
    other_function(DIM);
    int * y = (int *) malloc(DIM * sizeof(int));
    int * a = (int *) malloc(DIM * DIM * sizeof(int));
    int * x = (int *) malloc(DIM * sizeof(int));
    init_matrix(DIM, a);
    init_vector(DIM, x);
    multiply_matrix_vector(DIM, a, x, y);
    print_matrix(DIM, a);
    print_vector(DIM, x);
    print_vector(DIM, y);
    free(x);
    free(a);
    free(y);
    return EXIT_SUCCESS;
}


