#include <stdio.h>
#include <stdlib.h>


int** allocate_matrix(int n) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));
    }
    return mat;
}



void free_matrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}



void add(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}



void subtract(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}



void strassen_recursive(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;


  
    int** A11 = allocate_matrix(k);
    int** A12 = allocate_matrix(k);
    int** A21 = allocate_matrix(k);
    int** A22 = allocate_matrix(k);

    int** B11 = allocate_matrix(k);
    int** B12 = allocate_matrix(k);
    int** B21 = allocate_matrix(k);
    int** B22 = allocate_matrix(k);


  
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }


    int** tempA = allocate_matrix(k);
    int** tempB = allocate_matrix(k);

    
  
    int** M1 = allocate_matrix(k);
    int** M2 = allocate_matrix(k);
    int** M3 = allocate_matrix(k);
    int** M4 = allocate_matrix(k);
    int** M5 = allocate_matrix(k);
    int** M6 = allocate_matrix(k);
    int** M7 = allocate_matrix(k);


  
    add(A11, A22, tempA, k);
    add(B11, B22, tempB, k);
    strassen_recursive(tempA, tempB, M1, k);

    
    add(A21, A22, tempA, k);
    strassen_recursive(tempA, B11, M2, k);



    subtract(B12, B22, tempB, k);
    strassen_recursive(A11, tempB, M3, k);

  
    subtract(B21, B11, tempB, k);
    strassen_recursive(A22, tempB, M4, k);


  
    add(A11, A12, tempA, k);
    strassen_recursive(tempA, B22, M5, k);

 
  
    subtract(A21, A11, tempA, k);
    add(B11, B12, tempB, k);
    strassen_recursive(tempA, tempB, M6, k);


  
    subtract(A12, A22, tempA, k);
    add(B21, B22, tempB, k);
    strassen_recursive(tempA, tempB, M7, k);


    int** C11 = allocate_matrix(k);
    int** C12 = allocate_matrix(k);
    int** C21 = allocate_matrix(k);
    int** C22 = allocate_matrix(k);


    add(M1, M4, tempA, k);
    subtract(tempA, M5, tempB, k);
    add(tempB, M7, C11, k);

    add(M3, M5, C12, k);


    add(M2, M4, C21, k);


    subtract(M1, M2, tempA, k);
    add(tempA, M3, tempB, k);
    add(tempB, M6, C22, k);


    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j]         = C11[i][j];
            C[i][j + k]     = C12[i][j];
            C[i + k][j]     = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }


    free_matrix(A11, k); free_matrix(A12, k); free_matrix(A21, k); free_matrix(A22, k);
    free_matrix(B11, k); free_matrix(B12, k); free_matrix(B21, k); free_matrix(B22, k);
    free_matrix(tempA, k); free_matrix(tempB, k);
    free_matrix(M1, k); free_matrix(M2, k); free_matrix(M3, k); free_matrix(M4, k);
    free_matrix(M5, k); free_matrix(M6, k); free_matrix(M7, k);
    free_matrix(C11, k); free_matrix(C12, k); free_matrix(C21, k); free_matrix(C22, k);
}


void strassen_multiply(int** A, int** B, int** C, int n) {
   
    int m = 1;
    while (m < n) {
        m *= 2;
    }

 
    int** paddedA = allocate_matrix(m);
    int** paddedB = allocate_matrix(m);
    int** paddedC = allocate_matrix(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            paddedA[i][j] = A[i][j];
            paddedB[i][j] = B[i][j];
        }
    }

    strassen_recursive(paddedA, paddedB, paddedC, m);

  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = paddedC[i][j];
        }
    }

    free_matrix(paddedA, m);
    free_matrix(paddedB, m);
    free_matrix(paddedC, m);
}

void print_matrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        printf("  [ ");
        for (int j = 0; j < n; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("]\n");
    }
}

int main() {
    int n = 4;

    int** A = allocate_matrix(n);
    int** B = allocate_matrix(n);
    int** C = allocate_matrix(n);


    int a_data[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };

    int b_data[4][4] = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = a_data[i][j];
            B[i][j] = b_data[i][j];
        }
    }

    printf("Matrix A (4x4):\n");
    print_matrix(A, n);

    printf("\nMatrix B (4x4):\n");
    print_matrix(B, n);

    strassen_multiply(A, B, C, n);

    printf("\nResult Matrix C = A x B (Strassen's Method):\n");
    print_matrix(C, n);

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}