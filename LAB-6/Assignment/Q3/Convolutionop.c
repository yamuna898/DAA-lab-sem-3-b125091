/*
 * APPROACH / STRATEGY (Vector Convolution via Divide and Conquer FFT):
 * 1. Linear convolution in domain takes O(m*n). To achieve O(n log n), we utilize Fast Fourier Transform (FFT).
 * 2. FFT uses Divide-and-Conquer strategy: recursively split input sequence into even and odd indices,
 *    transform both halves recursively, and combine using complex twiddle factors (Euler's formula).
 * 3. Both input vectors are zero-padded to length N (smallest power of 2 >= m + n - 1).
 * 4. Convolution Theorem: Compute FFT(A) and FFT(B), perform element-wise complex multiplication,
 *    and apply Inverse FFT (IFFT) followed by normalisation to retrieve convolution result in O(n log n) time.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct {
    double re, im;
} Complex;

Complex add(Complex a, Complex b) {
    return (Complex){a.re + b.re, a.im + b.im};
}

Complex sub(Complex a, Complex b) {
    return (Complex){a.re - b.re, a.im - b.im};
}

Complex mul(Complex a, Complex b) {
    return (Complex){a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
}

void fft(Complex a[], int n, int invert) {
    if (n == 1) return;

    Complex even[n / 2], odd[n / 2];
    for (int i = 0; i < n / 2; i++) {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    fft(even, n / 2, invert);
    fft(odd, n / 2, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    Complex w = {1.0, 0.0};
    Complex wn = {cos(angle), sin(angle)};

    for (int k = 0; k < n / 2; k++) {
        Complex t = mul(w, odd[k]);
        a[k] = add(even[k], t);
        a[k + n / 2] = sub(even[k], t);
        w = mul(w, wn);
    }
}

void fft_normalize(Complex a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].re /= n;
        a[i].im /= n;
    }
}

int next_power_two(int x) {
    int n = 1;
    while (n < x) n <<= 1;
    return n;
}

int main() {
    int m, n;
    printf("Enter length of A (m): ");
    if (scanf("%d", &m) != 1) return 1;
    printf("Enter length of B (n): ");
    if (scanf("%d", &n) != 1) return 1;

    int N = next_power_two(m + n - 1);
    Complex A[N], B[N];

    for (int i = 0; i < N; i++) {
        A[i] = (Complex){0, 0};
        B[i] = (Complex){0, 0};
    }

    printf("Enter A:\n");
    for (int i = 0; i < m; i++) scanf("%lf", &A[i].re);

    printf("Enter B:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &B[i].re);

    fft(A, N, 0);
    fft(B, N, 0);

    for (int i = 0; i < N; i++) {
        A[i] = mul(A[i], B[i]);
    }

    fft(A, N, 1);
    fft_normalize(A, N);

    printf("Convolution C:\n");
    for (int k = 0; k < m + n - 1; k++) {
        printf("%.6f ", A[k].re);
    }
    printf("\n");

    return 0;
}