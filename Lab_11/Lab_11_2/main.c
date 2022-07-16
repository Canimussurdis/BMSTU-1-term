#include "forfile.h"

int main(){
    int paragraph_of_menu = 0;
    int n = COUNT_MAX_LINES;
    Book* book = (Book*)calloc(SIZE, sizeof(Book));
    FILE* file;
    do {   
        paragraph_of_menu = output_menu(paragraph_of_menu);
        int flag = output_switch (paragraph_of_menu, file, n);
        if (flag == 0)
            return 0;
    } while (paragraph_of_menu != 5);
    return 0;
}
