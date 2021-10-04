#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void input_array(float *a, int n);
void sort(float *arr, int n, int sign);
int count_sign(float* arr, int n, int sign);
void make_sign_array(float* arr, int n, int sign, float* result);

int main() {
    int n;
    printf("Insert the lenght of the array: ");
    scanf("%d", &n);

    float* arr = (float *) malloc(n * sizeof(float));
    input_array(arr, n);

    int first_size = count_sign(arr, n, 1);
    int second_size = count_sign(arr, n, -1);
    int third_size = count_sign(arr, n, 0);

    float* first_arr = (float *) malloc(first_size * sizeof(float));
    float* second_arr = (float *) malloc(second_size * sizeof(float));
    float* third_arr = (float *) malloc(third_size * sizeof(float));

    float* result_arr = (float *) malloc(n * sizeof(float));
    int last_index = 0;

    make_sign_array(arr, n, 1, first_arr);
    make_sign_array(arr, n, -1, second_arr);
    make_sign_array(arr, n, 0, third_arr);

    sort(first_arr, first_size, 1);
    sort(second_arr, second_size, -1);

    for (int i = 0; i < first_size; ++i) {
        result_arr[last_index] = first_arr[i];
        last_index++;
    }
    for (int i = 0; i < second_size; ++i) {
        result_arr[last_index] = second_arr[i];
        last_index++;
    }
    for (int i = 0; i < third_size; ++i) {
        result_arr[last_index] = third_arr[i];
        last_index++;
    }

    for (int i = 0; i < n; ++i) {
        printf("%f ", result_arr[i]);
    }
    printf("\n");

    free(arr);
    free(first_arr);
    free(second_arr);
    free(third_arr);

    return 0;
}

void input_array(float* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("arr[%d] = ", i);
        scanf("%f", &arr[i]);
    }
}

void sort(float *arr, int n, int sign) {
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (sign == -1) {
                if (arr[j - 1] < arr[j]) {
                    int tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                }
            } else if (sign == 1) {
                if (arr[j - 1] > arr[j]) {
                    int tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                }
            }
        }
    }
}

// make_sign_array создает массив result, состо€щий из элементов
// массива arr со знаком sign. ‘унки€ возвращает размер созданного массива
void make_sign_array(float* arr, int n, int sign, float* result) {
    int last_index = 0;
    for (int i = 0; i < n; ++i) {
        if (sign * arr[i] > 0 || sign == 0 && arr[i] == 0) {
            result[last_index] = arr[i];
            last_index++;
        }
    }
}

// count_sign считает количество элементов массива со знаком sign
// ≈сли sign < 0, то считает количество отрицательных чисел
// ≈сли sign == 0, то считает количество нулей
// ≈сли sign > 0, то считает количество положительных
int count_sign(float* arr, int n, int sign) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (sign * arr[i] > 0 || sign == 0 && arr[i] == 0) {
            result++;
        }
    }

    return result;
}
