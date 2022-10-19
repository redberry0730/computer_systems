#include <stdio.h>
#include <stdlib.h>

#define UPPER_BOUND 16

int * get_space() {
    int space;
    return &space;
}

int guess(int num, int value) {
    int success = 0;
    if (num == value) {
        success = 1;
    }
    return success;
}

int main() {
    puts("Enter a number.");
    printf("> ");
    int * space = get_space();
    scanf("%d", space);
    printf("You entered %d.\n", *space);
    if (guess(*space, 19)) {
        puts("We guessed correctly!  You entered 19!");
    } else {
        printf("Your original value of %d was not what we guessed.\n", *space);
    }
    return EXIT_SUCCESS;
}
