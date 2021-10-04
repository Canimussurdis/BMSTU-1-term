#ifndef FORFILE_H
#define FORFILE_H
#pragma once

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_LENGHT 50
#define MAX_COUNT_OF_ST 30

typedef struct Student{
    char* name;
    int* marks;
} Student;

typedef struct Student_sorted{
    Student* stud_2;
    int count_2;
    Student* stud_3;
    int count_3;
    Student* stud_4;
    int count_4;
    Student* stud_5;
    int count_5;
} Student_sorted;

char* read_str();
void quick_sort_students(Student* students, int l, int r);
void print_student(Student* students, int count_of_students);
Student* input_student(int* count_of_students);
Student_sorted sort_students(Student* students, int count_of_students);
void print_sorted(Student_sorted st_sorted);
int find_to_delete(int* marks);
void swap(Student* a, Student* b);
Student_sorted deletion(Student_sorted st_sorted);

#endif // FORFILE_H
