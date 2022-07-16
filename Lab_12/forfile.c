#include "forfile.h"

FILE* open_file_to_write(const char* filename){
    FILE* file = fopen(filename, "wb");
    return file;
}

int print_err(){
    printf("Error");
    return 0;
}

char* alloc_memory(){
    return (char*)calloc(SIZE_C, sizeof(char));
}

int output_menu(int paragraph_of_menu){
    printf("\nChoose the paragraph of menu\n");
    printf("1. Add a book to the end of file\n");
    printf("2. Output books on the screen\n");
    printf("3. Sort books\n");
    printf("4. Delete book by author\n");
    printf("5. Exit\n");
    scanf("%d", &paragraph_of_menu);

    if (paragraph_of_menu > 5 || paragraph_of_menu < 1)
        print_err();
    return paragraph_of_menu;
}

/*Book memory_for_book(Book* book){
    book->name = alloc_memory();
    if (book->name == NULL)
        printf("Error");
    book->author = alloc_memory();
    if (book->author == NULL)
        printf("Error");
    return *book;
}*/

FILE* open_file_to_ab(const char* filename){
    FILE* file = fopen(filename, "ab");
    if (file == NULL)
        print_err();
    return file;
}

int add_book(FILE* file){
    Book book;
    file = open_file_to_ab("my_book_file_binary.bin");
    printf("name: ");
    scanf("%s", book.name);
    printf("author: ");
    scanf("%s", book.author);
    printf("pages: ");
    scanf("%d", &book.page_count);
    printf("rank: ");
    scanf("%d", &book.rank);

    write_in_file(&book, file);
    fclose(file);
    return 1;
}

FILE* open_file_to_read(const char* filename){
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
        print_err();
    return file;
}

FILE* open_file_to_rb(const char* filename){
    FILE* file = fopen(filename, "rb+");
    if (file == NULL)
        print_err();
    return file;
}

int output_books(FILE* file){
    printf("Books:\n\n");
    char* str = alloc_memory();
    if (str == NULL)
        print_err();
    file = open_file_to_read("my_book_file_binary.bin");
    int n = 0, number = 0;
    while (fread(str, sizeof(str), 1, file)){
        printf("%s\n", str);
        fread(str, sizeof(str), 1, file);
        printf("%s\n", str);
        fread(&number, sizeof(number), 1, file);
        printf("%d\n", number);
        fread(&number, sizeof(number), 1, file);
        printf("%d\n", number);
        n++;
        printf("\n");
    }
    fclose(file);
    free(str);
    return 1;
}

int count_books(FILE* file){
    file = open_file_to_read("my_book_file_binary.bin");
    int size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    fclose(file);
    return size/sizeof(Book);
    /*int n = 0, number = 0;
    while (fread(str, sizeof(str), 1, file)){
        fread(str, sizeof(str), 1, file);
        fread(&number, sizeof(number), 1, file);
        fread(&number, sizeof(number), 1, file);
        n++;
    }*/
}

int my_strcmp(const char* s, const char* cmp_s){
    int i = 0;
    while (*(s+i) == *(cmp_s+i) && *(s+i) && *(cmp_s+i))
        i++;
    return *(s+i) - *(cmp_s+i);
}

int my_strlen(const char* s){
    int k = -1;
    do
        k++;
    while (*(s+k) != '\0');
    return k;
}

int compare_rank(Book* book1,Book* book2){
    return (book1->rank - book2->rank);
}

int compare_name(Book* book1,Book* book2){
    return (my_strcmp(book1->name, book2->name));
}
void swap(Book* book1,Book* book2){
    Book tmp = *book1;
    *book1 = *book2;
    *book2 = tmp;
}

Book read_file(Book* book, FILE* file){
    fread(book->name, sizeof(book->name), 1, file);
    fread(book->author, sizeof(book->author), 1, file);
    fread(&book->page_count, sizeof(book->page_count), 1, file);
    fread(&book->rank, sizeof(book->rank), 1, file);
    return *book;
}

