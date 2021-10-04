#include "forfile.h"

int main() {
    int count_of_students = 0;
    Student* students = input_student (&count_of_students);
    Student_sorted st_sorted = sort_students (students, count_of_students);
    print_sorted (st_sorted);
    printf ("\n%d\n", st_sorted.count_2);
    st_sorted = deletion (st_sorted);
    printf ("\n%d\n", st_sorted.count_2);
    printf ("\n\n\n\n\n\n");
    print_sorted (st_sorted);

    return 0;
}
