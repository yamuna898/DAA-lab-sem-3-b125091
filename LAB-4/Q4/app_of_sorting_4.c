#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    double diff = *(const double *)a - *(const double *)b;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}


int count_less_than(const double arr[], int n, double target) {
    int low = 0, high = n - 1;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            ans = mid + 1; 
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}


void find_peak_with_binary_search(const double entries_in[], const double exits_in[], int n, 
                                  double *peak_time, int *max_people) {
    double *entries = (double *)malloc(n * sizeof(double));
    double *exits   = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        entries[i] = entries_in[i];
        exits[i]   = exits_in[i];
    }

    

    qsort(entries, n, sizeof(double), compare);
    qsort(exits, n, sizeof(double), compare);

    *max_people = 0;
    *peak_time = entries[0];


    
    for (int i = 0; i < n; i++) {
        double current_arrival = entries[i];
        
        int total_entered = i + 1; 
        int total_departed = count_less_than(exits, n, current_arrival);
        
        int current_present = total_entered - total_departed;

        if (current_present > *max_people) {
            *max_people = current_present;
            *peak_time = current_arrival;
        }
    }

    free(entries);
    free(exits);
}

int main(void) {
    double entries[] = {1.0, 2.0, 4.0, 6.0, 10.0};
    double exits[]   = {5.0, 8.0, 9.0, 11.0, 15.0};
    int n = sizeof(entries) / sizeof(entries[0]);

    double peak_time = 0.0;
    int max_people = 0;

    find_peak_with_binary_search(entries, exits, n, &peak_time, &max_people);

    printf("Peak Time (Binary Search Method): %.2f\n", peak_time);
    printf("Max People Present              : %d\n", max_people);

    return 0;
}