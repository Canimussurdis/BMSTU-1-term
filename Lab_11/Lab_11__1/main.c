#include <forfile.h>

int main(){
    const char* filename = "file.txt";
    FILE* file = open_file_to_read(filename);
    int number_of_lines = 0;
    char** text_of_file = record_text_from_file_to_massive(file, &number_of_lines);
    fclose(file);
    open_file_to_write(filename);
    record_text_from_massive_to_file(file, number_of_lines, text_of_file);
    fclose(file);
    free(text_of_file);
    return 0;
}
