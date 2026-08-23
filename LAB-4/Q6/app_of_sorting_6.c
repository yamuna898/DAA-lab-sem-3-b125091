#include <stdio.h>
#include <stdlib.h>

// Structure to define an Interval
typedef struct {
    int left;
    int right;
} Interval;

// Structure to define an Event (endpoint)
typedef struct {
    int point;  // Coordinate value
    int type;   // +1 for start endpoint, -1 for end endpoint
} Event;

// Comparator function for qsort
// Sort primarily by coordinate point ascending.
// If points are equal, start events (+1) come before end events (-1).
int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->point != e2->point) {
        return e1->point - e2->point;
    }
    // If coordinates are the same, process start event (+1) before end event (-1)
    return e2->type - e1->type; 
}

// Function to find point p with maximum interval overlap
void findMaxOverlapPoint(Interval intervals[], int n) {
    // 1. Create an array of 2n events
    Event *events = (Event *)malloc(2 * n * sizeof(Event));
    if (events == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        events[2 * i].point = intervals[i].left;
        events[2 * i].type = 1;  // Interval starts

        events[2 * i + 1].point = intervals[i].right;
        events[2 * i + 1].type = -1; // Interval ends
    }

    // 2. Sort the events: O(n log n) time
    qsort(events, 2 * n, sizeof(Event), compareEvents);

    // 3. Sweep through events to track running count and find peak
    int current_overlap = 0;
    int max_overlap = 0;
    int best_point = events[0].point;

    for (int i = 0; i < 2 * n; i++) {
        current_overlap += events[i].type;

        if (current_overlap > max_overlap) {
            max_overlap = current_overlap;
            best_point = events[i].point;
        }
    }

    // Output Results
    printf("Point with maximum interval coverage (p): %d\n", best_point);
    printf("Number of overlapping intervals at p: %d\n", max_overlap);

    free(events);
}

int main() {
    // Example dataset provided in the problem statement
    Interval S[] = {
        {10, 40},
        {20, 60},
        {50, 90},
        {15, 70}
    };
    int n = sizeof(S) / sizeof(S[0]);

    printf("Input Intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("Interval %d: [%d, %d]\n", i + 1, S[i].left, S[i].right);
    }
    printf("\n");

    findMaxOverlapPoint(S, n);

    return 0;
}