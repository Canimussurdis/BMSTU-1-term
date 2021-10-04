#include "forfile.h"

//чтение строки для имени студента + (дин. выделение памяти)
char* read_str(){
    rewind (stdin);
    char* str = calloc (MAX_LENGHT, sizeof(char));
    if (str == NULL)
        return 0;
    char tmp = getchar();
    int i = 0;
    while (tmp != '\n'){
        str[i] = tmp;
        tmp = getchar ();
        i++;
    }
    str[i] = '\0';
    return str;
}

void swap(Student* a, Student* b){
    Student tmp = *a;
    *a = *b;
    *b = tmp;
}

//вариант быстрой сортировки с семинара см
void quick_sort_students(Student* students, int l, int r){
    int i = l;
    int j = r;
    Student x = students[(l + r) / 2];
    do {
        while (strcmp((students + i)->name, x.name) < 0){
            i++;
        }
        while (strcmp((students + j)->name, x.name) > 0){
            j--;
        }
        if (i <= j) {
            if (strcmp((students + i)->name, (students + j)->name) > 0) {
               swap ((students + i), (students + j));
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < r)
        quick_sort_students (students, i, r);
    if (l < j)
        quick_sort_students (students, l, j);
}

void print_student(Student* students, int count_of_students){
    for (int i = 0; i < count_of_students; ++i){
        printf ("Info about student number %d :\n", i+1);
        printf ("Name : %s\n", (students + i)->name);
        printf ("Marks : ");
        for (int k = 0; k < 5; ++k){
            printf ("%d ", *((students + i)->marks + k));
        }
        printf ("\n");
    }
    printf ("\n");
}

//эксперименты с вводом студентов
Student* input_student(int* count_of_students){
    Student *students = calloc(MAX_COUNT_OF_ST, sizeof (Student));
    for( ; ; ){
        ++*count_of_students;
        printf ("Enter name of student number %d : ", *count_of_students);
        (students + *count_of_students - 1)->name = read_str ();
        (students + *count_of_students - 1)->marks = calloc (5, sizeof (int));
        printf ("Enter 5 grade student number %d : ", *count_of_students);
        for (int i = 0; i < 5; ++i){
            scanf("%d", ((students + *count_of_students - 1)->marks + i));
        }
        int answer;
        printf ("Do you want to enter one more student?(0 - NO, 1 - YES) : ");
        scanf ("%d", &answer);
        if (answer == 0)
            return students;
        if (answer == 1){
            students = realloc (students, (*count_of_students + 1) * sizeof(Student));
            continue;
        }
    }
}

int find_mark (int *marks, int mark){
    int result = 0;
    for (int i = 0; i < 5; ++i){
        if (marks[i] == mark)
            result++;
    }
    return result;
}

Student_sorted sort_students(Student* students, int count_of_students){
    Student_sorted st_sorted;
    st_sorted.stud_2 = calloc(MAX_COUNT_OF_ST, sizeof (Student));
    st_sorted.stud_3 = calloc(MAX_COUNT_OF_ST, sizeof (Student));
    st_sorted.stud_4 = calloc(MAX_COUNT_OF_ST, sizeof (Student));
    st_sorted.stud_5 = calloc(MAX_COUNT_OF_ST, sizeof (Student));
    st_sorted.count_2 = 0;
    st_sorted.count_3 = 0;
    st_sorted.count_4 = 0;
    st_sorted.count_5 = 0;
    for (int i = 0; i < count_of_students; ++i){
        if (find_mark ((students + i)->marks, 2) > 0){
            st_sorted.count_2++;
            st_sorted.stud_2 = realloc (st_sorted.stud_2, st_sorted.count_2 * sizeof(Student));
            *(st_sorted.stud_2 + st_sorted.count_2 - 1) = *(students + i);
            continue;
        }
        if (find_mark ((students + i)->marks, 3) > 0){
            st_sorted.count_3++;
            st_sorted.stud_3 = realloc (st_sorted.stud_3, st_sorted.count_3 * sizeof(Student));
            *(st_sorted.stud_3 + st_sorted.count_3 - 1) = *(students + i);
            continue;
        }
        if (find_mark ((students + i)->marks, 4) > 0){
            ++st_sorted.count_4;
            st_sorted.stud_4 = realloc (st_sorted.stud_4, st_sorted.count_4 * sizeof(Student));
            *(st_sorted.stud_4 + st_sorted.count_4 - 1) = *(students + i);
            continue;
        }
        if (find_mark ((students + i)->marks, 5) == 5){
            st_sorted.count_5++;
            st_sorted.stud_5 = realloc (st_sorted.stud_5, st_sorted.count_5 * sizeof(Student));
            *(st_sorted.stud_5 + st_sorted.count_5 - 1) = *(students + i);
            continue;
        }
    }
    return st_sorted;
}

void print_sorted(Student_sorted st_sorted){
    if (st_sorted.count_2 > 0){
        quick_sort_students (st_sorted.stud_2, 0, st_sorted.count_2 - 1);
        printf ("\nStudents with 2\n");
        print_student (st_sorted.stud_2, st_sorted.count_2);
    } else printf ("No students with 2\n");

    if (st_sorted.count_3 > 0){
        quick_sort_students (st_sorted.stud_3, 0, st_sorted.count_3 - 1);
        printf ("\nStudents with 3\n");
        print_student (st_sorted.stud_3, st_sorted.count_3);
    } else printf ("No students with 3\n");

    if (st_sorted.count_4 > 0){
        quick_sort_students (st_sorted.stud_4, 0, st_sorted.count_4 - 1);
        printf ("\nStudents with 4\n");
        print_student (st_sorted.stud_4, st_sorted.count_4);
    } else printf ("No students with 4\n");

    if (st_sorted.count_5 > 0){
        quick_sort_students (st_sorted.stud_5, 0, st_sorted.count_5 - 1);
        printf ("\nStudents with 5\n");
        print_student (st_sorted.stud_5, st_sorted.count_5);
    } else printf ("No students with 5\n");
}

int find_to_delete(int* marks){
    int k = 0;
    for (int i = 0; i < 5; i++){
        if (marks[i] == 2)
            k++;
    }
    return k;
}

Student_sorted deletion(Student_sorted st_sorted){
    for (int i = 0; i < st_sorted.count_2; i++){
        if (find_to_delete ((st_sorted.stud_2 + i)->marks) > 2){
            for (int k = i; k < st_sorted.count_2 - 1; k++){
                swap(st_sorted.stud_2 + k, st_sorted.stud_2 + k+1);
            }
            st_sorted.count_2--;
           st_sorted.stud_2 = realloc (st_sorted.stud_2, st_sorted.count_2 * sizeof (Student));
        }
    }
    return st_sorted;
}
