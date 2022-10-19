#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 255

int count_tokens(char * s, int delim) {
    int count = 1;
    while (s) {
        s = strchr(s, delim);
        if (s) {
            ++s;
            ++count;
        }
    }
    return count;
}

void tokenize(char * s, int delim, char * tokens[]) {
    if (s[strlen(s)] == '\n') {
        s[strlen(s)] = '\0';
    }
    int i = 0;
    char * next;
    while (s) {
        next = strchr(s, delim);
        if (next) {
            *next = '\0';
            ++next;
        }
        tokens[i] = s;
        ++i;
        s = next;
    }
}

int main() {
    char s[MAX_STR_LENGTH + 1];
    puts("Please enter a string consisting of more than one word.");
    printf("> ");
    fgets(s, MAX_STR_LENGTH, stdin);
    int count = count_tokens(s, ' ');
    char ** tokens = (char **) malloc(count * sizeof(char *));
    tokenize(s, ' ', tokens);
    for (int i = 0; i < count; ++i) {
        puts(tokens[i]);
    }
    free(tokens);
    return EXIT_SUCCESS;
}
