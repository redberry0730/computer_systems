#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 16

int main() {
    char s[MAX_STR_LEN];
    puts("Please enter a string.");
    scanf("%s", s);
    printf("Length of input: %ld\n", strlen(s));
    return EXIT_SUCCESS;
}
