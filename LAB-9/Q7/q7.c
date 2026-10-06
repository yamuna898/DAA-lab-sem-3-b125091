#include <stdio.h>

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] % 2 == 1)
            a[i] = a[i] * 2;
    }

    int answer = 1000000000;

    while (1) {

        int min = a[0];
        int max = a[0];
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {

            if (a[i] < min)
                min = a[i];

            if (a[i] > max) {
                max = a[i];
                maxIndex = i;
            }
        }

        int deviation = max - min;

        if (deviation < answer)
            answer = deviation;

        /* Maximum cannot be divided anymore */

        if (max % 2 == 1)
            break;

        a[maxIndex] = max / 2;
    }

    printf("Minimum deviation = %d\n", answer);

    return 0;
}