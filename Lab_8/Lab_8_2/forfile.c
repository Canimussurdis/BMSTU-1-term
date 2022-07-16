#include "forfile.h"

void input_n(int *n) {
    do {
        printf("Input n: ");
        scanf("%d", n);
    } while (*n <= 0);
    getchar();
}

char* memory_alloc(int size) {
    return (char*)calloc(size, sizeof(char));
}

char** memory_pointers(int n) {
    char** str_matrix = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++) {
        str_matrix[i] = (char*)calloc(SIZE_STR, sizeof(char));
    }
    return str_matrix;
}

void input_strings(char** str_matrix, int n) {
    for (int i = 0; i < n; i++) {
        gets(str_matrix[i]);
    }
}

void output_matrix(char** str_matrix, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i, *(str_matrix+i));
    }
}

void input_str(char* str) {
    scanf("%s", str);
}

size_t strlen(const char *str) {
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

void free_matrix(char **str) {
    free(*str);
    free(str);
}

char* find(char* s, char c) {
    char* result = s;

    while (*result) {
        if (*result == c) {
            return result;
        }
        ++result;
    }
    return NULL;
}

char* replace_copy(char *source_begin, char *source_end, char *dest, char *pattern, char *replacement){
    while (source_begin != source_end) {
        char *pattern_begin = my_strstr(source_begin, pattern, source_end - source_begin);
        char *copy_range_end = source_end;
        if (pattern_begin) {
            copy_range_end = pattern_begin;
        }
        dest = my_strcpy_range(source_begin, copy_range_end, dest);
        source_begin = copy_range_end;
        if (source_begin != source_end) {
            dest = my_strcpy(dest, replacement, 1);
            source_begin += strlen(pattern);
        }
    }
    return dest;
}

void replace(char* s, char* s_old, char* s_new) {
    char *tmp_buf = memory_alloc(SIZE_STR);
    char *first_familyname_end = find(s, ' ');
    char* dest_position = replace_copy(s, first_familyname_end, tmp_buf, s_old, s_new);
    my_strcpy(dest_position, first_familyname_end, 0);
    my_strcpy(s, tmp_buf, 0);
    free(tmp_buf);
}

char* my_strcpy_range(char* begin, char* end, char* destination) {
    while (begin != end) {
        *(destination++) = *(begin++);
    }
    return destination;
}

/*Добавление подстроки в начало строки*/
char* my_strins(char* str, char* sub_s) {
    char* s_temp = memory_alloc(strlen(str));
    my_strcpy(s_temp, str, 1);
    my_strcpy(str, sub_s, 1);
    my_strcat(str, s_temp);
    free(s_temp);
    return str;
}

/*Удаление заданного кол-ва символов из начала строки*/
char* my_strdel(char* str, unsigned count) {
    if (strlen(str) <= count) {
        str[0] = '\0';
    } else {
        my_strcpy(str, str + count, 0);
    }
    return str;
}

char* my_strcpy(char* dest, const char* src, unsigned char skip_zero) {
    while (*src) {
        *(dest++) = *(src++);
    }
    if (!skip_zero) {
        *(dest++) = *src;
    }
    return dest;
}

char* my_strcat(char* dest, const char *src) {
    char *p;
    for (p = dest; *p; p++);
    for (int i = 0; (p[i] = src[i]); i++);
    return dest;
}

/*Поиск подстроки в строке*/
char* my_strstr(char *str, const char* sub_s, int lim) {
    char *q;
    char *p = str;
    const char *qs = sub_s;
    int check = 1;
    int i = 0;

    while (*p && *qs && check && i < lim) {
        for (q = p, qs = sub_s; *p && *q == *qs; q++, qs++);
        if (!(*qs && *q)) {
            check = 0;
        } else {
            p++;
        }
        i++;
    }
    return (*p && i < lim) ? p : NULL;
}

void cycle_replace(char **str, char *suf1, char *suf2, int n){
    for (int i = 0; i < n; i++) {
        replace(str[i], suf1, suf2);
    }
}
