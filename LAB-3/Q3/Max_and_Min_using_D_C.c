#include <stdio.h>

typedef struct {
    int min;
    int max;
} MinMaxPair;

MinMaxPair get_min_max_dc(const int arr[], int low, int high, int *comparisons) {
    MinMaxPair result, left_result, right_result;


  
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }


  
    if (high == low + 1) {
        (*comparisons)++;
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }


    int mid = low + (high - low) / 2;


    left_result  = get_min_max_dc(arr, low, mid, comparisons);
    right_result = get_min_max_dc(arr, mid + 1, high, comparisons);


    (*comparisons)++;
    if (left_result.min < right_result.min) {
        result.min = left_result.min;
    } else {
        result.min = right_result.min;
    }


    (*comparisons)++;
    if (left_result.max > right_result.max) {
        result.max = left_result.max;
    } else {
        result.max = right_result.max;
    }

    return result;
}

void test_array(const int arr[], int n) {
    int comparisons = 0;
    MinMaxPair result = get_min_max_dc(arr, 0, n - 1, &comparisons);
    int theoretical_bound = (3 * n) / 2;

    printf("Array (n = %d): ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Minimum Element        : %d\n", result.min);
    printf("Maximum Element        : %d\n", result.max);
    printf("Actual Comparisons     : %d\n", comparisons);
    printf("Theoretical 3n/2 Limit : %d\n", theoretical_bound);
    printf("Bound Respected?       : %s\n", (comparisons <= theoretical_bound) ? "YES (PASSED)" : "NO (FAILED)");
    printf("--------------------------------------------------\n");
}

int main(void) {
    int arr1[] = {100, 11, 445, 1, 330, 3000, -5, 230};
    test_array(arr1, 8);


  
    int arr2[] = {22, 14, -8, 89, 53, 102, 3};
    test_array(arr2, 7);

    return 0;
}