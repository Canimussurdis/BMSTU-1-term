//variant 0. Sort matrix by using horizontal snake pattern
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_len_n_m(int* n, int* m);
int** new_int_matrix(int n, int m);
void printf_matrix(int** matrix, int n, int m);
void transform(int** matrix, int* mat, int n, int m);
int** input_matrix(int** matrix, int n, int m);
void clean_matrix(int** matrix);
void matrix_into_mat(int** matrix, int* mat, int n, int m);
int** matrix_by_snake(int** matrix, int* mat, int n, int m);
void swap(int* a, int* b);
void sort_matrix(int* a, int n, int m);
//void rowrevsort(int** matrix, int n, int i);
//void rowsort(int** matrix, int n, int i);
//void colsort(int** matrix, int n, int i);

int main(){
    int n, m;
    get_len_n_m(&n, &m);
    int** matrix = new_int_matrix(n, m);
    input_matrix(matrix, n, m);
    printf_matrix(matrix, n, m);

    int* mat = (int*)calloc(n*m, sizeof(int));
    matrix_into_mat(matrix, mat, n, m);
    sort_matrix(mat, n, m);
    int** new_matrix = matrix_by_snake(matrix, mat, n, m);
    printf("Result:\n");
    printf_matrix(new_matrix, n, m);
    clean_matrix(matrix);

    return 0;
}

void get_len_n_m(int* n, int* m) {
    do {
        printf("Insert n and m: ");
        scanf("%d%d", n, m);
    } while ((*n <= 0) && (*m <= 0));
}

void transform(int** matrix, int* mat, int n, int m) {
    for(int i = 0; i < n; i ++)
        matrix[i] = mat + i * m;
}

int** new_int_matrix(int n, int m) {
    int** matrix= (int**)calloc(n, sizeof(int*));
    int* mat = (int*)calloc(n*m, sizeof(int));
    transform(matrix, mat, n, m);
    return matrix;

}

int** input_matrix(int** matrix, int n, int m) {
    printf("Input the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }
    return matrix;
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

void clean_matrix(int** matrix) {
    free(*matrix);
    free(matrix);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int** matrix_by_snake(int** matrix, int* mat, int n, int m) {
    int j = 0;
    int temp = 0;
    int d = 0;
    while (j < n){
        switch (d){
            case 0:
                for (int i = 0; i < m; i++){
                    matrix[j][i] = mat[temp];
                    temp++;
                }
                j++;
                d = 1;
                break;
            case 1:
                for (int i = m - 1; i >= 0; i--){
                    matrix[j][i] = mat[temp];
                    temp++;
                    }
                j++;
                d = 0;
                break;
        }
    }
    return matrix;
}

void matrix_into_mat(int** matrix, int* mat, int n, int m){
    int temp = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mat[temp] = matrix[i][j];
            temp++;
        }
    }
}

void sort_matrix(int* a, int n, int m){
    int s = n * m;
    for (int i = 1; i < s; i++){
        for (int j = 1; j < s; j++){
            if (a[j - 1] > a[j])
                swap((a + j - 1), (a + j));
        }
    }
}


/*int** matrix_by_snake(int** matrix, int* mat, int n) {
    int i;
    for(int i = 0; i < mat; i++){
        for(int j = 0; j < n; j++){
            if(j%2==0){
                rowsort(matrix, n, i);
            } else {
                rowrevsort(matrix, n, i);
                }
            }
            for(int j = 0; j < n; j++){
                    colsort(matrix, n, i);
                    printf("\n");
                    }
    }

    for(int j=0;j<n;j++){
        if(j%2==0){
        rowsort(matrix, n, i);
        } else {
            rowrevsort(matrix, n, i);
        }
    }
    return matrix;
}

void rowsort(int** matrix, int n, int i){
    for(int j=0;j<n-1;j++){
        for(int k=0; k < n-j-1; k++){
            if(matrix[i][k] > matrix[i][k+1]){
                int temp=matrix[i][k];
                matrix[i][k]=matrix[i][k+1];
                matrix[i][k+1]=temp;
            }
        }
    }
}
void rowrevsort(int** matrix, int n, int i){
    for(int j=0;j<n-1;j++){
        for(int k=0; k<n-j-1; k++){
            if(matrix[i][k] < matrix[i][k+1]){
                int temp=matrix[i][k];
                matrix[i][k]=matrix[i][k+1];
                matrix[i][k+1]=temp;
            }
        }
    }
}
void colsort(int** matrix, int n, int i){
    for(int j=0; j<n-1; j++){
        for(int k=0; k<n-j-1; k++){
            if(matrix[k][i] > matrix[k+1][i]){
                int temp= matrix[k][i];
                matrix[k][i]=matrix[k+1][i];
                matrix[k+1][i]=temp;
            }
        }
    }
}*/
