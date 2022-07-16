#include "forfile.h"

int main(){
    int n;

    input_n(&n);
    char** str = memory_pointers(n);
    char* suf1 = memory_alloc(SIZE_STR);
    char* suf2 = memory_alloc(SIZE_STR);
    printf("Input strings:\n");
    input_strings(str, n);

    printf("Suf1:\n");
    input_str(suf1);
    printf("Suf2:\n");
    input_str(suf2);

    printf("Before:\n");
    output_matrix(str, n);
    cycle_replace(str, suf1, suf2, n);
    printf("After:\n");
    output_matrix(str, n);
    free_matrix(str);
    return 0;
}
