#include <stdio.h>

void selection_sort(int A[], int n, long long *comparisons, long long *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = A[i];
            A[i] = A[min_idx];
            A[min_idx] = temp;
            (*swaps)++;
        }
    }
}

void print_array(const int A[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("]\n");
}

int main(void) {
    int n = 6;
    long long comparisons, swaps;
    long long expected_comps = (long long)n * (n - 1) / 2;

   
  
    int arr1[] = {64, 25, 12, 22, 11, 90};
    printf("=== Test Case 1: Unsorted Array ===\n");
    printf("Original Array : ");
    print_array(arr1, n);
    selection_sort(arr1, n, &comparisons, &swaps);
    printf("Sorted Array   : ");
    print_array(arr1, n);
    printf("Comparisons    : %lld (Expected: %lld)\n", comparisons, expected_comps);
    printf("Swaps          : %lld\n\n", swaps);

 
  
    int arr2[] = {11, 12, 22, 25, 64, 90};
    printf("=== Test Case 2: Already Sorted Array (Best Case) ===\n");
    printf("Original Array : ");
    print_array(arr2, n);
    selection_sort(arr2, n, &comparisons, &swaps);
    printf("Sorted Array   : ");
    print_array(arr2, n);
    printf("Comparisons    : %lld (Expected: %lld)\n", comparisons, expected_comps);
    printf("Swaps          : %lld\n\n", swaps);


  
    int arr3[] = {90, 64, 25, 22, 12, 11};
    printf("=== Test Case 3: Reverse Sorted Array (Worst Case) ===\n");
    printf("Original Array : ");
    print_array(arr3, n);
    selection_sort(arr3, n, &comparisons, &swaps);
    printf("Sorted Array   : ");
    print_array(arr3, n);
    printf("Comparisons    : %lld (Expected: %lld)\n", comparisons, expected_comps);
    printf("Swaps          : %lld\n", swaps);

    return 0;
}
