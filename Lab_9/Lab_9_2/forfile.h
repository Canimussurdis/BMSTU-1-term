#ifndef FORFILE_H
#define FORFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_LEN 2048

char* alloc_text();
void free_text(char* text);
void input_text(char* string);
void input_n(int* n);
void print_new_text(char* text, int n);
char* jump_word(char* word_start);
#endif // FORFILE_H
