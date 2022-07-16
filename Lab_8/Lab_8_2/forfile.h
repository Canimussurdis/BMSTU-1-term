#ifndef FORFILE_H
#define FORFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE_STR 400

void input_n(int *n);
char* memory_alloc(int size);
char** memory_pointers(int n);
void input_strings(char** str_matrix, int n);
void output_matrix(char** str_matrix, int n);
void input_str(char* str);
size_t strlen(const char *str);
void free_matrix(char **str);
char* find(char* s, char c);
char* replace_copy(char *source_begin, char *source_end, char *dest, char *pattern, char *replacement);
void replace(char* s, char* s_old, char* s_new);
char* my_strcpy_range(char* begin, char* end, char* destination);
char* my_strins(char* str, char* sub_s);
char* my_strdel(char* str, unsigned count);
char* my_strcpy(char* dest, const char* src, unsigned char skip_zero);
char* my_strcat(char* dest, const char *src);
char* my_strstr(char *str, const char* sub_s, int lim);
void cycle_replace(char **str, char *suf1, char *suf2, int n);
#endif // FORFILE_H
