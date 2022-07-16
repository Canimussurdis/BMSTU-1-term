#include "mystring.h"

int main() {
    //int N;
    //scanf_s("%d", &N);
    printf("Insert the string: \n");
    char string[N];
    fgets(string, N, stdin);
    /*remove_space(string);
    printf("New string: \n");
    puts(string);
    free(string);*/
    char result[N];
    memset(result, '\0', N);
    delete_spaces(string, result);
    printf("%s\n", result);

    getchar();

    return 0;
}
