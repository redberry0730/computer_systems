/*
 *
 * Author: Yeon Jae Cho - chonw@bc.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 101
#define MIN_VALUE 50
#define BOUND (MAX_VALUE - MIN_VALUE)
#define NUM 4

typedef struct StudentGrades {
    int s_grade_1;
    int s_grade_2;
    int s_grade_3;
    int s_grade_4;
} StudentGrades;

typedef struct ClassGrades {
    int * c_grade_1;
    int * c_grade_2;
    int * c_grade_3;
    int * c_grade_4;
} ClassGrades;

typedef struct Average {
    double avg_1;
    double avg_2;
    double avg_3;
    double avg_4;
} Average;

void init_student_grades(StudentGrades * sg) {
    sg->s_grade_1 = rand() % MAX_VALUE;
    sg->s_grade_2 = rand() % MAX_VALUE;
    sg->s_grade_3 = rand() % MAX_VALUE;
    sg->s_grade_4 = rand() % MAX_VALUE;
}

void print_students(const int num, StudentGrades * students) {
    puts("Student Grades:");
    for (int i = 0; i < num; i++) {
        printf("Student %d:\t pa1: %d pa2: %d pa3: %d, pa4: %d\n",
        i+1, students[i].s_grade_1, students[i].s_grade_2, students[i].s_grade_3, students[i].s_grade_4);
    }
}

void record_student_grades(const int num, const StudentGrades * const students, ClassGrades * class) {
    for (int i = 0; i < num; i++) {
        class->c_grade_1[i] = students[i].s_grade_1;
        class->c_grade_2[i] = students[i].s_grade_2;
        class->c_grade_3[i] = students[i].s_grade_3;
        class->c_grade_4[i] = students[i].s_grade_4;
    }
}

void print_class(const int num, const ClassGrades * const class) {
    puts("Class Grades:");
    for (int i = 0; i < num; i++) {
        printf("Student %d:\t pa1: %d pa2: %d pa3: %d, pa4: %d\n",
        i+1, class->c_grade_1[i], class->c_grade_2[i], class->c_grade_3[i], class->c_grade_4[i]);
    }
}

double average_from_class(const int num, const ClassGrades * const class) {
    Average average;
    average.avg_1 = 0.0;
    average.avg_2 = 0.0;
    average.avg_3 = 0.0;
    average.avg_4 = 0.0;
    for (int i = 0; i < num; i++) {
        average.avg_1 = class->c_grade_1[i];
        average.avg_2 = class->c_grade_2[i];
        average.avg_3 = class->c_grade_3[i];
        average.avg_4 = class->c_grade_4[i];
    }
    average.avg_1 /= num;
    average.avg_2 /= num;
    average.avg_3 /= num;
    average.avg_4 /= num;
    double result = (average.avg_1 + average.avg_2 + average.avg_3 + average.avg_4) / NUM;
    return result;
}

double average_from_students(const int num, const StudentGrades * const students) {
    Average average;
    average.avg_1 = 0.0;
    average.avg_2 = 0.0;
    average.avg_3 = 0.0;
    average.avg_4 = 0.0;
    for (int i = 0; i < num; i++) {
        average.avg_1 = students[i].s_grade_1;
        average.avg_2 = students[i].s_grade_2;
        average.avg_3 = students[i].s_grade_3;
        average.avg_4 = students[i].s_grade_4;
    }
    average.avg_1 /= num;
    average.avg_2 /= num;
    average.avg_3 /= num;
    average.avg_4 /= num;
    double result = (average.avg_1 + average.avg_2 + average.avg_3 + average.avg_4) / NUM;
    return result;
}

void run_test(const int num) {
    StudentGrades * students = (StudentGrades *) calloc(num, sizeof(StudentGrades));
    for (int i = 0; i < num; i++) {
        init_student_grades(&students[i]);
    }
    print_students(num, students);
    ClassGrades class;
    class.c_grade_1 = (int *) calloc(num, sizeof(int));
    class.c_grade_2 = (int *) calloc(num, sizeof(int));
    class.c_grade_3 = (int *) calloc(num, sizeof(int));
    class.c_grade_4 = (int *) calloc(num, sizeof(int));
    record_student_grades(num, students, &class);
    print_class(num, &class);
    free(students);
    free(class.c_grade_1);
    free(class.c_grade_2);
    free(class.c_grade_3);
    free(class.c_grade_4);
    double student_grade, class_grade;
    student_grade = average_from_students(NUM, students);
    class_grade = average_from_class(NUM, class);
    printf("Average from students: %lf", student_grade);
    printf("Average from class: %lf", class_grade);
}

int main() {
    run_test(NUM);
    return EXIT_SUCCESS;
}

























//
