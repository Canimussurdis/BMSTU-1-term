#ifndef MYSTRING_H
#define MYSTRING_H
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define N 100

char* make_string();
void check_begin_and_end(char* string);
void deletion (char* string, int fst, int len);
int mystrlen(const char* str);
void remove_space(char* string);
void str_copy_symbol(char *destination, char symbol);
char is_space(char symbol);
char is_special(char symbol);
char* delete_spaces(char* string, char* result);
#endif // MYSTRING_H
