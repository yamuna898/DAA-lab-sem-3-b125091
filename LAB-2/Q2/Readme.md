# DAA Lab 02 — Q2: 2-Way vs 3-Way Merge Sort

Implementation and performance comparison of **Regular 2-Way Merge Sort** and **Modified 3-Way Merge Sort** in C.

---

## Objective

The objective of this experiment is to implement and compare:

1. **2-Way Merge Sort**
2. **3-Way Merge Sort**

Both algorithms use the **Divide and Conquer** approach, but differ in how the input array is divided.

The program:

* Implements 2-Way Merge Sort.
* Implements 3-Way Merge Sort.
* Tests both algorithms on the same input.
* Verifies the sorted output.
* Measures execution time.
* Benchmarks both algorithms for different input sizes.
* Generates an SVG graph comparing their actual execution times.

---

## 1. Introduction

Merge Sort is a **divide-and-conquer sorting algorithm**.

The general process is:

```text
Divide
  ↓
Recursively Sort
  ↓
Merge
```

### 2-Way Merge Sort

The array is divided into **two** parts:

```text
              Array
             /     \
            /       \
       Left Half   Right Half
            \       /
             \     /
              Merge
```

### 3-Way Merge Sort

The array is divided into **three** parts:

```text
                 Array
              /    |    \
             /     |     \
          Part 1 Part 2 Part 3
             \     |     /
              \    |    /
               3-Way Merge
```

---

# 2. 2-Way Merge Sort

In 2-Way Merge Sort, the array is recursively divided into two approximately equal halves.

For example:

```text
[45, 12, 89, 33, 7, 99]

          ↓

[45, 12, 89]    [33, 7, 99]
```

Each half is recursively sorted and then merged.

The implementation uses:

```c
twoWayMergeSort()
```

for recursive division and:

```c
mergeTwo()
```

for merging the two sorted sections.

The merge function creates temporary arrays for the left and right sections and uses `INT_MAX` as a sentinel value.

---

## 2.1 2-Way Merge Process

The algorithm follows these steps:

1. Check whether the current portion contains more than one element.
2. Calculate the middle index.
3. Recursively sort the left half.
4. Recursively sort the right half.
5. Merge the two sorted halves.

The recursive division is implemented as:

```c
int middle = left + (right - left) / 2;

twoWayMergeSort(values, left, middle);
twoWayMergeSort(values, middle + 1, right);

mergeTwo(values, left, middle, right);
```

---

# 3. 3-Way Merge Sort

In 3-Way Merge Sort, the array is divided into **three sections**.

For example:

```text
[45, 12, 89, 33, 7, 99]

        ↓

[45, 12]   [89, 33]   [7, 99]
```

Each section is recursively sorted.

The three sorted sections are then merged into a single sorted array.

The implementation uses:

```c
threeWayMergeSort()
```

and:

```c
mergeThree()
```

---

## 3.1 3-Way Division

Two division points are calculated:

```c
int midOne = left + (right - left) / 3;
int midTwo = left + 2 * (right - left) / 3;
```

This creates three sections:

```text
Part 1:
left → midOne

Part 2:
midOne + 1 → midTwo

Part 3:
midTwo + 1 → right
```

The three sections are recursively sorted and then merged.

---

# 4. 3-Way Merge Process

The `mergeThree()` function creates three temporary arrays:

```text
First Part
Second Part
Third Part
```

Each temporary array receives a sentinel:

```c
INT_MAX
```

The smallest available element among the three sections is then selected during each merge step.

Conceptually:

```text
First Part   ──┐
               │
Second Part  ──┼──> Smallest element → Output
               │
Third Part   ──┘
```

The implementation compares the current elements from all three sections before selecting the smallest value.

---

# 5. 2-Way vs 3-Way Merge Sort

| Feature                     | 2-Way Merge Sort | 3-Way Merge Sort |
| --------------------------- | ---------------- | ---------------- |
| Number of divisions         | 2                | 3                |
| Recursive branches          | 2                | 3                |
| Number of sections merged   | 2                | 3                |
| Recursion depth             | `log₂ n`         | `log₃ n`         |
| Merge cost per level        | `O(n)`           | `O(n)`           |
| Overall time complexity     | `O(n log n)`     | `O(n log n)`     |
| Auxiliary space             | `O(n)`           | `O(n)`           |
| Merge comparison complexity | Lower            | Higher           |

Although 3-Way Merge Sort has fewer recursion levels, its merge operation has to select the smallest element from **three sections instead of two**.

Therefore, fewer recursion levels do not automatically mean better practical performance.

---

# 6. Time Complexity

## 6.1 2-Way Merge Sort

The recurrence relation is:

```text
T(n) = 2T(n/2) + O(n)
```

Using the Master Theorem:

```text
a = 2
b = 2
f(n) = O(n)
```

Therefore:

```text
T(n) = O(n log₂ n)
```

Since the base of a logarithm is a constant in asymptotic analysis:

```text
O(n log n)
```

### Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `O(n log n)`    |
| Average Case | `O(n log n)`    |
| Worst Case   | `O(n log n)`    |

---

# 7. Time Complexity — 3-Way Merge Sort

The recurrence relation is:

```text
T(n) = 3T(n/3) + O(n)
```

Using the Master Theorem:

```text
a = 3
b = 3
f(n) = O(n)
```

Therefore:

```text
T(n) = O(n log₃ n)
```

Since the logarithm base is a constant:

```text
O(n log n)
```

### Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `O(n log n)`    |
| Average Case | `O(n log n)`    |
| Worst Case   | `O(n log n)`    |

---

# 8. Space Complexity

Both implementations create temporary arrays during merging.

### 2-Way Merge Sort

Two temporary arrays are created:

```text
Left Part
Right Part
```

Therefore:

```text
Auxiliary Space = O(n)
```

### 3-Way Merge Sort

Three temporary arrays are created:

```text
First Part
Second Part
Third Part
```

Therefore:

```text
Auxiliary Space = O(n)
```

### Comparison

| Algorithm        | Auxiliary Space |
| ---------------- | --------------: |
| 2-Way Merge Sort |          `O(n)` |
| 3-Way Merge Sort |          `O(n)` |

## The temporary arrays are dynamically allocated using `malloc()` and released using `free()`.

# 9. Correctness Test

Before running the large benchmark, the program tests both algorithms using the same 15-element array:

```text
[45, 12, 89, 33, 7, 99, 1, 56, 23, 67, 88, 4, 19, 72, 10]
```

Two copies of the original array are created:

```text
Original Array
      │
      ├──────────────> 2-Way Array
      │
      └──────────────> 3-Way Array
```

This ensures that both algorithms receive exactly the same input.

The expected sorted result is:

```text
[1, 4, 7, 10, 12, 19, 23, 33, 45, 56, 67, 72, 88, 89, 99]
```

The program prints the sorted result and execution time for both algorithms.

---

# 10. Performance Benchmark

The program performs a larger performance benchmark after the correctness test.

### Benchmark Range

```text
Starting N = 10,000
Ending N   = 200,000
Increment  = 20,000
```

Therefore, the tested input sizes are:

```text
10,000
30,000
50,000
70,000
90,000
110,000
130,000
150,000
170,000
190,000
```

The benchmark configuration is defined directly in `createSVGGraph()`.

---

## 10.1 Fair Comparison

For every input size, two arrays are created:

```c
int *arrayTwo;
int *arrayThree;
```

Both arrays receive the **same randomly generated values**.

This ensures that the algorithms are compared using identical input data.

---

## 10.2 Measuring Execution Time

The program uses:

```c
clock()
```

from `<time.h>`.

For 2-Way Merge Sort:

```c
begin = clock();

twoWayMergeSort(arrayTwo, 0, size - 1);

finish = clock();
```

For 3-Way Merge Sort:

```c
begin = clock();

threeWayMergeSort(arrayThree, 0, size - 1);

finish = clock();
```

The elapsed time is calculated as:

```c
(double)(finish - begin) / CLOCKS_PER_SEC
```

---

# 11. Benchmark Output

The program displays the benchmark in the following format:

```text
--- EFFICIENCY BENCHMARK ---
Size (N)   | 2-Way Time      | 3-Way Time
-----------------------------------------------
10000      | ...
30000      | ...
50000      | ...
70000      | ...
90000      | ...
110000     | ...
130000     | ...
150000     | ...
170000     | ...
190000     | ...
```

The actual execution times depend on:

* Processor
* Compiler
* Operating system
* System load
* Memory availability

Therefore, the exact timing values may differ between computers.

---

# 12. SVG Performance Graph

After completing the benchmark, the program generates:

```text
mergesort_comparison.svg
```

The graph compares the measured execution times of both algorithms.

### X-Axis

```text
Array Size (N)
```

### Y-Axis

```text
Time (Seconds)
```

The graph contains two curves:

```text
2-Way Merge Sort
3-Way Merge Sort
```

The program scales the graph using the largest measured execution time.

The SVG is generated directly by writing SVG markup from the C program.

---

# 13. Graph Representation

The generated graph uses:

```text
Array Size (N)
       │
       │
Time   │       ╱
       │     ╱
       │   ╱
       │ ╱
       └────────────────
             N
```

The actual graph is based on the **measured execution times**, rather than theoretical values.

The program converts each benchmark result into an `(x, y)` coordinate and creates an SVG `<polyline>` for each algorithm.

---

# 14. Why 3-Way Merge Sort Is Not Automatically Faster

At first glance, 3-Way Merge Sort appears attractive because:

```text
log₃(n) < log₂(n)
```

Therefore, it has fewer recursion levels.

However, each level of 3-Way Merge Sort performs a more complicated merge.

### 2-Way Merge

At each step, the algorithm compares:

```text
Left element
     vs
Right element
```

### 3-Way Merge

At each step, the algorithm compares:

