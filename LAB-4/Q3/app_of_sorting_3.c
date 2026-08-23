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
    int i = 0, j = 0, idx = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[idx++] = L[i++];
        else             arr[idx++] = R[j++];
    }
    while (i < n1) arr[idx++] = L[i++];
    while (j < n2) arr[idx++] = R[j++];
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
int binary_search(const int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
bool k_sum_helper(const int S[], int n, int k, int current_k, int start_idx, 
                  int current_sum, int target, int chosen_indices[]) {
    if (current_k == k - 1) {
        int remainder = target - current_sum;
        int found_idx = binary_search(S, start_idx, n - 1, remainder);
        if (found_idx != -1) {
            chosen_indices[current_k] = found_idx;
            return true;
        }
        return false;
    }
    for (int i = start_idx; i <= n - (k - current_k); i++) {
        chosen_indices[current_k] = i;
        if (k_sum_helper(S, n, k, current_k + 1, i + 1, current_sum + S[i], target, chosen_indices)) {
            return true;
        }
    }
    return false;
}
bool has_k_sum(int S[], int n, int k, int T, int result_elements[]) {
    if (k <= 0 || k > n) return false;
    merge_sort(S, 0, n - 1);
    if (k == 1) {
        int idx = binary_search(S, 0, n - 1, T);
        if (idx != -1) {
            if (result_elements) result_elements[0] = S[idx];
            return true;
        }
        return false;
    }
    int *chosen_indices = (int *)malloc(k * sizeof(int));
    bool found = k_sum_helper(S, n, k, 0, 0, 0, T, chosen_indices);

    if (found && result_elements) {
        for (int i = 0; i < k; i++) {
            result_elements[i] = S[chosen_indices[i]];
        }
    }
    free(chosen_indices);
    return found;
}
int main(void) {
    int S[] = {23, 5, 1, 14, 9, 8, 3, 11, 30};
    int n = sizeof(S) / sizeof(S[0]);
    int k = 4;
    int targets[] = {27, 45, 100};
    int num_tests = sizeof(targets) / sizeof(targets[0]);
    printf("Input Set S: ");
    for (int i = 0; i < n; i++) printf("%d ", S[i]);
    printf("\nk = %d\n\n", k);
    for (int t = 0; t < num_tests; t++) {
        int T = targets[t];
        int *result = (int *)malloc(k * sizeof(int));
        int S_copy[9];
        for (int i = 0; i < n; i++) S_copy[i] = S[i];
        if (has_k_sum(S_copy, n, k, T, result)) {
            printf("Target T = %3d -> Found: ", T);
            for (int i = 0; i < k; i++) {
                printf("%d%s", result[i], (i == k - 1) ? "" : " + ");
            }
            printf(" = %d\n", T);
        } else {
            printf("Target T = %3d -> No combination of %d elements adds to %d\n", T, k, T);
        }
        free(result);
    }
    return 0;
}