#include "forfile.h"

int main()
{
    printf ("Enter your text(when you're done enter #) : \n");
    char* text = reading();
    Result_dictionary stats = collection_of_statistics(text);
    print_words(stats);
    free_Result(stats);
    return 0;
}
