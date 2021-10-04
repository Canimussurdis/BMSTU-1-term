/*variant 3. Calculate the sum in the upper and lower triangles formed by
diagonals, and put their difference in the Central element*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

void get_len_n(int* n);
int** new_int_matrix(int n);
void transform(int** matrix, int* arr, int n);
int** input_matrix(int** matrix, int n);
void printf_matrix(int** matrix, int n);
int found_esp(int** matrix, int n);
int upper_sum(int** matrix, int n);
int lower_sum(int** matrix, int n);
int** change_elem(int** matrix, int n);
void clean_matrix(int** matrix);

int main(){
    int n;
    get_len_n(&n);
    int** matrix = new_int_matrix(n);
    input_matrix(matrix, n);
    printf_matrix(matrix, n);

    change_elem(matrix, n);
    printf_matrix(matrix, n);
    getchar();
    clean_matrix(matrix);

    return 0;
}


void get_len_n(int* n) {
    do {
       printf("Insert n: ");
       scanf("%d", n);
    } while ((*n <= 0) || (*n % 2 == 0));
}


void transform(int** matrix, int* arr, int n) {
    for(int i = 0; i < n; i ++)
        matrix[i] = arr + i * n;
}

int** new_int_matrix(int n) {
    int* arr = (int*)calloc(n*n, sizeof(int));
    int** matrix= (int**)calloc(n, sizeof(int*));
    transform(matrix, arr, n);

    return matrix;

}

int** input_matrix(int** matrix, int n) {
    printf("Input the matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", *(matrix + i) + j);
		}
	}
	return matrix;
}

void printf_matrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}

int found_esp(int** matrix, int n) {
    int esp = upper_sum(matrix, n) - lower_sum(matrix, n);

    return esp;

}

int upper_sum(int** matrix, int n) {
    int first_sum = 0;
    for(int i = 0; i < n; i ++)
        for(int j = i + 1; j < n - 1 - i; j++)
          first_sum += matrix[i][j];

    return first_sum;
}


int lower_sum(int** matrix, int n) {
    int first_sum = 0;
    for(int i = 0; i < n; i ++)
        for(int j = n - i; j < i; j++)
          first_sum += matrix[i][j];

    return first_sum;
}

int** change_elem(int** matrix, int n) {

             matrix[n/2][n/2] = found_esp(matrix, n);

    return matrix;
}

void clean_matrix(int** matrix) {
    free(*matrix);
    free(matrix);
}

