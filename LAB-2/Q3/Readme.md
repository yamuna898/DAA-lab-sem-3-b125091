# DAA Lab — K-Way Merge

## Sequential Merging vs Divide-and-Conquer Merging

This project implements and compares two approaches for merging multiple sorted arrays into a single sorted array:

1. **Sequential Merging**
2. **Divide-and-Conquer Merging**

Both methods take `k` sorted arrays, each containing the same number of elements, and produce one sorted array containing all elements.

The program also:

* Performs a correctness test.
* Displays the input arrays.
* Displays the result produced by both methods.
* Measures execution time.
* Benchmarks both approaches for different values of `k`.
* Demonstrates the difference between sequential and divide-and-conquer merging.

---

# 1. Objective

The objective of this experiment is to implement and compare two techniques for merging `k` sorted arrays.

The main focus is understanding how the **order in which arrays are merged** affects the total running time.

The two approaches are:

### Method 1 — Sequential Merging

Merge the arrays one at a time:

```text
A1 + A2
     ↓
  Result
     +
    A3
     ↓
  Result
     +
    A4
     ↓
   ...
```

### Method 2 — Divide and Conquer

Divide the collection of arrays into groups, recursively merge each group, and finally merge the resulting groups:

```text
             A1 A2 A3 A4
              /       \
           A1 A2     A3 A4
             \         /
              \       /
              Final
```

---

# 2. Problem Statement

Given `k` sorted arrays, each containing `n` elements:

```text
A1
A2
A3
...
Ak
```

merge all of them into one sorted array containing:

```text
n × k
```

elements.

For example:

```text
A1 = [1, 5, 9]
A2 = [2, 6, 10]
A3 = [3, 7, 11]
A4 = [4, 8, 12]
```

The required output is:

```text
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
```

---

# 3. Common Merge Function

Both approaches use the same function:

```c
combineArrays()
```

This function merges **two already sorted arrays** into one sorted array.

Its parameters are:

```c
combineArrays(
    first,
    sizeFirst,
    second,
    sizeSecond
)
```

It creates a new array whose size is:

```text
sizeFirst + sizeSecond
```

---

## 3.1 Two-Pointer Technique

The merge operation maintains two indices:

```text
i → first array
j → second array
```

At each step, the smaller current element is copied into the result.

For example:

```text
First:  [1, 5, 9]
         ↑

Second: [2, 6, 10]
         ↑
```

Compare:

```text
1 < 2
```

so `1` is copied.

Then:

```text
First:  [1, 5, 9]
            ↑

Second: [2, 6, 10]
         ↑
```

Now compare:

```text
5 > 2
```

so `2` is copied.

This continues until both arrays are completely processed.

---

# 4. Method 1 — Sequential Merging

Sequential merging combines the arrays **one at a time**.

Suppose there are four arrays:

```text
A1, A2, A3, A4
```

The process is:

```text
Step 1:

A1 + A2
 ↓
R1


Step 2:

R1 + A3
 ↓
R2


Step 3:

R2 + A4
 ↓
Final Result
```

The implementation first copies the first input array into `combined`.

It then iterates through the remaining arrays and repeatedly calls:

```c
combineArrays()
```

After every merge, the previous result is freed and replaced with the new result.

---

## 4.1 Sequential Merging Example

Given:

```text
A1 = [1, 5, 9]
A2 = [2, 6, 10]
A3 = [3, 7, 11]
A4 = [4, 8, 12]
```

The algorithm performs:

```text
[1,5,9]
   +
[2,6,10]

       ↓

[1,2,5,6,9,10]
```

Then:

```text
[1,2,5,6,9,10]
          +
       [3,7,11]

             ↓

[1,2,3,5,6,7,9,10,11]
```

Then:

```text
[1,2,3,5,6,7,9,10,11]
              +
           [4,8,12]

                    ↓

[1,2,3,4,5,6,7,8,9,10,11,12]
```

---

# 5. Sequential Merging Complexity

Let:

* `k` = number of arrays
* `n` = number of elements in each array

The total number of elements is:

```text
N = n × k
```

During sequential merging, the intermediate result keeps becoming larger.

The merge sizes are approximately:

```text
n + n
2n + n
3n + n
4n + n
...
```

Therefore, the total work is:

```text
2n + 3n + 4n + ... + kn
```

which gives:

```text
O(n × k²)
```

### Sequential Merge Complexity

```text
Time = O(nk²)
```

where:

```text
n = elements per array
k = number of arrays
```

---

# 6. Method 2 — Divide and Conquer

