/*
 * APPROACH / STRATEGY (1D Array Operations):
 * 1. Maximum / First & Second Largest / Mean: Computed in a single linear pass O(n).
 * 2. Median / Mode: Sorting the array via insertion sort takes O(n^2) worst-case time,
 *    allowing easy extraction of the middle element (median) or most frequent element (mode).
 * 3. Standard Deviation: Computed using mean and a second pass to calculate squared differences.
 * 4. Remove Duplicates: Uses a nested loop approach (O(n^2)) to shift elements in-place.
 * 5. Reverse: Uses a two-pointer approach swapping outer elements moving inward in O(n) time.
 * 6. Partition about Pivot: Places elements smaller than the pivot after elements greater than
 *    or equal to the pivot using a two-pointer partition in O(n) time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void copy_array(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) b[i] = a[i];
}

void insertion_sort(int a[], int n) {
    for (int j = 1; j < n; j++) {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

int maximum(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > mx) mx = a[i];
    }
    return mx;
}

void first_second_largest(int a[], int n, int *first, int *second) {
    *first = -2147483648;
    *second = -2147483648;
    for (int i = 0; i < n; i++) {
        if (a[i] > *first) {
            *second = *first;
            *first = a[i];
        } else if (a[i] > *second && a[i] != *first) {
            *second = a[i];
        }
    }
}

double mean(int a[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    return (double)sum / n;
}

double median(int a[], int n) {
    int *b = (int *)malloc(n * sizeof(int));
    copy_array(a, b, n);
    insertion_sort(b, n);
    double ans;
    if (n % 2 != 0) ans = b[n / 2];
    else ans = (b[n / 2 - 1] + b[n / 2]) / 2.0;
    free(b);
    return ans;
}

double standard_deviation(int a[], int n) {
    double mu = mean(a, n);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double d = a[i] - mu;
        sum += d * d;
    }
    return sqrt(sum / n);
}

int mode(int a[], int n) {
    int *b = (int *)malloc(n * sizeof(int));
    copy_array(a, b, n);
    insertion_sort(b, n);
    int best = b[0], bestCount = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (b[i] == b[i - 1]) count++;
        else {
            if (count > bestCount) {
                bestCount = count;
                best = b[i - 1];
            }
            count = 1;
        }
    }
    if (count > bestCount) best = b[n - 1];
    free(b);
    return best;
}

void remove_duplicates(int a[], int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; ) {
            if (a[i] == a[j]) {
                for (int k = j; k < *n - 1; k++) {
                    a[k] = a[k + 1];
                }
                (*n)--;
            } else {
                j++;
            }
        }
    }
}

void reverse_array(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(&a[i], &a[n - 1 - i]);
    }
}

void partition_array(int a[], int n, int pivot) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && a[left] > pivot) left++;
        while (left < right && a[right] <= pivot) right--;
        if (left < right) {
            swap(&a[left], &a[right]);
            left++;
            right--;
        }
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, pivot;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int a[n];
    printf("Enter %d unsorted integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int first, second;
    printf("Maximum: %d\n", maximum(a, n));
    first_second_largest(a, n, &first, &second);
    printf("First largest: %d, Second largest: %d\n", first, second);
    printf("Mean: %.2f\n", mean(a, n));
    printf("Median: %.2f\n", median(a, n));
    printf("Standard deviation: %.4f\n", standard_deviation(a, n));
    printf("Mode: %d\n", mode(a, n));

    int b[n], m = n;
    copy_array(a, b, n);
    remove_duplicates(b, &m);
    printf("After removing duplicates: ");
    print_array(b, m);

    copy_array(a, b, n);
    reverse_array(b, n);
    printf("Reversed array: ");
    print_array(b, n);

    printf("Enter pivot: ");
    scanf("%d", &pivot);
    copy_array(a, b, n);
    partition_array(b, n, pivot);
    printf("Partitioned array: ");
    print_array(b, n);

    return 0;
}