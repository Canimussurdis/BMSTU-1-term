#include "forfile.h"

int main() {
    char* text;
    int n;
    text = alloc_text(MAX_LEN);
    input_text(text);
    input_n(&n);
    if (n > 0)
        print_new_text(text, n);
    free_text(text);
    return 0;
}
