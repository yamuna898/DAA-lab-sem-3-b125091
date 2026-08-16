#include <stdio.h>
#include <stdlib.h>



double** allocate_matrix(int n) {
    double** mat = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        mat[i] = (double*)calloc(n, sizeof(double));
    }
    return mat;
}

void free_matrix(double** mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}


void mat_add(double** A, double** B, double** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void mat_sub(double** A, double** B, double** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}



void structured_matrix_mult(double** A, double** B, double** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;


    double** A1 = allocate_matrix(k);
    double** A2 = allocate_matrix(k);
    double** B1 = allocate_matrix(k);
    double** B2 = allocate_matrix(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A1[i][j] = A[i][j];         
            A2[i][j] = A[i][j + k];    
            B1[i][j] = B[i][j];         
            B2[i][j] = B[i][j + k];     
        }
    }

    double** SA = allocate_matrix(k); 
    double** DA = allocate_matrix(k);
    double** SB = allocate_matrix(k); 
    double** DB = allocate_matrix(k); 

    mat_add(A1, A2, SA, k);
    mat_sub(A1, A2, DA, k);
    mat_add(B1, B2, SB, k);
    mat_sub(B1, B2, DB, k);

    double** P1 = allocate_matrix(k);
    double** P2 = allocate_matrix(k);


  
    structured_matrix_mult(SA, SB, P1, k);
    structured_matrix_mult(DA, DB, P2, k);

  
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            double c1 = (P1[i][j] + P2[i][j]) / 2.0;
            double c2 = (P1[i][j] - P2[i][j]) / 2.0;

            C[i][j]         = c1; 
            C[i + k][j + k] = c1; 
            C[i][j + k]     = c2; 
            C[i + k][j]     = c2; 
        }
    }

 
    free_matrix(A1, k); free_matrix(A2, k);
    free_matrix(B1, k); free_matrix(B2, k);
    free_matrix(SA, k); free_matrix(DA, k);
    free_matrix(SB, k); free_matrix(DB, k);
    free_matrix(P1, k); free_matrix(P2, k);
}

void print_matrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        printf("  [ ");
        for (int j = 0; j < n; j++) {
            printf("%6.1f ", mat[i][j]);
        }
        printf("]\n");
    }
}

int main(void) {
    int n = 4;
    double** A = allocate_matrix(n);
    double** B = allocate_matrix(n);
    double** C = allocate_matrix(n);

  
    double a_vals[4][4] = {
        {2, 1, 4, 3},
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {3, 4, 1, 2}
    };

    double b_vals[4][4] = {
        {1, 2, 3, 1},
        {2, 1, 1, 3},
        {3, 1, 1, 2},
        {1, 3, 2, 1}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = a_vals[i][j];
            B[i][j] = b_vals[i][j];
        }
    }

    printf("Matrix A (Structured 4x4):\n");
    print_matrix(A, n);

    printf("\nMatrix B (Structured 4x4):\n");
    print_matrix(B, n);

    structured_matrix_mult(A, B, C, n);

    printf("\nResult Matrix C = A x B in O(n^2):\n");
    print_matrix(C, n);

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);
    return 0;
}