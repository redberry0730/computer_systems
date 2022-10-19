/*
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void file_error(const char * const file_name) {
    fprintf(stderr, "Could not open file %s\n", file_name);
    exit(EXIT_FAILURE);
}

void write_small_random_numbers(int num, const char * const file_name) {
    FILE * fp = fopen(file_name, "w");
    if (! fp) {
        file_error(file_name);
    }
    for (int i = 0; i < num; i++) {
        fputc((rand() % 10) + '0', fp);
    }
    fclose(fp);
}

void read_small_numbers(const char * const file_name) {
    FILE * fp = fopen(file_name, "r");
    if (! fp) {
        file_error(file_name);
    }
    while (1) {
        int c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        else {
            printf("%c", c);
        }
    }
    fclose(fp);
}

int get_byte_count(const char * const file_name) {
    FILE * fp = fopen(file_name, "r");
    if (! fp) {
        file_error(file_name);
    }
    fseek(fp, 0, SEEK_END);
    int count = ftell(fp);
    fclose(fp);
    return count;
}

int main() {
    const char * const file_name = "small_numbers.txt";
    write_small_random_numbers(100, file_name);
    read_small_numbers(file_name);
    int x = get_byte_count(file_name);
    printf("Byte Count: %d", x);
    int * nums = (int *) calloc(count, sizeof(int));
    read_small_numbers(count, file_name, nums);
    for (int i = 0; i < count; i++) {
        putchar(nums[i] + '0');
    }
    free(nums);
    return EXIT_SUCCESS;
}
