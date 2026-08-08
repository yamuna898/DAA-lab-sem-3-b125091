#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* ============================================================
   1. REGULAR MERGE SORT - 2 WAY
   ============================================================ */

void mergeTwo(int values[], int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int *leftPart = malloc((leftSize + 1) * sizeof(int));
    int *rightPart = malloc((rightSize + 1) * sizeof(int));

    // Copy both halves into temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftPart[i] = values[left + i];

    for (int j = 0; j < rightSize; j++)
        rightPart[j] = values[middle + 1 + j];

    // Sentinel values mark the end of each temporary array
    leftPart[leftSize] = INT_MAX;
    rightPart[rightSize] = INT_MAX;

    int i = 0;
    int j = 0;

    // Merge the two sorted halves
    for (int k = left; k <= right; k++)
    {
        if (leftPart[i] <= rightPart[j])
            values[k] = leftPart[i++];
        else
            values[k] = rightPart[j++];
    }

    free(leftPart);
    free(rightPart);
}

void twoWayMergeSort(int values[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Divide the array into two parts
        twoWayMergeSort(values, left, middle);
        twoWayMergeSort(values, middle + 1, right);

        // Merge the sorted parts
        mergeTwo(values, left, middle, right);
    }
}


/* ============================================================
   2. MODIFIED MERGE SORT - 3 WAY
   ============================================================ */

void mergeThree(int values[], int left, int midOne, int midTwo, int right)
{
    int firstSize = midOne - left + 1;
    int secondSize = midTwo - midOne;
    int thirdSize = right - midTwo;

    int *firstPart = malloc((firstSize + 1) * sizeof(int));
    int *secondPart = malloc((secondSize + 1) * sizeof(int));
    int *thirdPart = malloc((thirdSize + 1) * sizeof(int));

    // Copy the three sections into temporary arrays
    for (int i = 0; i < firstSize; i++)
        firstPart[i] = values[left + i];

    for (int i = 0; i < secondSize; i++)
        secondPart[i] = values[midOne + 1 + i];

    for (int i = 0; i < thirdSize; i++)
        thirdPart[i] = values[midTwo + 1 + i];

    // Add sentinel values to detect the end of each part
    firstPart[firstSize] = INT_MAX;
    secondPart[secondSize] = INT_MAX;
    thirdPart[thirdSize] = INT_MAX;

    int i = 0;
    int j = 0;
    int k = 0;

    // Select the smallest value from the three parts
    for (int pos = left; pos <= right; pos++)
    {
        if (firstPart[i] <= secondPart[j] &&
            firstPart[i] <= thirdPart[k])
        {
            values[pos] = firstPart[i++];
        }
        else if (secondPart[j] <= firstPart[i] &&
                 secondPart[j] <= thirdPart[k])
        {
            values[pos] = secondPart[j++];
        }
        else
        {
            values[pos] = thirdPart[k++];
        }
    }

    free(firstPart);
    free(secondPart);
    free(thirdPart);
}

void threeWayMergeSort(int values[], int left, int right)
{
    if (left >= right)
        return;

    // Divide the array into three sections
    int midOne = left + (right - left) / 3;
    int midTwo = left + 2 * (right - left) / 3;

    threeWayMergeSort(values, left, midOne);

    if (midOne + 1 <= midTwo)
        threeWayMergeSort(values, midOne + 1, midTwo);

    if (midTwo + 1 <= right)
        threeWayMergeSort(values, midTwo + 1, right);

    // Merge the three sorted sections
    mergeThree(values, left, midOne, midTwo, right);
}


/* ============================================================
   3. BENCHMARK AND SVG GRAPH GENERATION
   ============================================================ */

