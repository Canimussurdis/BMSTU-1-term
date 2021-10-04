/*Calculate the value of the sum of the series 1/n! for n - >infinity
with the required accuracy*/

#include <stdio.h>
#include <math.h>

void get_accur(double* accur);
double find_result(double* accur);
double get_elem(int n);
int factorial(int n);

int main() {

    double accur = 0;
    get_accur(&accur);
    printf("The sum: %lf\n", find_result(&accur));

    return 0;

}

void get_accur(double* accur) {

    do{
      printf("Insert the required accuracy: ");
      scanf("%lf", accur);
    } while (*accur < 0);
}

double find_result(double* accur) {

    double sum = 0;
    double elem1 = get_elem(1);
    double elem2 = 0;
    for (int i = 2; fabs(elem2 - elem1) > *accur; ) {
        elem2 = elem1;
         i+=1;
        sum += elem1;
        elem1= get_elem(i);
    }

    return sum;
}

double get_elem(int n){
    return (1.0 / factorial(n));
}

int factorial(int n){
    int x = 1;
    for (int i = n; i > 0; i--)
        x *= i;

    return x;
}
