#include "forfile.h"


int main(){
    int paragraph_of_menu = 0;
    int n;
    Book book, book1, book2;
    FILE* file = fopen("my_book_file_binary.bin", "r+b");
    do {
        paragraph_of_menu = output_menu(paragraph_of_menu);
        int flag = output_switch(paragraph_of_menu, file, &book, &book1, &book2, n);
        if (flag == 0)
            return 0;
    } while (paragraph_of_menu != 5);

    fclose(file);
    return 0;
}
