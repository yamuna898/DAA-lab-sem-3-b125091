/*
Algorithmic Logic
The simulation relies on pseudo-random number generation (rand()) seeded by the current system time to model probability:

1. Fair Coin (50%): We use modulo 2 (rand() % 2).
   If the result is 0, it counts as Heads; if 1, it counts as Tails.
   This enforces a strict 50/50 algorithmic split.
2. Biased Coin (75%): We use modulo 100 (rand() % 100).
   If the generated number is strictly less than 75 (0 through 74), it counts as Heads.
   If it is 75 to 99, it counts as Tails. This perfectly enforces a 75/25 algorithmic bias.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIALS 10000
#define BIAS   75      // Probability (%) of getting Heads

int main()
{
    srand((unsigned)time(NULL));

    int fairH = 0, fairT = 0;
    int biasH = 0, biasT = 0;

    for (int i = 0; i < TRIALS; i++)
    {
        (rand() % 2) ? fairT++ : fairH++;
        (rand() % 100 < BIAS) ? biasH++ : biasT++;
    }

    printf("\n================ Coin Toss Simulation ================\n");
    printf("Trials : %d\n\n", TRIALS);

    printf("%-12s %10s %10s %15s\n","Coin", "Heads", "Tails", "Head Probability");
    printf("--------------------------------------------------------------\n");

    printf("%-12s %10d %10d %14.2f%%\n", "Fair", fairH, fairT, fairH * 100.0 / TRIALS);

    printf("%-12s %10d %10d %14.2f%%\n", "Biased", biasH, biasT, biasH * 100.0 / TRIALS);

    printf("\nExpected Head Probability:\n");
    printf("Fair Coin   : 50%%\n");
    printf("Biased Coin : %d%%\n", BIAS);

    return 0;
}
