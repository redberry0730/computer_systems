#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define ARRAY_SIZE 100000
#define MAX_VALUE 100

long sum1(int length, int * nums) {
    long accum = 0l;
    for (int i = 0; i < length; i++){
        accum += nums[i];
    }
    return accum;
}

void run_and_time(long (* sum_func)(int, int*), int length, int * nums) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    long sum = sum_func(length, nums);
    gettimeofday(&end, NULL);
    printf("Execution time(seconds): %ld\n", (long) end.tv_sec - (long) start.tv_sec);
    printf("Execution time(micro-seconds): %ld\n", (long) end.tv_usec - (long) start.tv_usec);
    printf("Sum: %d\n", sum);
}

int main() {
    int * nums = (int *) calloc(ARRAY_SIZE, sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        nums[i] = rand() % MAX_VALUE;
    }
    run_and_time(&sum1, ARRAY_SIZE, nums);
    return EXIT_SUCCESS;
}
