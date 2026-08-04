/*
**Algorithmic Logic**
The puzzle is solved using a classic divide-and-conquer recursive approach:

1. Base Case: If n = 1, simply move the disk from Source to Destination.
2. Recursive Steps:
   -  Move the top n - 1 disks from the Source peg to the Auxiliary peg.
   -  Move the nth (largest) disk from the Source peg directly to the Destination peg.
   -  Move the n - 1 disks from the Auxiliary peg to the Destination peg.
The recurrence relation for the number of moves is M(n) = 2M(n-1) + 1,
which resolves to the mathematical formula M(n) = 2^n - 1.
*/


#include <stdio.h>
#include <math.h>
void toh(int n, char S, char D, char H, long long *move_count) {
    if (n == 1) {
        printf("Step %lld: Move disk 1 from %c to %c\n", ++(*move_count), S, D);
        return;
    }
    else{
        toh(n - 1, S, H, H, move_count);
        printf("Step %lld: Move disk %d from %c to %c\n", ++(*move_count), n, S, D);
        toh(n - 1, H, D, S, move_count);
    }
}

int main() {
    int test_disks=3;
    long long actual_moves = 0;

    printf(" 1. ALGORITHM EXECUTION (Step-by-Step for n = %d)\n", test_disks);
    printf("====================================================\n");

    toh(test_disks, 'A', 'C', 'B', &actual_moves);
    printf("\nTotal moves taken to solve %d disks: %lld\n\n", test_disks, actual_moves);

    printf(" 2. EXPONENTIAL GROWTH ANALYSIS ( O(2^n) )\n");
    printf("====================================================\n");
    printf("%-10s | %-20s\n", "Disks (n)", "Total Moves (2^n - 1)");
    printf("---------------------------------------------------------------------------------------\n");


    for (int i = 3; i <= 20; i++) {
        long long total_moves = (1LL << i) - 1;
        printf("%-10d | %-20lld\n", i, total_moves);
    }

    return 0;
}