void createSVGGraph(const char *fileName)
{
    // Benchmark range
    int firstSize = 10000;
    int lastSize = 200000;
    int increment = 20000;

    int testCount = (lastSize - firstSize) / increment + 1;

    int *arraySizes = malloc(testCount * sizeof(int));
    double *twoWayTimes = malloc(testCount * sizeof(double));
    double *threeWayTimes = malloc(testCount * sizeof(double));

    printf("--- EFFICIENCY BENCHMARK ---\n");
    printf("%-10s | %-15s | %-15s\n",
           "Size (N)", "2-Way Time", "3-Way Time");
    printf("-----------------------------------------------\n");

    int testIndex = 0;

    for (int size = firstSize; size <= lastSize; size += increment)
    {
        int *arrayTwo = malloc(size * sizeof(int));
        int *arrayThree = malloc(size * sizeof(int));

        // Fill both arrays with the same random values
        for (int i = 0; i < size; i++)
        {
            int randomValue = rand() % 100000;

            arrayTwo[i] = randomValue;
            arrayThree[i] = randomValue;
        }

        clock_t begin;
        clock_t finish;

        // Measure 2-way merge sort
        begin = clock();
        twoWayMergeSort(arrayTwo, 0, size - 1);
        finish = clock();

        twoWayTimes[testIndex] =
            (double)(finish - begin) / CLOCKS_PER_SEC;

        // Measure 3-way merge sort
        begin = clock();
        threeWayMergeSort(arrayThree, 0, size - 1);
        finish = clock();

        threeWayTimes[testIndex] =
            (double)(finish - begin) / CLOCKS_PER_SEC;

        printf("%-10d | %-15f | %-15f\n",
               size,
               twoWayTimes[testIndex],
               threeWayTimes[testIndex]);

        arraySizes[testIndex] = size;
        testIndex++;

        free(arrayTwo);
        free(arrayThree);
    }


    /* ---------- Create SVG File ---------- */

    FILE *graphFile = fopen(fileName, "w");

    if (!graphFile)
    {
        printf("Error creating SVG file!\n");

        free(arraySizes);
        free(twoWayTimes);
        free(threeWayTimes);

        return;
    }

    // Find the largest time for graph scaling
    double largestTime = 0.001;

    for (int i = 0; i < testCount; i++)
    {
        if (twoWayTimes[i] > largestTime)
            largestTime = twoWayTimes[i];

        if (threeWayTimes[i] > largestTime)
            largestTime = threeWayTimes[i];
    }


    /* ---------- SVG Header ---------- */

    fprintf(graphFile,
            "<svg xmlns=\"http://www.w3.org/2000/svg\" "
            "width=\"900\" height=\"600\">\n");

    fprintf(graphFile,
            "<rect width=\"100%%\" height=\"100%%\" "
            "fill=\"#1e1e1e\"/>\n");


    /* ---------- Grid ---------- */

    for (int i = 50; i <= 800; i += 75)
    {
        fprintf(graphFile,
                "<line x1=\"50\" y1=\"%d\" x2=\"850\" y2=\"%d\" "
                "stroke=\"#333\" stroke-width=\"1\"/>\n",
                i, i);

        fprintf(graphFile,
                "<line x1=\"%d\" y1=\"50\" x2=\"%d\" y2=\"550\" "
                "stroke=\"#333\" stroke-width=\"1\"/>\n",
                i, i);
    }


    /* ---------- Axes and Labels ---------- */

    fprintf(graphFile,
            "<line x1=\"50\" y1=\"550\" x2=\"850\" y2=\"550\" "
            "stroke=\"white\" stroke-width=\"2\"/>\n");

    fprintf(graphFile,
            "<line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"550\" "
            "stroke=\"white\" stroke-width=\"2\"/>\n");

    fprintf(graphFile,
            "<text x=\"400\" y=\"590\" fill=\"white\" "
            "font-family=\"sans-serif\" font-size=\"16\">"
            "Array Size (N)</text>\n");

    fprintf(graphFile,
            "<text x=\"20\" y=\"350\" fill=\"white\" "
            "font-family=\"sans-serif\" font-size=\"16\" "
            "transform=\"rotate(-90 20,350)\">"
            "Time (Seconds)</text>\n");

    fprintf(graphFile,
            "<text x=\"50\" y=\"30\" fill=\"white\" "
            "font-family=\"sans-serif\" font-size=\"20\" "
            "font-weight=\"bold\">"
            "Efficiency: 2-Way vs 3-Way Merge Sort</text>\n");


    /* ---------- Plot 2-Way Merge Sort ---------- */

    fprintf(graphFile,
            "<polyline fill=\"none\" stroke=\"#60a5fa\" "
            "stroke-width=\"4\" stroke-linejoin=\"round\" "
            "points=\"");

    for (int i = 0; i < testCount; i++)
    {
        int x = 50 +
                (int)(((double)arraySizes[i] /
                       arraySizes[testCount - 1]) * 800);

        int y = 550 -
                (int)((twoWayTimes[i] / largestTime) * 500);

        fprintf(graphFile, "%d,%d ", x, y);
    }

    fprintf(graphFile, "\"/>\n");


    /* ---------- Plot 3-Way Merge Sort ---------- */

    fprintf(graphFile,
            "<polyline fill=\"none\" stroke=\"#f87171\" "
            "stroke-width=\"4\" stroke-linejoin=\"round\" "
            "points=\"");

    for (int i = 0; i < testCount; i++)
    {
        int x = 50 +
                (int)(((double)arraySizes[i] /
                       arraySizes[testCount - 1]) * 800);

        int y = 550 -
                (int)((threeWayTimes[i] / largestTime) * 500);

        fprintf(graphFile, "%d,%d ", x, y);
    }

    fprintf(graphFile, "\"/>\n");


    /* ---------- Graph Legend ---------- */

    fprintf(graphFile,
            "<rect x=\"80\" y=\"60\" width=\"250\" height=\"80\" "
            "fill=\"#2d2d2d\" stroke=\"#555\" rx=\"5\"/>\n");

    fprintf(graphFile,
            "<text x=\"100\" y=\"90\" fill=\"#60a5fa\" "
            "font-family=\"sans-serif\" font-size=\"16\" "
            "font-weight=\"bold\">"
            "2-Way Merge Sort</text>\n");

    fprintf(graphFile,
            "<text x=\"100\" y=\"120\" fill=\"#f87171\" "
            "font-family=\"sans-serif\" font-size=\"16\" "
            "font-weight=\"bold\">"
            "3-Way Merge Sort</text>\n");

    fprintf(graphFile, "</svg>\n");

    fclose(graphFile);

    // Release memory used for benchmark results
    free(arraySizes);
    free(twoWayTimes);
    free(threeWayTimes);

    printf("\nSVG graph generated as '%s'.\n", fileName);
}