```text
First element
      vs
Second element
      vs
Third element
```

The implementation explicitly performs comparisons among all three current sections.

Therefore:

```text
3-Way:
Fewer recursion levels
        +
More complicated merge

2-Way:
More recursion levels
        +
Simpler merge
```

The actual benchmark determines which implementation performs better on the tested machine.

---

# 15. Theoretical Comparison

| Property        | 2-Way            | 3-Way            |
| --------------- | ---------------- | ---------------- |
| Recurrence      | `2T(n/2) + O(n)` | `3T(n/3) + O(n)` |
| Recursion depth | `log₂ n`         | `log₃ n`         |
| Merge cost      | `O(n)`           | `O(n)`           |
| Best Case       | `O(n log n)`     | `O(n log n)`     |
| Average Case    | `O(n log n)`     | `O(n log n)`     |
| Worst Case      | `O(n log n)`     | `O(n log n)`     |
| Auxiliary Space | `O(n)`           | `O(n)`           |

Both algorithms therefore belong to the same asymptotic complexity class.

---

# 16. Observations

### Observation 1

Both algorithms correctly sort the input array.

### Observation 2

Both algorithms have:

```text
O(n log n)
```

time complexity.

### Observation 3

3-Way Merge Sort has fewer recursion levels because the input is divided into three parts.

### Observation 4

The 3-way merge operation is more complicated because it must select the smallest element among three sections.

### Observation 5

Asymptotic complexity alone does not determine which implementation will be faster in practice.

### Observation 6

The benchmark provides an empirical comparison of the two implementations.

### Observation 7

The exact execution time is machine-dependent.

---

# 17. Project Structure

```text
DAA-Lab-02/
│
├── q2_merge_sort.c
├── mergesort_comparison.svg
└── README.md
```

### `q2_merge_sort.c`

Contains:

* 2-Way Merge Sort
* 3-Way Merge Sort
* Merge functions
* Correctness test
* Performance benchmark
* SVG graph generation
* Array display function

### `mergesort_comparison.svg`

Generated automatically after running the program.

Contains the performance comparison graph between 2-Way and 3-Way Merge Sort.

### `README.md`

Contains the explanation, algorithm, complexity analysis, benchmark details, observations, and conclusion.

---

# 18. Requirements

A C compiler is required.

Recommended:

* GCC
* MinGW
* Clang

The program uses the following standard libraries:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
```

---

# 19. Compilation

Using GCC:

```bash
gcc q2_merge_sort.c -o q2
```

---

# 20. Execution

### Linux / WSL

```bash
./q2
```

### Windows / MinGW

```bash
gcc q2_merge_sort.c -o q2.exe
q2.exe
```

---

# 21. Program Execution Flow

```text
                 Start
                   │
                   ▼
          Create Test Array
                   │
                   ▼
          Copy Array Twice
             /           \
            ▼             ▼
     2-Way Merge      3-Way Merge
        Sort             Sort
            \             /
             ▼           ▼
          Display Sorted Results
                   │
                   ▼
            Run Benchmark
                   │
                   ▼
          Generate SVG Graph
                   │
                   ▼
                  End
```

The `main()` function first performs the correctness test and then calls:

```c
createSVGGraph("mergesort_comparison.svg");
```

to perform the benchmark and generate the graph.

---

# 22. Conclusion

This experiment implements and compares **2-Way Merge Sort** and **3-Way Merge Sort**.

Both algorithms use the Divide and Conquer strategy and have the same asymptotic time complexity:

```text
2-Way Merge Sort → O(n log n)

3-Way Merge Sort → O(n log n)
```

The main difference is how the input is divided and how the sorted sections are merged.

### 2-Way Merge Sort

```text
              Array
             /     \
            /       \
          Part      Part
            \       /
             \     /
              Merge
```

### 3-Way Merge Sort

```text
                 Array
              /    |    \
             /     |     \
          Part   Part   Part
             \     |     /
              \    |    /
               3-Way Merge
```

3-Way Merge Sort reduces the recursion depth, but its merge operation requires comparisons among three sections.

Therefore:

> **More divisions do not automatically mean better practical performance.**

The theoretical complexity of both algorithms is `O(n log n)`, while their actual performance can differ because of the constant factors and the additional comparisons involved in the 3-way merge.

The benchmark and generated SVG graph provide an experimental comparison of their actual execution times for increasing input sizes.

---

# 23. Final Complexity Summary

| Algorithm            |    Best Case | Average Case |   Worst Case |  Space |
| -------------------- | -----------: | -----------: | -----------: | -----: |
| **2-Way Merge Sort** | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` |
| **3-Way Merge Sort** | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` |

## Final Result

```text
2-Way Merge Sort → O(n log n)

3-Way Merge Sort → O(n log n)
```

Both have the same asymptotic growth rate, but their practical execution times depend on the implementation and the cost of their respective merge operations.

---

# Author

**Yamuna**

B.Tech Computer Science & Engineering