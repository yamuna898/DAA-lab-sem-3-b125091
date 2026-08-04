/*
Algorithmic Logic
Because the array is already sorted (all 0s naturally come before all 1s), we do not need to check every single element:

1. Binary Search O(log n):
   We jump to the middle of the array.
   If we see a 1, we check the element immediately to its left.
   If the left element is a 0, we have found the exact transition point!
2. If the middle is a 0, we know the transition must happen somewhere in the right half,
   so we discard the left half entirely.
3. If the middle is a 1 but the left element is also a `1*,
   we haven't found the start yet, so we discard the right half.
*/

#include <stdio.h>


int findPartitionBinary(int arr[], int n, int *steps) {
    int low = 0, high = n - 1;
    *steps = 0;

    while (low <= high) {
        (*steps)++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0))return mid;
        else if (arr[mid] == 0)low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {

    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int binary_steps = 0;

    int binary_index = findPartitionBinary(arr, n, &binary_steps);

    printf("--------------------- PARTITION POINT ANALYSIS -------------------------------\n\n");

    printf("Array: [ ");
    for(int i = 0; i < n; i++)printf("%d ", arr[i]);
    printf("]\n");
    printf("Index:   ");
    for(int i = 0; i < n; i++) {
        if(i < 10) printf("%d ", i);
        else printf("%d ", i);
    }
    printf("\n\n");

    printf(" Binary Search Results:\n");
    printf("Partition found at index: %d\n", binary_index);
    printf("Total steps required: %d\n\n", binary_steps);

    return 0;
}
