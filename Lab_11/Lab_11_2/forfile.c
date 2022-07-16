#include "forfile.h"
/* Вынести имя в константу */

FILE* open_file_to_read(const char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL)
        print_err();
    return file;
}

FILE* open_file_to_write(const char* filename){
    FILE* file = fopen(filename, "w");
    return file;
}

FILE* open_file_to_a(const char* filename){
    FILE* file = fopen(filename, "a");
    return file;
}

int print_err(){
    printf("Error");
    return 0;
}

char* alloc_memory(){
    return (char*)calloc(SIZE, sizeof(char));
}

Book* alloc_memory_for_books(){
    return (Book*)calloc(SIZE, sizeof(Book));
}

Book* realloc_memory(Book* books, int count){
    return (Book*)realloc(books, count * sizeof(Book));
}

int my_strcmp (const char* s, const char* cmp_s){
    int i = 0;
    while (*(s+i) == *(cmp_s+i) && *(s+i) && *(cmp_s+i))
        i++;
    return *(s+i) - *(cmp_s+i);
}

int output_menu(int paragraph_of_menu){
    printf("\nChoose the paragraph of menu\n");
    printf("1. Add a book to the end of file\n");
    printf("2. Output a books on the screen\n");
    printf("3. Sort books by rank\n");
    printf("4. Delete book by author\n");
    printf("5. Exit\n");
    scanf("%d", &paragraph_of_menu);
    return paragraph_of_menu;
}

int add_book(FILE* file){
    file = open_file_to_a("my_book_file.txt");
    Book book;
    get_book(&book);
    fprint_struct(file, book);
    printf("Book was succesfully added\n");
    fclose(file);
    /*printf("name: ");
    scanf("%s", book->name);
    printf("\nauthor: ");
    scanf("%s", book->author);
    printf("\npages: ");
    scanf("%d", &book->page_count);
    printf("\nrank: ");
    scanf("%d", &book->rank);
    fprint_struct(file, book);*/
    return 1;
}

void get_book(Book* book){
    getchar();
    input_string(book->name, "name of the book");
    input_string(book->author, "author's name");
    input_page_count(&book->page_count, "count of pages");
    input_rank(&book->rank);
}

void input_string(char* s, const char* obj){
    do {
        printf("Please input %s: ", obj);
        gets(s);
    } while (s[0] == 0);
}

void input_page_count(int* durP, const char* obj){
    do {
        printf("Please input %s: ", obj);
        scanf("%d", durP);
    } while (*durP < 1);
}

void input_rank(int* rank){
    do {
        printf("Please input rank (out of 10): ");
        scanf("%d", rank);
    } while (*rank > 10 || *rank < 1);
}

int output_books (FILE* file){
    /*printf("Books:\n\n");
    char* str = alloc_memory();
    if (str == NULL)
        print_err();
    file = open_file_to_read("my_book_file.txt");
    int n = 0;
    while (fgets(str, SIZE, file)){
        n++;
        printf("%s", str);
        if (n == COUNT_STRUCTS){
            printf("\n");
            n = 0;
        }
    }
    fclose(file);
    free(str);
    return 1;*/
    file = open_file_to_read("my_book_file.txt");
    int j =1;
    if (file != NULL) {
        while (!feof(file)) {
            Book book;
            fgets(book.name, SIZE, file);
            if(book.name[0] >= 32) {
                fgets(book.author, SIZE, file);
                fscanf(file, "%d%d", &book.page_count, &book.rank);
                printf("Book %d\nName: %sAuthor: %sCount of pages: %d\nRank: %d/5\n\n",
                       j, book.name, book.author, book.page_count, book.rank);
                j++;
            }
        }
        if ( j == 1)
            print_err();
    }
    fclose(file);
    return 1;
}

int count_books (FILE* file){
    char* str = alloc_memory();;
    if (str == NULL)
        print_err();
    file = open_file_to_read("my_book_file.txt");
    int n = 0;
    while (fgets(str, SIZE, file)){
        n++;
    }
    n = n/COUNT_STRUCTS;
    fclose(file);
    free(str);
    return n;
}

void fsanf_struct(FILE* file, Book* book) {
    fscanf(file, "%s%s%d%d", book->name, book->author, &book->page_count, &book->rank);
}

int read_file_and_assign (FILE* file, Book* books, int* line_count){
    file = open_file_to_read("my_book_file.txt");
    int t = 0;
    while ((!feof(file)) && (t < *line_count)){
       fsanf_struct(file, (books + t));
       t++;
    }
    fclose(file);
    return t;
}

void swap(Book* book1, Book* book2){
    Book temp = *book1;
    *book1 = *book2;
    *book2 = temp;
}

