/* lab_4, variant 4. It is requested to find the
geometric mean to the first 0 or minimum*/

#include <stdio.h>
#include <math.h>

int* find_min(int* arr, int n);
int* find_max(int* arr, int n);
int* search(int* arr, int n, int elem);
float get_sr_geom(int* arr, int n, int* min_arr, int* i);
void get_len(int* n);
void input_array(int* arr, int n);
float result(float sr_geom, int* i);

int main() {
    int n, i = 0;
    int arr[1000];

    get_len(&n);
    input_array(arr, n);
    int* min_arr = find_min(arr, n);
    float sr_geom = get_sr_geom(arr, n, min_arr, &i);

    printf("Geometric mean: %f\n", result(sr_geom, &i));
    return 0;
}

float result(float sr_geom, int* i) {
    if (sr_geom = 1) {
        printf("Error!\n");
    }else
    return exp(log(sr_geom)/(*i));
}


void get_len(int* n) {
    do {
        printf("Insert n: ");
        scanf("%d", n);
    } while (*n < 0);

}

void input_array(int* arr, int n) {
    printf("Input the elements: \n");
    for (int i = 0; i < n; ++i) {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }
}

float get_sr_geom(int* arr, int n, int* min_arr, int* i) {
    float sr_geom = 1;
    while ((*i < n) && (arr[*i] != 0) && (arr[*i] != *min_arr)) {
        sr_geom = sr_geom * arr[*i];
        (*i)++;
    }
    return sr_geom;
}


int* find_min(int *arr, int n) {
    int* min_arr = arr;
    for (int i = 1; i < n; i++) {
            if (*(arr + i) < *min_arr) {
                min_arr = arr + i;
            }
    }
    return min_arr;
}


int* find_max(int *arr, int n) {
    int* max_arr = arr;
    for (int i = 1; i < n; i++) {
            if (*(arr + i) > *max_arr) {
                max_arr = arr + i;
            }
    }
    return max_arr;
}


int* search(int *arr, int n, int elem) {
   int* search_el = arr;
   for (int i = 0; i < n; i++) {

        if (*(arr + i) == elem) {
            search_el = arr + i;
        }
   }
   if (*search_el != elem) {
        return 0;
   }
   return search_el;
}
