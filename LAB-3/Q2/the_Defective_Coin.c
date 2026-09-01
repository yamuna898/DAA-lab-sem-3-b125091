#include <stdio.h>
#include <stdlib.h>


long long* build_prefix_sum(const int coins[], int n) {
    long long* pref = (long long*)malloc((n + 1) * sizeof(long long));
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + coins[i];
    }
    return pref;
}


long long get_range_weight(const long long pref[], int l, int r) {
    if (l > r) return 0;
    return pref[r + 1] - pref[l];
}




int binary_search_defective(const int coins[], const long long pref[], int low, int high) {
    while (low < high) {
        int m = high - low + 1;
        int k = m / 2; // Size of equal halves

        int left_start  = low;
        int left_end    = low + k - 1;
        int right_start = high - k + 1;
        int right_end   = high;

        long long left_weight  = get_range_weight(pref, left_start, left_end);
        long long right_weight = get_range_weight(pref, right_start, right_end);

        if (left_weight < right_weight) {
            low = left_start;
            high = left_end;
        } else if (right_weight < left_weight) {
            low = right_start;
            high = right_end;
        } else {
            if (m % 2 == 1) {
                int mid = low + k;
                int standard_coin_weight = coins[low]; 

                if (coins[mid] < standard_coin_weight) {
                    return mid;
                }
            }

            return -1;
        }
    }

  
    int reference_idx = (low == 0) ? 1 : 0;
    if (coins[low] < coins[reference_idx]) {
        return low;
    }

    return -1;
}

int main(void) {
    int n = 20;

    int coins[] = {10, 10, 10, 10};


    long long* pref = build_prefix_sum(coins, n);


    int defective_idx = binary_search_defective(coins, pref, 0, n - 1);

    printf("==========================================\n");
    if (defective_idx != -1) {
        printf("Defective lighter coin found at index: %d (weight = %d)\n", 
               defective_idx, coins[defective_idx]);
    } else {
        printf("All coins are identical. No defective coin found.\n");
    }
    printf("==========================================\n");

    free(pref);
    return 0;
} 