void write_in_file (Book* book, FILE* file){
    fwrite(book->name, sizeof(book->name), 1, file);
    fwrite(book->author, sizeof(book->author), 1, file);
    fwrite(&book->page_count, sizeof(book->page_count), 1, file);
    fwrite(&book->rank, sizeof(book->rank), 1, file);
}

Book read_book_by_index(FILE* file, int index) {
    Book temp_book;
    fseek(file, sizeof(Book) * index, SEEK_SET);
    fread(&temp_book, sizeof(Book), 1, file);
    rewind(file);
    return temp_book;
}

void write_book_by_index(FILE* file, Book* book, int index) {
    fseek(file, sizeof(Book) * index, SEEK_SET);
    fwrite(book, sizeof(Book), 1, file);
    fflush(file);
    rewind(file);
}

int sort_books (FILE* file, Book* book1,Book* book2){
    printf("1. Sort by rank\n2. Sort by name\n");
    int a = 0;
    scanf("%d", &a);
    if (a > 2 || a < 1)
        print_err();
    file = open_file_to_rb("my_book_file_binary.bin");
    int n = count_books(file);
    if (n == 0)
        return 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++) {
            Book book1 = read_book_by_index(file, j);
            Book book2 = read_book_by_index(file, j + 1);
            int flag_sort;

            if ( a == 1)
                flag_sort = compare_rank(&book1, &book2);
            else if (a == 2)
                flag_sort = compare_name(&book1, &book2);

            if (flag_sort > 0) {
                write_book_by_index(file, &book1, j + 1);
                write_book_by_index(file, &book2, j);
            }
        }
        /*long int k1 = 0, k2 = 0, k = 0, l = 0;
        fseek(file, k, SEEK_SET);
        for (int i = 0; i < n-1; i++){
            Book book1, book2;
            book1 = read_file(&book1, file);
            k1 = ftell(file);
            book2 = read_file(&book2, file);
            k2 = ftell(file);
            if (a == 1){
                int flag_sort = compare_rank(&book1, &book2);
                if (flag_sort > 0){
                    swap(&book1, &book2);
                    k = k2 - k1;
                } else
                    k = k1;
            }
            if (a == 2){
                int flag_sort = compare_name(&book1, &book2);
                if (flag_sort > 0){
                    swap(&book1, &book2);
                    k = k2 - k1;
                } else
                    k = k1;
            }
            fseek(file, l, SEEK_SET);
            l = k;
            write_in_file(&book1, file);
            write_in_file(&book2, file);
            fseek(file, k, SEEK_SET);
        }*/
    }
    fclose(file);
    return 1;
}

int delete_book (FILE* file,Book* book1,Book* book2){
    char *author = alloc_memory();
    if (author == NULL)
        print_err();
    printf("Type name of author what you want to delete\n");
    scanf("%s", author);
    FILE *f;
    file = open_file_to_read("my_book_file_binary.bin");
    if (file == NULL)
        print_err();
    f = open_file_to_write("f.bin");
    int n = count_books(file);
    if (n == 0)
        return 0;
    int k = n;
    for (int i = 0; i < n; i++){
        Book book;
        book = read_file(&book, file);
        int flag = my_strcmp(book.author, author);
        if(flag != 0)
            write_in_file(&book, f);
        else
            k--;
        free(book.name);
        free(book.author);
    }
    fclose(f);
    fclose(file);
    free(author);
    f = open_file_to_read("f.bin");
    file = open_file_to_write("my_book_file_binary.bin");
    for (int i = 0; i < k; i++){
        Book book;
        book = read_file(&book, f);
        write_in_file(&book, file);
        free(book.name);
        free(book.author);
    }
    fclose(file);
    fclose(f);
    return 1;
}


int output_switch (int paragraph_of_menu, FILE* file, Book* book, Book* book1,Book* book2, int n){
    switch (paragraph_of_menu){
    case 1:
        n = add_book(file);
        if (n == 0)
            return 0;
        break;
    case 2:
        n = output_books(file);
        if (n == 0)
            return 0;
        break;
    case 3:
        n = sort_books(file, book1, book2);
        if (n == 0)
            return 0;
        break;
    case 4:
        n = delete_book(file, book1, book2);
        if (n == 0)
            return 0;
        break;
    }
    return 1;
}
