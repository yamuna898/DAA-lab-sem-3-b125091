/*
 * APPROACH / STRATEGY (Sorting via Reversals):
 * 1. Any permutation can be sorted using O(n) reversal operations by fixing elements position by
 *    position using suffix search and prefix reversals.
 * 2. When cost is length-dependent (|j - i| + 1), achieving O(n log^2 n) cost requires Divide-and-Conquer:
 *    a. Recursive Divide & Conquer Merge Sort splits array into halves.
 *    b. In-Place Merge utilizes 3-reversal rotation [X Y -> Y X] achieved by: reverse(X), reverse(Y), reverse(XY).
 *    c. Binary searches (lower/upper bound) find optimal cut positions to recursively swap sub-blocks using rotations.
 * 3. Total Cost Analysis: Merge cost M(s) = 2 M(s/2) + O(s) = O(s log s).
 *    Outer recursion S(n) = 2 S(n/2) + O(n log n) yields total cost of O(n log^2 n).
 */

#include <stdio.h>

long long reverse_range(int p[], int i, int j) {
    long long cost = 0;
    if (i >= j) return 0;
    cost = j - i + 1;
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
    return cost;
}

long long rotate_blocks(int p[], int first, int mid, int last) {
    long long cost = 0;
    cost += reverse_range(p, first, mid - 1);
    cost += reverse_range(p, mid, last - 1);
    cost += reverse_range(p, first, last - 1);
    return cost;
}

int lower_bound_pos(int p[], int first, int last, int x) {
    int lo = first, hi = last;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (p[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int upper_bound_pos(int p[], int first, int last, int x) {
    int lo = first, hi = last;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (p[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

long long merge_reversal(int p[], int first, int mid, int last) {
    if (first >= mid || mid >= last) return 0;
    if (last - first == 2) {
        if (p[mid] < p[first]) {
            return rotate_blocks(p, first, mid, last);
        }
        return 0;
    }

    int firstCut, secondCut;
    if (mid - first >= last - mid) {
        firstCut = first + (mid - first) / 2;
        secondCut = lower_bound_pos(p, mid, last, p[firstCut]);
    } else {
        secondCut = mid + (last - mid) / 2;
        firstCut = upper_bound_pos(p, first, mid, p[secondCut]);
    }

    long long cost = 0;
    cost += rotate_blocks(p, firstCut, mid, secondCut);

    int newMid = firstCut + (secondCut - mid);
    cost += merge_reversal(p, first, firstCut, newMid);
    cost += merge_reversal(p, newMid, secondCut, last);

    return cost;
}

long long merge_sort_reversal(int p[], int first, int last) {
    if (last - first <= 1) return 0;
    int mid = first + (last - first) / 2;
    long long cost = 0;
    cost += merge_sort_reversal(p, first, mid);
    cost += merge_sort_reversal(p, mid, last);
    cost += merge_reversal(p, first, mid, last);
    return cost;
}

void print_array(int p[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int p[n];
    printf("Enter permutation of 1..n:\n");
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("Original permutation: ");
    print_array(p, n);

    long long cost = merge_sort_reversal(p, 0, n);

    printf("Sorted permutation: ");
    print_array(p, n);
    printf("Total reversal cost: %lld\n", cost);

    return 0;
}