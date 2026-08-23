#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} Interval;

bool is_smaller(Interval a, Interval b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}


void merge_subarrays(Interval arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Interval *L = (Interval *)malloc(n1 * sizeof(Interval));
    Interval *R = (Interval *)malloc(n2 * sizeof(Interval));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (is_smaller(L[i], R[j])) {
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


void merge_sort_intervals(Interval arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_intervals(arr, left, mid);
        merge_sort_intervals(arr, mid + 1, right);
        merge_subarrays(arr, left, mid, right);
    }
}



Interval* merge_overlapping_intervals(Interval intervals[], int n, int *merged_count) {
    if (n <= 0) {
        *merged_count = 0;
        return NULL;
    }


    
    merge_sort_intervals(intervals, 0, n - 1);


    
    Interval *merged = (Interval *)malloc(n * sizeof(Interval));
    if (!merged) {
        fprintf(stderr, "Memory allocation failed.\n");
        *merged_count = 0;
        return NULL;
    }

    int count = 0;
    Interval current = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= current.end) {
  
            
            if (intervals[i].end > current.end) {
                current.end = intervals[i].end;
            }
        } else {

            merged[count++] = current;
            current = intervals[i];
        }
    }


    merged[count++] = current;

    *merged_count = count;
    return merged;
}

void print_intervals(const Interval arr[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)%s", arr[i].start, arr[i].end, (i == n - 1) ? "" : ", ");
    }
    printf("}\n");
}

int main(void) {
    Interval I[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {7, 18}
    };
    int n = sizeof(I) / sizeof(I[0]);

    printf("Input Intervals I:\n");
    print_intervals(I, n);

    int merged_count = 0;
    Interval *result = merge_overlapping_intervals(I, n, &merged_count);

    printf("\nMerged Intervals Output:\n");
    print_intervals(result, merged_count);

    free(result);
    return 0;
}