#include <stdio.h>

void sort(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (a[i] > a[j]) {

                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    for (int i = 0; i < n; i++) {
        printf("Meeting %d start and end: ", i + 1);
        scanf("%d %d", &start[i], &end[i]);
    }

    sort(start, n);
    sort(end, n);

    int i = 0;
    int j = 0;

    int rooms = 0;
    int maxRooms = 0;

    while (i < n) {

        if (start[i] < end[j]) {

            rooms++;

            if (rooms > maxRooms)
                maxRooms = rooms;

            i++;
        }
        else {
            rooms--;
            j++;
        }
    }

    printf("Minimum rooms required = %d\n", maxRooms);

    return 0;
}