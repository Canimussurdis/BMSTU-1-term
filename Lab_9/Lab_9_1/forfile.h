#ifndef FORFILE_H
#define FORFILE_H
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Word{
    char *key;
    int count;
} Word;

typedef struct Result_dictionary{
    Word *words;
    int unical_words;
} Result_dictionary;

void quick_sort_words(Result_dictionary stats, int l, int r);
int binary_search_word(char* word, Result_dictionary stats);
Result_dictionary collection_of_statistics(char* text);
char* reading();
void free_Result(Result_dictionary stats);
int count_words(Result_dictionary stats);
void print_spaces(int i);
void print_line_for_words();
void print_part_of_table(int n);
void print_words(Result_dictionary stats);
int isBigVerb (char c);
int isVerbOrNum (char c);
int isSeparator (char c);
#endif // FORFILE_H
