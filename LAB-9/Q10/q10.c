#include <stdio.h>
#include <string.h>

int overlap(char a[], char b[]) {

    int la = strlen(a);
    int lb = strlen(b);

    int best = 0;

    int max = la < lb ? la : lb;

    for (int k = 1; k <= max; k++) {

        int match = 1;

        for (int i = 0; i < k; i++) {

            if (a[la - k + i] != b[i]) {
                match = 0;
                break;
            }
        }

        if (match)
            best = k;
    }

    return best;
}

void mergeStrings(char a[], char b[], int ov) {

    int la = strlen(a);

    int pos = la - ov;

    for (int i = ov; b[i] != '\0'; i++) {
        a[pos++] = b[i];
    }

    a[pos] = '\0';
}

int main() {

    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    char s[20][100];

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    while (n > 1) {

        int bestI = 0;
        int bestJ = 1;
        int bestOverlap = -1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                int ov = overlap(s[i], s[j]);

                if (ov > bestOverlap) {

                    bestOverlap = ov;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        mergeStrings(s[bestI], s[bestJ], bestOverlap);

        for (int i = bestJ; i < n - 1; i++) {
            strcpy(s[i], s[i + 1]);
        }

        n--;
    }

    printf("Greedy superstring = %s\n", s[0]);

    return 0;
}