#include <stdio.h>
#include <limits.h>

int main() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter dimensions of matrices:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    /*
       If arr = {10, 30, 5, 60}

       Then matrices are:
       A1 = 10 x 30
       A2 = 30 x 5
       A3 = 5 x 60
    */

    // dp[i][j] = minimum scalar multiplications for Ai...Aj
    int dp[N][N];

    // Cost of multiplying one matrix is zero
    for (int i = 1; i < N; i++) {
        dp[i][i] = 0;
    }

    // length represents the number of matrices in the chain
    for (int length = 2; length < N; length++) {

        for (int i = 1; i < N - length + 1; i++) {

            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            // Try every possible position to split the chain
            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n",
           dp[1][N - 1]);

    return 0;
}

/*
Time Complexity: O(N^3)
Space Complexity: O(N^2)
*/