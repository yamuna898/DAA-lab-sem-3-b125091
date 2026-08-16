#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000



int binary_search(const int *arr, int n, int target, int *iterations) {
    int low = 0;
    int high = n - 1;
    *iterations = 0;

    while (low <= high) {
        (*iterations)++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int ternary_search(const int *arr, int n, int target, int *iterations) {
    int low = 0;
    int high = n - 1;
    *iterations = 0;

    while (low <= high) {
        (*iterations)++;
        int third = (high - low) / 3;
        int mid1 = low + third;
        int mid2 = high - third;

        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }
        if (target < arr[mid1]) {
            high = mid1 - 1;
        } else if (target > arr[mid2]) {
            low = mid2 + 1;
        } else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}




double time_binary_search(const int *arr, int n, int queries, long long *total_iterations) {
    int iters = 0;
    *total_iterations = 0;

    clock_t start = clock();
    for (int i = 0; i < queries; i++) {
        int target = (i % (n * 2));
        binary_search(arr, n, target, &iters);
        *total_iterations += iters;
    }
    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; 
}




double time_ternary_search(const int *arr, int n, int queries, long long *total_iterations) {
    int iters = 0;
    *total_iterations = 0;

    clock_t start = clock();
    for (int i = 0; i < queries; i++) {
        int target = (i % (n * 2));
        ternary_search(arr, n, target, &iters);
        *total_iterations += iters;
    }
    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; 
}




int main(void) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i * 2;
    }

    int target = 1532;
    int bs_iters = 0, ts_iters = 0;

    int bs_index = binary_search(arr, SIZE, target, &bs_iters);
    int ts_index = ternary_search(arr, SIZE, target, &ts_iters);

    printf("--------------------------------------------------\n");
    printf("    SINGLE SEARCH (Array Size: %d, Target: %d)\n", SIZE, target);
    printf("--------------------------------------------------\n");
    printf("Binary Search  -> Index: %3d | Iterations: %d\n", bs_index, bs_iters);
    printf("Ternary Search -> Index: %3d | Iterations: %d\n", ts_index, ts_iters);
    printf("--------------------------------------------------\n\n");
    return 0;
}