The second approach uses **Divide and Conquer**.

Instead of merging the arrays one by one, the collection of arrays is divided into smaller groups.

For example, with four arrays:

```text
              A1 A2 A3 A4
               /       \
              /         \
           A1 A2       A3 A4
             \           /
              \         /
               \       /
                Final
```

Each group is recursively merged.

---

## 6.1 Divide Step

The collection of arrays is divided around the middle:

```c
int middle = start + (end - start) / 2;
```

This creates:

```text
Left Group
Right Group
```

The function recursively processes both groups.

---

## 6.2 Conquer Step

Each group is recursively reduced until only one array remains.

For example:

```text
A1 A2 A3 A4

      ↓

A1 A2       A3 A4

      ↓

A1   A2    A3   A4
```

A single array is already sorted, so it becomes the base case.

---

## 6.3 Combine Step

The sorted results from the left and right groups are merged:

```text
Left Result
     +
Right Result
     ↓
Combined Result
```

The same `combineArrays()` function is used for this final merge.

---

# 7. Divide-and-Conquer Example

For:

```text
A1 = [1,5,9]
A2 = [2,6,10]
A3 = [3,7,11]
A4 = [4,8,12]
```

the recursion looks like:

```text
                  A1 A2 A3 A4
                 /          \
              A1 A2        A3 A4
              /   \        /   \
             A1   A2      A3   A4
              \   /        \   /
               A1+A2       A3+A4
                  \          /
                   \        /
                    Final
```

First:

```text
A1 + A2
```

produces:

```text
[1,2,5,6,9,10]
```

and:

```text
A3 + A4
```

produces:

```text
[3,4,7,8,11,12]
```

Finally:

```text
[1,2,5,6,9,10]
           +
[3,4,7,8,11,12]
           ↓
[1,2,3,4,5,6,7,8,9,10,11,12]
```

---

# 8. Divide-and-Conquer Complexity

At every level of the recursion, all `n × k` elements participate in merging.

The number of levels is approximately:

```text
log₂ k
```

Therefore:

```text
Time = O(nk log k)
```

### Divide-and-Conquer Merge Complexity

```text
Time = O(nk log k)
```

---

# 9. Complexity Comparison

| Method             | Time Complexity | Main Idea                    |
| ------------------ | --------------: | ---------------------------- |
| Sequential Merging |        `O(nk²)` | Merge arrays one by one      |
| Divide and Conquer |   `O(nk log k)` | Recursively divide and merge |

Where:

```text
n = elements per array
k = number of arrays
```

The total number of elements in the final result is:

```text
N = nk
```

Therefore, the complexities can also be expressed as:

| Method             | In Terms of `N` and `k` |
| ------------------ | ----------------------: |
| Sequential Merging |                 `O(Nk)` |
| Divide and Conquer |            `O(N log k)` |

---

# 10. Why Divide and Conquer Is More Efficient

The major difference is the size of the intermediate arrays.

### Sequential

The intermediate result becomes larger after every merge:

```text
n
2n
3n
4n
...
kn
```

Large arrays are repeatedly merged with another array.

This leads to:

```text
O(nk²)
```

---

### Divide and Conquer

The merging is balanced.

At each recursion level:

```text
All elements ≈ nk
```

are processed once.

The number of levels is:

```text
log₂ k
```

Therefore:

```text
O(nk log k)
```

This is significantly better as `k` becomes large.

---

# 11. Complexity Growth

For a fixed number of elements per array:

```text
Sequential:

O(nk²)
      ↑
quadratic in k
```

while:

```text
Divide and Conquer:

O(nk log k)
      ↑
logarithmic factor in k
```

As `k` increases, the difference becomes increasingly significant.

Conceptually:

```text
Running Time
    │
    │                         Sequential
    │                       /
    │                     /
    │                  /
    │              ___/
    │          ___/
    │      ___/
    │  ___/       Divide & Conquer
    │_/       ___/
    └────────────────────────── k
```

---

# 12. Correctness Test

The program first performs a correctness test using:

```text
Number of Arrays = 4
Elements per Array = 3
```

The input arrays are:

```text
Array 1: [1, 5, 9]
Array 2: [2, 6, 10]
Array 3: [3, 7, 11]
Array 4: [4, 8, 12]
```

The expected final result is:

```text
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
```

Both methods should produce exactly the same result.

The program displays:

```text
--- CORRECTNESS TEST ---

Array 1: [1, 5, 9]
Array 2: [2, 6, 10]
Array 3: [3, 7, 11]
Array 4: [4, 8, 12]

Method 1 - Sequential Result:
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

Method 2 - Divide & Conquer Result:
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
```

