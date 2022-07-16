#include <forfile.h>
//перевести проект на C++!
char** alloc_memory_for_char(){
    return (char**)calloc(MAX_NUMBER_OF_LINES, sizeof(char*));
}

char** alloc_memory(){
    char** massive_of_strings = alloc_memory_for_char();
    for (int i = 0; i < MAX_NUMBER_OF_LINES; i++){
       massive_of_strings[i] = (char*)calloc(MAX_NUMBER_OF_LINES, sizeof(char));
    }
    return massive_of_strings;
}

FILE* open_file_to_read(const char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL)
        print_err();
    return file;
}

int print_err(){
    printf("Error");
    return 0;
}

FILE* open_file_to_write(const char* filename){
    FILE* file = fopen(filename, "w");
    return file;
}

void printf_massive(char** massive_of_strings, int number_of_lines){
    for (int i = 0; i < number_of_lines; i++){
        if (NULL != massive_of_strings[i]){
            printf("%s", massive_of_strings[i]);
        }
    }
}

void copy_strings(char* string_dest, char* string_source){
    for (int i = 0; string_dest[i] == string_source[i]; i++);
}

char** record_text_from_file_to_massive(FILE* file, int* number_of_lines){
    char** text_file = alloc_memory_for_char();
    int curr_line = 0;
    while (!feof(file)) {
        char* temp = (char*)calloc(MAX_LENGHT_OF_LINE, sizeof(char));
        fgets(temp, MAX_LENGHT_OF_LINE, file);
        if ('\n' != temp[0] || '\0' != temp[0]){ //переменная стоит первой
            text_file[curr_line] = (char*)calloc(strlen(temp), sizeof(char)); //выделение памяти должно происходить в функции, strlen "засунуть" в define
            copy_strings(text_file[curr_line], temp);
            curr_line++;
        }
        free(temp);
    }
    *number_of_lines = curr_line;
    printf_massive(text_file, curr_line);
    return text_file;
}

void record_text_from_massive_to_file(FILE* file, int number_of_lines, char** massive_of_strings){
    for (int i = 0; i < number_of_lines; i++){
        fputs(massive_of_strings[i], file);
    }
}
