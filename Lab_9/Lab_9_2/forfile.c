#include "forfile.h"

char* alloc_text() {
    return (char*)calloc(MAX_LEN, sizeof(char));
}

void free_text(char* text) {
    free(text);
}

void input_text(char* string) {
    printf("Input the text:\n");
    gets(string);
}

void input_n(int* n) {
    printf("\nInput n:\n");
    scanf("%d", n);
}

void print_new_text(char* text, int n) {
    char* line = text;
    char* word_start = line;
    char* word_end;

    printf("\nHere is your text:\n");
    while (*(word_end = jump_word(word_start)) != '\0') {
        while ((word_end - 1 - line < n) || (word_end - word_start > n ) && (word_start == line)) {
            printf("%.*s", word_end - word_start, word_start);
            if (word_end - line < n)
                putchar(' ');

            word_start = word_end + 1;
            word_end = jump_word(word_start);
        }
        for (int i = 0; i < n - (word_start - line); i++)
            putchar(' ');
        putchar('\n');

        line = word_start;
        word_start = line;
        word_end = word_start;
    }
    if (strlen(word_start))
        printf("%s\n", word_start);
}

char* jump_word(char* word_start) {
    char* p = strpbrk(word_start, " ");
    if (!p)
        p = word_start + strlen(word_start);

    return p;
}


