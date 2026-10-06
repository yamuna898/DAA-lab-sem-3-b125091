#include <stdio.h>

struct Station {
    int distance;
    int fuel;
};

int main() {

    int n, D, F;

    printf("Enter number of stations: ");
    scanf("%d", &n);

    struct Station s[n];

    for (int i = 0; i < n; i++) {
        printf("Enter distance and fuel for station %d: ", i + 1);
        scanf("%d %d", &s[i].distance, &s[i].fuel);
    }

    printf("Enter target distance: ");
    scanf("%d", &D);

    printf("Enter starting fuel: ");
    scanf("%d", &F);

    /* Sort stations by distance */

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (s[i].distance > s[j].distance) {

                struct Station temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    int fuel = F;
    int position = 0;
    int stops = 0;

    while (position < D) {

        int bestFuel = -1;
        int bestStation = -1;

        for (int i = 0; i < n; i++) {

            if (s[i].distance <= position && s[i].fuel > 0) {

                if (s[i].fuel > bestFuel) {
                    bestFuel = s[i].fuel;
                    bestStation = i;
                }
            }
        }

        if (fuel >= D - position) {
            break;
        }

        if (bestStation == -1) {
            printf("Cannot reach target.\n");
            return 0;
        }

        fuel += s[bestStation].fuel;
        s[bestStation].fuel = 0;

        stops++;
    }

    printf("Minimum refuelling stops = %d\n", stops);

    return 0;
}