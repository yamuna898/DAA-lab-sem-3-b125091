/*
Algorithmic Logic
1. Brute Force O(n^2):
   The naive approach uses nested loops to compare every single element
   against every subsequent element in the array.
   It requires no extra memory (O(1) space), but takes an enormous amount of time for large arrays.
2. Optimized Hash/Frequency O(n):
   This approach leverages the "Space-Time Tradeoff".
   By allocating a small amount of extra memory (a seen boolean array),
   we can iterate through the main array just once. For each element,
   we check if its corresponding index in the seen array is already flagged.
   If it is, we found a duplicate instantly!
*/

#include <stdio.h>
#include <stdlib.h>

int checkUniqueOpt(int arr[], int n, int *comparisons) {
    *comparisons = 0;

    int seen[100] = {0};

    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (seen[arr[i]] == 1) {
            return 0;
        }
        seen[arr[i]] = 1;
    }
    return 1;
}

int main() {

    int arr[] = {12, 45, 7, 89, 23, 56, 34, 91, 18, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int brute_steps = 0, opt_steps = 0;

    printf("--- ELEMENT UNIQUENESS ANALYSIS ---\n\n");

    printf("Array: [ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");



    printf("Optimized Hash Search:\n");
    int isUnique2 = checkUniqueOpt(arr, n, &opt_steps);
    printf("Status: %s\n", isUnique2 ? "All elements are unique" : "Contains duplicates");
    printf("Array checks: %d\n\n", opt_steps);

    return 0;
}
