#include <stdio.h>

#define INF 1000000000

int main() {

    int n;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    int w[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int prefix[n + 1];

    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + w[i];
    }

    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            cost[i][j] = INF;

            int sum = prefix[j + 1] - prefix[i];

            for (int k = i; k < j; k++) {

                int current = cost[i][k]
                            + cost[k + 1][j]
                            + sum;

                if (current < cost[i][j])
                    cost[i][j] = current;
            }
        }
    }

    printf("Minimum alphabetic tree cost = %d\n", cost[0][n - 1]);

    return 0;
}