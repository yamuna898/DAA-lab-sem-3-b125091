/*
 * APPROACH / STRATEGY (2D Square Matrix Operations):
 * 1. Matrix Addition / Zero Test / Symmetry Test / In-place Transpose: Run in Theta(n^2) time
 *    by iterating over elements or off-diagonal entry pairs.
 * 2. Matrix Multiplication: Implements standard 3-loop multiplication in Theta(n^3) time.
 * 3. Determinant: Uses Gaussian Elimination with partial pivoting in O(n^3) time to reduce matrix
 *    to upper triangular form, then computes product of main diagonal elements.
 * 4. Eigenvalue / Eigenvector Computation: Uses Power Iteration algorithm to approximate the dominant
 *    eigenpair (dominant eigenvalue and associated eigenvector) across multiple iterations.
 */

#include <stdio.h>
#include <math.h>

#define MAX 50
#define EPS 1e-9

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], long long C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += (long long)A[i][k] * B[k][j];
            }
        }
    }
}

int is_zero(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != 0) return 0;
    return 1;
}

int is_symmetric(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i][j] != A[j][i]) return 0;
    return 1;
}

double determinant(int A[MAX][MAX], int n) {
    double M[MAX][MAX];
    double det = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = (double)A[i][j];

    for (int k = 0; k < n; k++) {
        int pivot = k;
        for (int i = k + 1; i < n; i++)
            if (fabs(M[i][k]) > fabs(M[pivot][k])) pivot = i;

        if (fabs(M[pivot][k]) < EPS) return 0.0;

        if (pivot != k) {
            for (int j = 0; j < n; j++) {
                double t = M[k][j];
                M[k][j] = M[pivot][j];
                M[pivot][j] = t;
            }
            det = -det;
        }
        det *= M[k][k];
        for (int i = k + 1; i < n; i++) {
            double factor = M[i][k] / M[k][k];
            for (int j = k + 1; j < n; j++) {
                M[i][j] -= factor * M[k][j];
            }
        }
    }
    return det;
}

void power_iteration(int A[MAX][MAX], int n, double *lambda, double v[MAX]) {
    for (int i = 0; i < n; i++) v[i] = 1.0;
    for (int iter = 0; iter < 1000; iter++) {
        double w[MAX], norm = 0.0;
        for (int i = 0; i < n; i++) {
            w[i] = 0.0;
            for (int j = 0; j < n; j++) w[i] += A[i][j] * v[j];
            norm += w[i] * w[i];
        }
        norm = sqrt(norm);
        if (norm < EPS) break;
        for (int i = 0; i < n; i++) v[i] = w[i] / norm;

        double Av[MAX];
        for (int i = 0; i < n; i++) {
            Av[i] = 0.0;
            for (int j = 0; j < n; j++) Av[i] += A[i][j] * v[j];
        }
        *lambda = 0.0;
        for (int i = 0; i < n; i++) *lambda += v[i] * Av[i];
    }
}

void transpose_in_place(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }
}

void print_matrix(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main() {
    int n, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    long long P[MAX][MAX];
    double v[MAX], lambda;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &B[i][j]);

    add(A, B, C, n);
    printf("\nA + B:\n"); print_matrix(C, n);

    multiply(A, B, P, n);
    printf("\nA * B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%lld ", P[i][j]);
        printf("\n");
    }

    printf("\nA is zero matrix: %s\n", is_zero(A, n) ? "Yes" : "No");
    printf("A is symmetric: %s\n", is_symmetric(A, n) ? "Yes" : "No");
    printf("det(A): %.3f\n", determinant(A, n));

    transpose_in_place(A, n);
    printf("\nTranspose of A (in place):\n");
    print_matrix(A, n);

    power_iteration(B, n, &lambda, v);
    printf("\nDominant eigenvalue estimate of B: %.6f\n", lambda);
    printf("Corresponding eigenvector:\n");
    for (int i = 0; i < n; i++) printf("%.4f ", v[i]);
    printf("\n");

    return 0;
}