---

# 13. Performance Benchmark

After the correctness test, the program runs a performance benchmark.

The number of elements in each array is fixed at:

```text
n = 500
```

The following values of `k` are tested:

```text
100
500
1000
2000
4000
```

Therefore, the total number of elements processed is:

|   `k` | Elements per Array | Total Elements `n × k` |
| ----: | -----------------: | ---------------------: |
|   100 |                500 |                 50,000 |
|   500 |                500 |                250,000 |
| 1,000 |                500 |                500,000 |
| 2,000 |                500 |              1,000,000 |
| 4,000 |                500 |              2,000,000 |

---

# 14. Benchmark Input Generation

The benchmark generates sorted input arrays using:

```c
input[i][j] = i + (j * numberOfArrays);
```

This creates interleaved values across the arrays.

For example, with four arrays:

```text
Array 1 → 0, 4, 8, 12, ...
Array 2 → 1, 5, 9, 13, ...
Array 3 → 2, 6, 10, 14, ...
Array 4 → 3, 7, 11, 15, ...
```

This produces arrays that are individually sorted while making the values interleaved between arrays.

The code uses this specifically to create a demanding merging workload.

---

# 15. Measuring Execution Time

The program uses the C `clock()` function from:

```c
#include <time.h>
```

For each method:

```text
Start clock
    ↓
Run merging algorithm
    ↓
Stop clock
    ↓
Calculate elapsed time
```

The execution time is calculated using:

```c
(double)(finish - start) / CLOCKS_PER_SEC
```

---

# 16. Benchmark Output

The program displays results in the following format:

```text
--- EFFICIENCY BENCHMARK ---
Elements per array = 500
Comparing sequential and divide-and-conquer merging

k          | Sequential Time     | Divide & Conquer Time
--------------------------------------------------------------
100        | ...
500        | ...
1000       | ...
2000       | ...
4000       | ...
```

The exact execution times depend on:

* Processor
* Operating system
* Compiler
* System load
* Available memory
* Runtime environment

Therefore, the numerical values may differ between machines.

---

# 17. Memory Management

The program uses dynamic memory allocation extensively.

Input arrays are allocated using:

```c
malloc()
```

The result of every merge is also dynamically allocated.

After a result is no longer required, it is released using:

```c
free()
```

For example, sequential merging performs:

```text
Old Result
    ↓
Merge
    ↓
New Result
    ↓
free(Old Result)
```

The benchmark also frees:

* Sequential result
* Divide-and-conquer result
* Every input array
* The array of input pointers

This prevents memory from accumulating throughout the benchmark.

---

# 18. Important Data Structure

The program represents multiple arrays using a pointer-to-pointer:

```c
int **input;
```

Conceptually:

```text
input
  │
  ├──→ Array 1
  │
  ├──→ Array 2
  │
  ├──→ Array 3
  │
  └──→ Array k
```

Each individual array is dynamically allocated:

```c
input[i] = malloc(elements * sizeof(int));
```

This allows the program to handle a variable number of arrays.

---

# 19. Base Case — Divide and Conquer

The recursive algorithm stops when only one array remains:

```c
if (start == end)
```

At that point, the array is already sorted.

The function simply creates a copy and returns it.

Therefore:

```text
One array
   ↓
Already sorted
   ↓
Return copy
```

This is the **base case** of the recursive algorithm.

---

# 20. Recursive Structure

The divide-and-conquer algorithm follows:

```text
divideMerge()
      │
      ▼
divideMergeRecursive()
      │
      ├──────────────┐
      ▼              ▼
 Left Group      Right Group
      │              │
      ▼              ▼
 Recursive        Recursive
 Merge            Merge
      │              │
      └──────┬───────┘
             ▼
       combineArrays()
             │
             ▼
       Final Sorted Array
```

This structure is what produces the `O(nk log k)` complexity.

---

# 21. Function Overview

| Function                 | Purpose                                     |
| ------------------------ | ------------------------------------------- |
| `combineArrays()`        | Merge two sorted arrays                     |
| `sequentialMerge()`      | Sequentially merge all arrays               |
| `divideMergeRecursive()` | Recursive divide-and-conquer implementation |
| `divideMerge()`          | Wrapper for divide-and-conquer merging      |
| `runBenchmark()`         | Compare execution times                     |
| `showArray()`            | Print an array                              |
| `main()`                 | Correctness test and benchmark execution    |

---

# 22. Program Execution Flow

