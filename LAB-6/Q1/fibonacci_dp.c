#include <stdio.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int dp[n + 1];

    // Base cases
    dp[0] = 0;
    if (n > 0)
        dp[1] = 1;

    // Build Fibonacci values using previous results
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("The %dth Fibonacci number is: %d\n", n, dp[n]);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/