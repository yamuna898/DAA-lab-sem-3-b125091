/*
Algorithmic Logic
Both algorithms rely on repeatedly swapping adjacent elements if they are in the wrong order.
However, their termination conditions differ:

1. Unoptimized Bubble Sort:
   Runs completely through its O(n^2) nested loops no matter what.
   It lacks the ability to recognize if the array is already sorted.
2. Optimized Bubble Sort:
   Introduces a swapped boolean flag. If the inner loop finishes a full pass without making a single swap,
   the algorithm knows the array is fully sorted and breaks out early, saving unnecessary comparisons.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int bubbleSort(int arr[], int n, int optimized)
{
    int comparisons = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (optimized && !swapped)break;
    }

    return comparisons;
}

void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void analyzeCase(char title[], int arr[], int n)
{
    int a[SIZE], b[SIZE];

    copyArray(arr, a, n);
    copyArray(arr, b, n);

    printf("%-28s %6d %12d\n",
           title,
           bubbleSort(a, n, 0),
           bubbleSort(b, n, 1));
}



//-----------------------------------MAIN------------------------------------
int main()
{
    srand((unsigned)time(NULL));

    int arr[SIZE];

    printf("\n========== Bubble Sort Comparison ==========\n\n");
    printf("%-28s %6s %12s\n", "Case", "Normal", "Optimized");
    printf("----------------------------------------------------\n");

    // Best Case
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    analyzeCase("Best (Sorted)", arr, SIZE);

    // Worst Case
    for (int i = 0; i < SIZE; i++)
        arr[i] = SIZE - i;

    analyzeCase("Worst (Reverse)", arr, SIZE);

    // Average Case
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    analyzeCase("Average (Random)", arr, SIZE);

    return 0;
}
