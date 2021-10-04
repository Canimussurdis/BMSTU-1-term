/*Transpose the matrix relative to the side diagonal
and display it on the screen.*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

void get_len_n_m(int* n, int* m);
int** new_int_matrix(int n, int m);
void transform(int** matrix, int* arr, int n, int m);
void input_matrix(int** matrix, int n, int m);
void change_matrix(int** new_matrix, int** matrix, int n, int m);
void printf_matrix(int** matrix, int n, int m);
void clean_matrix(int** matrix);
void printf_matrix_new(int** new_matrix, int n, int m);
//void swap(float* a, float* b);


int main(){
    int n, m;
    get_len_n_m(&n, &m);

    int** matrix = new_int_matrix(n, m);
    input_matrix(matrix, n, m);
    printf_matrix(matrix, n, m);
    int** new_matrix = new_int_matrix(m, n);
    change_matrix(new_matrix, matrix, n, m);
    printf("Result:\n");
    printf_matrix_new(new_matrix, n, m);
    clean_matrix(matrix);
    clean_matrix(new_matrix);
    return 0;

}

void get_len_n_m(int* n, int* m) {
    do {
        printf("Insert n and m: ");
        scanf("%d%d", n, m);
    } while ((n < 0)||(m < 0));
}


void transform(int** matrix, int* arr, int n, int m) {
    for(int i = 0; i < n; i ++)
        matrix[i] = arr + i * m;
}

int** new_int_matrix(int n, int m) {
    int* arr = (int*)calloc(n*m, sizeof(int));
    int** matrix= (int**)calloc(n, sizeof(int*));
    transform(matrix, arr, n, m);

    return matrix;

}

void input_matrix(int** matrix, int n, int m) {
    printf("Input the matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", *(matrix + i) + j);
		}
	}
}

void change_matrix(int** new_matrix, int** matrix, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            new_matrix[m - i -1][n - j -1] = matrix[j][i];
        }
    }
}

void printf_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}

void printf_matrix_new(int** new_matrix, int n, int m) {
    for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", new_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void clean_matrix(int** matrix) {
    free(*matrix);
    free(matrix);
}

/*void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
*/
