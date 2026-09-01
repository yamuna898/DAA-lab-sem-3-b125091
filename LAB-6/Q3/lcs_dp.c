#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    // dp[i][j] stores LCS length of first i and first j characters
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            // Empty string has LCS length 0
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }

            // Characters match
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            // Characters do not match
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];

    printf("Length of LCS = %d\n", length);

    // Construct the actual LCS by tracing the DP table
    char lcs[length + 1];
    lcs[length] = '\0';

    int i = m;
    int j = n;
    int index = length - 1;

    while (i > 0 && j > 0) {

        if (str1[i - 1] == str2[j - 1]) {
            lcs[index] = str1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    printf("Longest Common Subsequence = %s\n", lcs);

    return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/