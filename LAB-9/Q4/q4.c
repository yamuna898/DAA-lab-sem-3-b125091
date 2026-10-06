#include <stdio.h>

int main() {

    int n;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int totalCost = 0;

    for (int count = n; count > 1; count--) {

        int first = 0;
        int second = 1;

        if (a[first] > a[second]) {
            int temp = first;
            first = second;
            second = temp;
        }

        for (int i = 2; i < count; i++) {

            if (a[i] < a[first]) {
                second = first;
                first = i;
            }
            else if (a[i] < a[second]) {
                second = i;
            }
        }

        int sum = a[first] + a[second];

        totalCost += sum;

        a[first] = sum;
        a[second] = a[count - 1];
    }

    printf("Minimum total cost = %d\n", totalCost);

    return 0;
}