#include <stdio.h>

struct Item {
    float value;
    float weight;
    float decay;
};

int main() {
    int n;
    float W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value, weight and decay rate for item %d: ", i + 1);
        scanf("%f %f %f", &a[i].value, &a[i].weight, &a[i].decay);
    }

    printf("Enter capacity: ");
    scanf("%f", &W);

    float totalValue = 0;
    float time = 0;

    for (int count = 0; count < n && W > 0; count++) {

        int best = -1;
        float bestDensity = -999999;

        for (int i = 0; i < n; i++) {
            if (a[i].weight > 0) {
                float density = a[i].value / a[i].weight
                              - a[i].decay * time;

                if (density > bestDensity) {
                    bestDensity = density;
                    best = i;
                }
            }
        }

        if (best == -1)
            break;

        float take;

        if (a[best].weight <= W)
            take = a[best].weight;
        else
            take = W;

        totalValue += take * bestDensity;
        W -= take;
        a[best].weight -= take;

        time++;
    }

    printf("Maximum value = %.2f\n", totalValue);

    return 0;
}