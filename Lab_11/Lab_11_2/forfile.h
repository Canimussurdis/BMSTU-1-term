#ifndef FORFILE_H
#define FORFILE_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 255
#define COUNT_STRUCTS 4
#define COUNT_MAX_LINES 20
//const char* filename = "my_book_file.txt";

typedef struct Book{
    char name[SIZE];
    char author[SIZE];
    int page_count;
    int rank;
} Book;

FILE* open_file_to_read(const char* filename);
FILE* open_file_to_write(const char* filename);
FILE* open_file_to_a(const char* filename);
int my_strcmp (const char* s, const char* cmp_s);
int output_menu (int paragraph_of_menu);
int add_book (FILE* file);
int output_books (FILE* file);
int count_books (FILE* file);
int read_file_and_assign (FILE* file, Book* books, int* line_count);
void swap(Book* book1, Book* book2);
int sort_struct_by_rank (Book* books, int n);
void rewrite_file(FILE* file, Book* books, int n);
void fprint_struct(FILE* file, Book book);
void fsanf_struct(FILE* file, Book* book);
int sort_books(FILE* file);
//int deleting(Book* books, int n, char* author);
void deleting(Book* books, int num, int count);
int delete_book(FILE* file);
Book* memory_for_books(int n);
void freedom(Book* books, int n);
int output_switch(int paragraph_of_menu, FILE* file, int n);
char* alloc_memory();
int print_err();
void input_string(char* s, const char* obj);
void get_book(Book* book);
void input_rank(int* rank);
void input_page_count(int* durP, const char* obj);
Book* get_books_from_file(FILE* file, int* count);
Book* realloc_memory(Book* books, int count);
#endif // FORFILE_H
