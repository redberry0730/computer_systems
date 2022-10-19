/*
 * enum_demo
 * Demonstration of the definition and use of enumeration types,
 * plus string storage and comparison techniques.
 *
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define NUM_STUDENTS 8

typedef enum Section { SECTION_1, SECTION_2, SECTION_UNKNOWN } Section;

const char * students_in_section_1[NUM_STUDENTS] = {
    "Ali",
    "Jameson",
    "Leena",
    "Caroline",
    "Anirudh",
    "Meagan",
    "Slok",
    "Lupita"
};

const char * students_in_section_2[NUM_STUDENTS] = {
    "Ryan",
    "Divya",
    "Salina",
    "Komi",
    "AJ",
    "Tyla",
    "Sami",
    "Joy"
};

Section find_section(char * name, char ** time) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (! strcmp(name, students_in_section_1[i])) {
            *time = "morning";
            return SECTION_1;
        }
    }
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (! strcmp(name, students_in_section_2[i])) {
            *time = "afternoon";
            return SECTION_2;
        }
    }
    return SECTION_UNKNOWN;
}

void print_section(char * name, Section section, char * time) {
    printf("%s is a student in ", name);
    switch (section) {
        case SECTION_1:
            printf("Section 1");
            break;
        case SECTION_2:
            printf("Section 2");
            break;
        default:
            printf("an unknown section");
    }
    if (section != SECTION_UNKNOWN){
      printf(", which meets in the %s\n". time);
    }
    puts(".");
}

int main() {
    puts("Please enter a name, or \"quit\" to quit.");
    fputs("> ", stdout);
    char name[MAX_NAME_LENGTH + 1];
    char * time;
    while (scanf("%s", name)) {
        if (! strcmp(name, "quit")) {
            break;
        }
        Section section = find_section(name, &time);
        print_section(name, section, time);
        fputs("> ", stdout);
    }

    return EXIT_SUCCESS;
}
