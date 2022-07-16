#include "forfile.h"

/* Возвращает true, если текущий символ - большая буква */
int isBigVerb (char c){
    return (c > 64 && c < 91) ? 1 : 0;
}

/* Возвращает true, если текущий символ - маленькая буква или цифра */
int isVerbOrNum (char c){
    return ((c > 47 && c < 58) || (c > 96 && c < 123)) ? 1 : 0;;
}

int isSeparator (char c){
    return (c == '.' || c == '?' || c == '!') ? 1 : 0;;
}

void quick_sort_words(Result_dictionary stats, int l, int r){
    int i = l;
    int j = r;
    Word x = stats.words[(l + r) / 2];
    do {
        while (strcmp((stats.words + i)->key, x.key) < 0){
            i++;
        }
        while (strcmp((stats.words + j)->key, x.key) > 0){
            j--;
        }
        if (i <= j) {
            if (strcmp((stats.words + i)->key, (stats.words + j)->key) > 0) {
                Word tmp = *(stats.words + i);           // swap
                *(stats.words + i) = *(stats.words + j);
                *(stats.words + j) = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < r)
        quick_sort_words(stats, i, r);
    if (l < j)
        quick_sort_words(stats, l, j);
}

int binary_search_word(char* word, Result_dictionary stats){
    int low, middle, high;
    low = 0;
    if (stats.unical_words == 0)
        return -1;
    high = stats.unical_words - 1;
    quick_sort_words(stats, 0, stats.unical_words - 1);
    while (low <= high){
        middle = (low + high) / 2;
        if (strcmp(word, (stats.words + middle)->key) < 0)
            high = middle - 1;
        else if (strcmp(word, (stats.words + middle)->key) > 0)
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

Result_dictionary collection_of_statistics(char* text){
    char* tmp_word = calloc (50, sizeof (char));
    int curr_symbol = 0;
    Result_dictionary stats;
    stats.unical_words = 0;
    stats.words = malloc(sizeof (Word));
    for (size_t i = 0; i < strlen (text); ++i){
        if (isBigVerb (*(text + i)))
            *(text + i) = tolower (*(text + i)); // преобразование прописных букв в строчные
        if (isVerbOrNum (*(text + i))){
            *(tmp_word + curr_symbol) = *(text + i);
            curr_symbol++;
            continue;
        }
        if (!isVerbOrNum (*(text + i)) && strlen (tmp_word) >= 1){

            *(tmp_word + curr_symbol) = '\0';
            curr_symbol = 0;
            int k = binary_search_word (tmp_word, stats);
            if (k != -1){
                (stats.words + k)->count++;
            }

            if (k == -1){
                stats.unical_words++;
                stats.words = realloc (stats.words, sizeof (Word) * stats.unical_words);
                (stats.words + stats.unical_words - 1)->key = malloc (strlen (tmp_word) + 1);
                strcpy ((stats.words + stats.unical_words - 1)->key, tmp_word);
                (stats.words + stats.unical_words - 1)->count = 1;
            }
            tmp_word = calloc (50, sizeof (char));
        }
    }
    free(tmp_word);
    return stats;
}

char* reading(){
    rewind (stdin);
    char *str = malloc (sizeof (char));
    if (str == NULL) return NULL;
    char tmp;
    int i = 0;
    while ((tmp = getchar ())!= '#'){
        str = realloc (str, strlen (str) + 1);
        *(str + i) = tmp;
        i++;
    }
    *(str + i) = '\0';
    return str;
}

void free_Result(Result_dictionary stats){
    for (int i = 0; i < stats.unical_words - 1; ++i){
        free ((stats.words + i)->key);
    }
}

int count_words(Result_dictionary stats){
    int count = 0;
    for (int i = 0; i < stats.unical_words - 1; ++i){
        count += (stats.words + i)->count;
    }
    return count;
}

void print_spaces(int i){
    for (int k = i; k < 20; ++k){
        printf (" ");
    }
}

void print_line_for_words(){
    printf ("+");
    for (int i = 0; i < 31; ++i){
        printf ("-");
    }
    printf ("+");
    for (int i = 0; i < 31; ++i){
        printf ("-");
    }
    printf ("+");
    for (int i = 0; i < 23; ++i){
        printf ("-");
    }
    printf ("+\n");
}

void print_part_of_table(int n){
    for (int i = 0; i < n; ++i){
        printf ("=");
    }
    printf ("\n");
}

void print_words(Result_dictionary stats){
    print_part_of_table (89);
    printf ("|\t\tWord\t\t|\tCount of meeting\t|\tFrequency\t|\n");
    print_line_for_words ();
    int count_of_all_words = count_words (stats);
    for (int k = 0; k < stats.unical_words - 1; ++k){
        printf ("|");
        print_spaces (strlen ((stats.words + k)->key));
        printf ("%s", (stats.words + k)->key);
        print_spaces (9);
        printf ("|\t%10d\t\t|\t%7.3f%%\t|\n", (stats.words + k)->count,
                (float)((stats.words + k)->count*100)/count_of_all_words);
        print_line_for_words ();
    }
}
