#ifndef FORFILE_H
#define FORFILE_H

#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma once

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE_C 255

typedef struct Book {
    char name[SIZE_C];
    char author[SIZE_C];
    int page_count;
    int rank;
} Book;
FILE* open_file_to_read(const char* filename);
FILE* open_file_to_rb(const char* filename);
FILE* open_file_to_ab(const char* filename);
FILE* open_file_to_write(const char* filename);
int output_menu(int paragraph_of_menu);
char* alloc_memory();
int output_switch (int paragraph_of_menu, FILE* file, Book* book, Book* book1, Book* book2, int n);
Book memory_for_book (Book* book);
int add_book(FILE* file);
int output_books (FILE* file);
int count_books (FILE* file);
int my_strcmp (const char* s, const char* cmp_s);
int my_strlen (const char* s);
int compare_rank (Book* book1, Book* book2);
int compare_name (Book* book1, Book* book2);
void swap (Book* book1,Book* book2);
Book read_file (Book* book, FILE* file);
void write_in_file (Book* book, FILE* file);
int sort_books (FILE* file, Book* book1, Book* book2);
int delete_book (FILE* file, Book* book1, Book* book2);
int print_err();
Book read_book_by_index(FILE* file, int index);
void write_book_by_index(FILE* file, Book* book, int index);
#endif // FORFILE_H
