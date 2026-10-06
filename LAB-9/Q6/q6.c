#include <stdio.h>
#include <string.h>

int main() {

    char s[1000];
    int K;

    printf("Enter string: ");
    scanf("%s", s);

    printf("Enter K: ");
    scanf("%d", &K);

    int n = strlen(s);

    int freq[256] = {0};
    int nextAvailable[256] = {0};

    for (int i = 0; i < n; i++) {
        freq[(unsigned char)s[i]]++;
    }

    char result[1000];

    for (int pos = 0; pos < n; pos++) {

        int best = -1;

        for (int c = 0; c < 256; c++) {

            if (freq[c] > 0 && nextAvailable[c] <= pos) {

                if (best == -1 || freq[c] > freq[best]) {
                    best = c;
                }
            }
        }

        if (best == -1) {
            printf("Impossible\n");
            return 0;
        }

        result[pos] = best;

        freq[best]--;

        nextAvailable[best] = pos + K;
    }

    result[n] = '\0';

    printf("Reorganised string = %s\n", result);

    return 0;
}