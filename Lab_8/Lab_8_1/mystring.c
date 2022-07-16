#include "mystring.h"

char* make_string() {
    char* string = (char*)calloc(N, sizeof(char));
    fgets(string, N, stdin);
    //free(string);
    return string;
}

void str_copy_symbol(char *destination, char symbol){
    static int result_index = 0;
    *(destination + result_index) = symbol;
    ++result_index;
}

char is_space(char symbol){
    return symbol == ' ';
}

char is_special(char symbol){
    switch (symbol)
    {
    case ',':
    case '.':
    case '!':
    case '?':
    case ':':
        return 1;
    default:
        return 0;
    }
}

int mystrlen(const char* str) {
    int len;
    for (len = 0; str[len]; len++);
    return len;
}


char* delete_spaces(char* string, char* result) {
    size_t length = mystrlen(string);
    char is_valid_text_started = 0;
    for (size_t i = 0; i < length; i++){
        char current_symbol = *(string + i);
        char following_symbol = *((string + i) + 1);
        char following_symbol_is_letter = !is_space(following_symbol) && !is_special(following_symbol);
        char is_valid_space = is_valid_text_started && (current_symbol == ' ') && following_symbol_is_letter;
        if ((current_symbol != ' ') || is_valid_space){
            is_valid_text_started = 1;
            str_copy_symbol(result, current_symbol);
        }
    }
    return result;
}
