#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}



void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}



bool has_pair_sum(int S1[], int S2[], int n, int x, int *out_a, int *out_b) {

    merge_sort(S1, 0, n - 1);
    merge_sort(S2, 0, n - 1);


    int i = 0;         
    int j = n - 1;    

    while (i < n && j >= 0) {
        int sum = S1[i] + S2[j];

        if (sum == x) {
            if (out_a) *out_a = S1[i];
            if (out_b) *out_b = S2[j];
            return true;
        } else if (sum < x) {
            i++;     
        } else {
            j--;       
        }
    }

    return false;
}

int main(void) {
    int S1[] = {15, 3, 40, 8, 22};
    int S2[] = {5, 12, 1, 30, 7};
    int n = sizeof(S1) / sizeof(S1[0]);

    int targets[] = {45, 19, 100};
    int num_tests = sizeof(targets) / sizeof(targets[0]);

    for (int t = 0; t < num_tests; t++) {
        int x = targets[t];
        int a = 0, b = 0;

      
        int S1_copy[5], S2_copy[5];
        for (int k = 0; k < n; k++) {
            S1_copy[k] = S1[k];
            S2_copy[k] = S2[k];
        }

        if (has_pair_sum(S1_copy, S2_copy, n, x, &a, &b)) {
            printf("Target x = %3d -> Found: %d (from S1) + %d (from S2) = %d\n", x, a, b, x);
        } else {
            printf("Target x = %3d -> No valid pair exists.\n", x);
        }
    }

    return 0;
}