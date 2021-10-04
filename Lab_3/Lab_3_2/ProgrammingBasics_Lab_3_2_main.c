/*first variant. Calculate the integral of the function ln(x)
with a given accuracy using the left rectangle method*/

#include <stdio.h>
#include <math.h>

void get_a_b(int* a, int* b);
void get_acc(float* accur);
float getN(int* a, int* b, float n);
float function(float x);
float integral(int* a, int* b, float n);
void swap(int* a, int* b);
void print_result(float f1);
float find_result(int* a, int* b, float accur);

int main() {
    float h, accur, f1, sum = 0;
    int a, b, n;
    get_a_b(&a, &b);
    get_acc(&accur);

    find_result(&a, &b, accur);

    print_result(f1);

    return 0;
}

void get_a_b(int* a, int* b) {
    do {
        printf("Insert a and b: ");
        scanf("%d%d", a, b);
    } while ((*a < 0)||(*b < 0));

    if (*b < *a){
        swap(a, b);
    }
}

void get_acc(float* accur) {
    do {
        printf("\nInsert the required accuracy: \n ");
        scanf("%f", accur);
    } while (*accur < 0);

}

void swap(int* a, int* b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

float function(float x){
    return log(x);
}

float integral(int* a, int* b, float n) {
    float h = getN(a, b, n);
    float sum = 0;

    for (int i = *a; i <= *b; i = i + h){
        sum = sum + function(i) * h;
        }

    return sum;
}

float getN(int* a, int* b, float n){
    return (b - a) / n;
}


void print_result(float f1) {
    printf("%f", f1);
}

float find_result(int* a, int* b, float accur) {
    int i = 2;
    float f1 = integral(a, b, i);
    float f2 = integral(a, b, i - 1);
    while (fabs(f1 - f2) >= accur) {
        i += 1;
        f2 = f1;
        f1 = integral(a, b, i);
    }

    return f1;
}