/*int sort_struct_by_rank (Book* books, int n){
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n-1; i++){
            if ((books + i)->rank > (books + i +1)->rank)
                swap(books, i);
        }
    }
    return 1;
}*/

void fprint_struct(FILE* file, Book book){
    fprintf(file, "%s\n%s\n%d\n%d", book.name, book.author, book.page_count, book.rank);
}


void rewrite_file(FILE* file, Book* books, int n){
    file = open_file_to_write("my_book_file.txt");
    for (int i = 0; i < n; i++){
        fprint_struct(file, *(books + i));
    }
    fclose(file);
}

/*int sort_books(FILE* file, Book* books){
    int n = count_books(file);
    if (n == 0)
        return 0;
    books = memory_for_books(n);
    int flag_read_and_assign = read_file_and_assign(file, books, &n);
    if (flag_read_and_assign == 0)
        return 0;
    int flag_sort = sort_struct_by_rank(books, n);
    if (flag_sort == 0)
        return 0;
    int flag_rewrite = rewrite_file(file, books, n);
    if (flag_rewrite == 0)
        return 0;
    freedom(books, n);
    return 1;
}*/

int sort_books(FILE* file){
    file = open_file_to_read("my_book_file.txt");
    if (file != 0){
        int count = 0;
        Book* books = get_books_from_file(file, &count);
        for (int i = 0; i < count - 1; i++)
            for (int j = i; j < count; j++)
                if (books[i].rank > books[j].rank)
                    swap(books + j, books + i);
        fclose(file);
        rewrite_file(file, books, count);
        free(books);
        printf("Books were sorted succesfully\n\n");
    }
    return 1;
}

Book* get_books_from_file(FILE* file, int* count){
    Book* books = alloc_memory_for_books();
    while (!feof(file)) {
        fgets(books[*count].name, SIZE, file);
        if (books[*count].name[0] >= 32){
            fgets(books[*count].author, SIZE, file);
            fscanf(file, "%d%d", &(books + *count)->page_count, &(books + *count)->rank);
            (*count)++;
        }
    }
    books = realloc_memory(books, *count);
    return books;
}

/*int deleting(Book* books, int n, char* author){
    for (int i = 0; i < n; i++){
        int flag = my_strcmp((books + i)->author, author);
        if (flag == 0){
            for (int j = i; j < n-1; j++)
                *(books + j) = *(books + j + 1);
            n--;
            i--;
        }
    }
    return n;
}*/

void deleting(Book* books, int num, int count){
    for (int i = num; i < count; i++)
        books[i] = books[i + 1];
}

/*int delete_book(FILE* file, Book* books){
    Book* book;
    char* author = alloc_memory();
    if (author == NULL){
        print_err();
    }
    printf("Type the name of author you want to delete: \n");
    scanf("%s", author);
    int n = count_books(file);
    if (n == 0)
        return 0;
    books = memory_for_books(n);
    int flag_read_and_assign = read_file_and_assign(file, books, &n);
    if (flag_read_and_assign == 0)
        return 0;
    n = deleting(books, n, author);
    free(author);
    book = (Book*)realloc(book, sizeof(Book)*(n));
    if (book == NULL)
        print_err();
    int flag_rewrite = rewrite_file(file, books, n);
    if (flag_rewrite == 0)
        return 0;
    freedom(books, n);
    return 1;
}*/

int delete_book(FILE* file){
    file = open_file_to_read("my_book_file.txt");
    if ( file != NULL){
        char author[SIZE];
        getchar();
        input_string(author, "author whose books you want to delete");
        strcat(author, "\n");
        int count = 0;
        Book* books = get_books_from_file(file, &count);
        for (int i = 0; i < count; i++){
            if (!strcmp(author, books[i].author))
                deleting(books, i--, --count);
            books = realloc_memory(books, count);
        }
        fclose(file);
        rewrite_file(file, books, count);
        free(books);
        printf("Books were deleted succesfully\n\n");
    }
    return 1;
}

/*Book* memory_for_books(int n){
   return (Book*)calloc(n, sizeof(Book));
}

void freedom(Book* books, int n){
    for (int i = 0; i < n; i++){
        free((books+i)->name);
        free((books+i)->author);
    }
    free(books);
}*/

int output_switch(int paragraph_of_menu, FILE* file, int n){
    /*books = (Book *)calloc(n, sizeof(Book));
    int book_count = read_file_and_assign (file, books, &n);
    realloc(books, sizeof(Book)*(book_count));*/
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
        n = sort_books(file);
        if (n == 0)
            return 0;
        break;
    case 4:
        n = delete_book(file);
        if (n == 0)
            return 0;
        break;
    }
    return 1;
}