/* ============================================================
   4. ARRAY PRINTING
   ============================================================ */

void displayArray(int values[], int size)
{
    printf("[");

    for (int i = 0; i < size; i++)
    {
        printf("%d%s",
               values[i],
               i == size - 1 ? "" : ", ");
    }

    printf("]\n");
}


/* ============================================================
   5. MAIN FUNCTION
   ============================================================ */

int main()
{
    /* ---------- Correctness Test ---------- */

    int testSize = 15;

    int original[] =
    {
        45, 12, 89, 33, 7,
        99, 1, 56, 23, 67,
        88, 4, 19, 72, 10
    };

    int twoWayArray[15];
    int threeWayArray[15];

    // Copy the original data into both test arrays
    for (int i = 0; i < testSize; i++)
    {
        twoWayArray[i] = original[i];
        threeWayArray[i] = original[i];
    }

    printf("--- CORRECTNESS TEST ---\n");

    printf("Original Array : ");
    displayArray(original, testSize);

    clock_t startTime;
    clock_t endTime;


    /* ---------- Test 2-Way Merge Sort ---------- */

    startTime = clock();

    twoWayMergeSort(twoWayArray, 0, testSize - 1);

    endTime = clock();

    printf("2-Way Sorted   : ");
    displayArray(twoWayArray, testSize);

    printf("  -> Time taken: %f seconds\n\n",
           (double)(endTime - startTime) / CLOCKS_PER_SEC);


    /* ---------- Test 3-Way Merge Sort ---------- */

    startTime = clock();

    threeWayMergeSort(threeWayArray, 0, testSize - 1);

    endTime = clock();

    printf("3-Way Sorted   : ");
    displayArray(threeWayArray, testSize);

    printf("  -> Time taken: %f seconds\n\n",
           (double)(endTime - startTime) / CLOCKS_PER_SEC);


    /* ---------- Benchmark and Graph ---------- */

    createSVGGraph("mergesort_comparison.svg");

    return 0;
}