```text
                     START
                       │
                       ▼
              Create sample arrays
                       │
                       ▼
              Display input arrays
                       │
             ┌─────────┴─────────┐
             ▼                   ▼
      Sequential Merge     Divide & Conquer
             │                   │
             ▼                   ▼
       Sorted Result       Sorted Result
             │                   │
             └─────────┬─────────┘
                       ▼
                Display Results
                       │
                       ▼
                 Free Memory
                       │
                       ▼
                Run Benchmark
                       │
                       ▼
                Test k values
                       │
                       ▼
               Measure Runtime
                       │
                       ▼
                      END
```

---

# 23. Theoretical Comparison

| Property               | Sequential     | Divide & Conquer      |
| ---------------------- | -------------- | --------------------- |
| Strategy               | Sequential     | Divide and Conquer    |
| Merge order            | One at a time  | Balanced pairs/groups |
| Number of merge levels | `k`            | `log₂ k`              |
| Time Complexity        | `O(nk²)`       | `O(nk log k)`         |
| Final output size      | `nk`           | `nk`                  |
| Uses recursion         | No             | Yes                   |
| Uses `combineArrays()` | Yes            | Yes                   |
| Suitable for large `k` | Less efficient | More efficient        |

---

# 24. Key Difference

The most important difference between the two methods is **how often large intermediate arrays are processed**.

### Sequential

```text
A1 + A2
       ↓
(A1+A2) + A3
       ↓
(A1+A2+A3) + A4
       ↓
...
```

The intermediate result becomes larger and larger.

### Divide and Conquer

```text
A1 + A2       A3 + A4
     ↓             ↓
  Result 1      Result 2
       \          /
        \        /
          Final
```

The merging is balanced, reducing the number of times large intermediate arrays are processed.

---

# 25. Advantages and Disadvantages

## Sequential Merging

### Advantages

* Very simple to implement.
* Easy to understand.
* No recursion required.
* Straightforward control flow.

### Disadvantages

* Becomes inefficient as `k` increases.
* Repeatedly merges increasingly large arrays.
* Time complexity is `O(nk²)`.

---

## Divide and Conquer

### Advantages

* Better asymptotic performance.
* Balanced merging.
* Reduces the number of merge levels.
* More suitable for a large number of sorted arrays.

### Disadvantages

* More complicated implementation.
* Uses recursion.
* Requires additional temporary memory.
* Recursive function calls introduce additional overhead.

---

# 26. Conclusion

This experiment compares two approaches for merging `k` sorted arrays.

The **Sequential Merging** approach merges one array at a time and has:

```text
O(nk²)
```

time complexity.

The **Divide-and-Conquer Merging** approach recursively divides the arrays into smaller groups and merges them in a balanced manner, giving:

```text
O(nk log k)
```

time complexity.

Therefore, as the number of arrays `k` increases, divide-and-conquer merging becomes significantly more efficient than sequential merging.

The key lesson is:

> **The order in which multiple sorted arrays are merged can have a major effect on overall time complexity.**

---

# 27. Final Complexity Summary

| Method                       | Best / General Time Complexity |   Space |
| ---------------------------- | -----------------------------: | ------: |
| **Sequential Merging**       |                       `O(nk²)` | `O(nk)` |
| **Divide & Conquer Merging** |                  `O(nk log k)` | `O(nk)` |

Where:

```text
n = number of elements in each array
k = number of sorted arrays
N = total number of elements = n × k
```

In terms of the total number of elements `N`:

| Method                 |   Complexity |
| ---------------------- | -----------: |
| **Sequential Merging** |      `O(Nk)` |
| **Divide & Conquer**   | `O(N log k)` |

---

# 28. Compilation and Execution

## Compile

Using GCC:

```bash
gcc k_way_merge.c -o k_way_merge
```

## Run

### Linux / WSL

```bash
./k_way_merge
```

### Windows / MinGW

```bash
gcc k_way_merge.c -o k_way_merge.exe
k_way_merge.exe
```

---

# 29. Requirements

* C compiler
* GCC / MinGW / Clang
* Standard C library
* Basic understanding of:

  * Arrays
  * Pointers
  * Dynamic memory allocation
  * Recursion
  * Merge Sort
  * Big-O notation

---

# 30. Final Result

```text
Sequential Merging
        ↓
   O(nk²)

Divide & Conquer
        ↓
   O(nk log k)
```

For a large number of sorted arrays:

```text
Divide & Conquer
        ↓
   More scalable
        ↓
   Better asymptotic performance
```

---

# Author

**Yamuna**

B.Tech Computer Science & Engineering