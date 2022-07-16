#ifndef FORFILE_H
#define FORFILE_H
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHT_OF_LINE 1000
#define MAX_NUMBER_OF_LINES 20

char** alloc_memory();
FILE* open_file_to_read(const char* filename);
FILE* open_file_to_write(const char* filename);
int print_err();
char** alloc_memory_for_char();
void printf_massive(char** massive_of_strings, int number_of_lines);
void copy_strings(char* string_dest, char* string_source);
char** record_text_from_file_to_massive(FILE* file, int* number_of_lines);
void record_text_from_massive_to_file(FILE* file, int number_of_lines, char** massive_of_Strings);
char* allocate_memory(char* temp);
#endif // FORFILE_H
