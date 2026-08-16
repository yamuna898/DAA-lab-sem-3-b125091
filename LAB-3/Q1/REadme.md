# Binary Search vs Ternary Search in C

A C implementation comparing **Binary Search** and **Ternary Search** on a sorted array.

The program performs searches and tracks the number of iterations required by each algorithm. It also includes functions for benchmarking the execution time of multiple searches.

---

## Overview

This project compares two divide-and-conquer searching algorithms:

* **Binary Search** — divides the search range into **2 parts**.
* **Ternary Search** — divides the search range into **3 parts**.

Both algorithms require the input array to be **sorted**.

### Key Difference

| Feature                     | Binary Search  | Ternary Search |
| --------------------------- | -------------- | -------------- |
| Number of divisions         | 2              | 3              |
| Comparisons per iteration   | Up to 2        | Up to 4        |
| Worst-case time             | `O(log₂ n)`    | `O(log₃ n)`    |
| Best-case time              | `O(1)`         | `O(1)`         |
| Space complexity            | `O(1)`         | `O(1)`         |
| Array required to be sorted | Yes            | Yes            |
| Practical performance       | Usually faster | Usually slower |

Although ternary search reduces the search range more aggressively, it performs more comparisons in each iteration. Therefore, **binary search is generally faster in practice for searching a sorted array**.

---

## How the Program Works

The program creates an array of `1000` elements:

```c
arr[i] = i * 2;
```

Therefore, the array looks like:

```text
0, 2, 4, 6, 8, 10, ... , 1998
```

The target used in the single-search example is:

```text
1532
```

Since:

```text
1532 / 2 = 766
```

the target exists at:

```text
Index = 766
```

The program then searches for this value using both Binary Search and Ternary Search.

---

# Binary Search

## Algorithm

Binary Search works by repeatedly dividing the current search interval into two halves.

Suppose:

```text
low = 0
high = n - 1
```

The middle element is calculated as:

```c
mid = low + (high - low) / 2;
```

Then three cases are possible:

### Case 1 — Target Found

```text
arr[mid] == target
```

Return `mid`.

### Case 2 — Target is Greater

```text
arr[mid] < target
```

The target must be in the right half.

```text
low = mid + 1
```

### Case 3 — Target is Smaller

```text
arr[mid] > target
```

The target must be in the left half.

```text
high = mid - 1
```

This process continues until the target is found or:

```text
low > high
```

which means the target does not exist in the array.

---

## Binary Search Example

Consider:

```text
[2, 4, 6, 8, 10, 12, 14, 16]
```

Searching for:

```text
14
```

The process is approximately:

```text
                [2 4 6 8 10 12 14 16]
                         ^
                        mid

Target > mid
        ↓

                [10 12 14 16]
                     ^
                    mid

Target > mid
        ↓

                    [14 16]
                     ^
                    mid

Target found
```

Each iteration eliminates approximately half of the remaining elements.

---

# Ternary Search

## Algorithm

Ternary Search divides the search range into **three sections**.

Two middle positions are calculated:

```c
third = (high - low) / 3;

mid1 = low + third;
mid2 = high - third;
```

The algorithm then checks:

```text
arr[mid1]
arr[mid2]
```

There are three possible regions where the target can exist.

### Case 1 — Target Found at `mid1`

```text
arr[mid1] == target
```

Return `mid1`.

### Case 2 — Target Found at `mid2`

```text
arr[mid2] == target
```

Return `mid2`.

### Case 3 — Target is Smaller Than `arr[mid1]`

```text
target < arr[mid1]
```

Search only the first third:

```text
high = mid1 - 1
```

### Case 4 — Target is Greater Than `arr[mid2]`

```text
target > arr[mid2]
```

Search only the last third:

```text
low = mid2 + 1
```

### Case 5 — Target Lies Between `mid1` and `mid2`

Search the middle third:

```text
low = mid1 + 1;
high = mid2 - 1;
```

---

# Ternary Search Example

Consider:

```text
[2, 4, 6, 8, 10, 12, 14, 16, 18]
```

The range is divided into three sections:

```text
[2 4 6] | [8 10 12] | [14 16 18]
          ^     ^
        mid1   mid2
```

The target determines which third needs to be searched next.

---

# Why Binary Search Is Usually Faster

At first glance, Ternary Search may appear better because:

```text
Binary Search:
n → n/2 → n/4 → n/8 → ...

Ternary Search:
n → n/3 → n/9 → n/27 → ...
```

However, the number of comparisons performed during each iteration matters.

### Binary Search

Each iteration calculates one middle position and can require comparisons such as:

```text
arr[mid] == target
arr[mid] < target
```

### Ternary Search

Each iteration calculates two middle positions and checks:

```text
arr[mid1] == target
arr[mid2] == target
target < arr[mid1]
target > arr[mid2]
```

Therefore, Ternary Search does more work per iteration.

For a normal sorted array, Binary Search usually provides better practical performance despite Ternary Search having a smaller logarithmic base.

---

# Time Complexity

Let:

```text
n = number of elements
```

## Binary Search

The search space becomes:

```text
n
n/2
n/4
n/8
...
```

After `k` iterations:

```text
n / 2^k = 1
```

Therefore:

```text
2^k = n
```

Taking logarithm:

```text
k = log₂(n)
```

### Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `O(1)`          |
| Average Case | `O(log n)`      |
| Worst Case   | `O(log n)`      |

---

## Ternary Search

The search space becomes approximately:

```text
n
n/3
n/9
n/27
...
```

After `k` iterations:

```text
n / 3^k = 1
```

Therefore:

```text
3^k = n
```

Taking logarithm:

```text
k = log₃(n)
```

### Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `O(1)`          |
| Average Case | `O(log n)`      |
| Worst Case   | `O(log n)`      |

---

# Why `O(log₂ n)` and `O(log₃ n)` Are Both `O(log n)`

The base of a logarithm is a constant factor.

Using the change-of-base formula:

```text
log₃(n) = log₂(n) / log₂(3)
```

Since:

```text
1 / log₂(3)
```

is a constant, both are asymptotically:

```text
O(log n)
```

However, Big-O hides constant factors.

So:

```text
O(log₂ n)
```

does **not** mean Binary Search and Ternary Search perform exactly the same amount of work.

In practice, the number of comparisons per iteration matters.

---

# Space Complexity

Both implementations are **iterative**, meaning they do not use recursive function calls.

They only maintain a constant number of variables:

```text
low
high
mid
```

or:

```text
low
high
mid1
mid2
third
```

Therefore:

| Algorithm      | Auxiliary Space |
| -------------- | --------------- |
| Binary Search  | `O(1)`          |
| Ternary Search | `O(1)`          |

The input array itself requires `O(n)` memory, but that is **input space**, not auxiliary space used by the searching algorithm.

---

# Benchmark Functions

The program also contains:

```c
time_binary_search()
time_ternary_search()
```

These functions perform multiple searches and measure their execution time using:

```c
clock()
```

The measured time is converted to milliseconds:

```c
((double)(end - start) / CLOCKS_PER_SEC) * 1000.0
```

The functions also accumulate the total number of iterations performed across all searches.

---

## Important Note

The current `main()` function only performs the **single-search comparison**.

The benchmark functions are defined but are **not currently called from `main()`**.

Therefore, the current program does not print benchmark execution times.

To benchmark both algorithms, `main()` would need to call:

```c
time_binary_search(...)
time_ternary_search(...)
```

and print their results.

---

# Complexity Summary

| Operation                 | Binary Search |      Ternary Search |
| ------------------------- | ------------: | ------------------: |
| Search-space reduction    |       `n / 2` |             `n / 3` |
| Best Case                 |        `O(1)` |              `O(1)` |
| Average Case              |    `O(log n)` |          `O(log n)` |
| Worst Case                |    `O(log n)` |          `O(log n)` |
| Auxiliary Space           |        `O(1)` |              `O(1)` |
| Middle points calculated  |             1 |                   2 |
| Practical comparison cost |         Lower |              Higher |
| Typical choice            | **Preferred** | Usually unnecessary |

---

# Sample Output

For:

```text
Array Size = 1000
Target = 1532
```

the target is present at:

```text
Index = 766
```

The output has the following structure:

```text
--------------------------------------------------
    SINGLE SEARCH (Array Size: 1000, Target: 1532)
--------------------------------------------------
Binary Search  -> Index: 766 | Iterations: ...
Ternary Search -> Index: 766 | Iterations: ...
--------------------------------------------------
```

The exact number of iterations depends on the search path taken by each algorithm.

---

# Requirements

* C compiler
* Standard C library

The program uses:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
```

Compile using GCC:

```bash
gcc search.c -o search
```

Run:

```bash
./search
```

On Windows:

```bash
search.exe
```

---

# Key Concepts Demonstrated

This project demonstrates:

* Sorted-array searching
* Binary Search
* Ternary Search
* Iterative algorithms
* Divide-and-conquer
* Time complexity
* Space complexity
* Logarithmic growth
* Iteration counting
* Basic execution-time benchmarking
* `clock()` in C
* Pointer parameters for returning iteration counts

---

# Common Mistakes

### 1. Using Binary or Ternary Search on an unsorted array

Both algorithms depend on the ordering of the array.

```text
Sorted → Correct
Unsorted → Not guaranteed to work
```

### 2. Incorrect midpoint calculation

Prefer:

```c
int mid = low + (high - low) / 2;
```

instead of:

```c
int mid = (low + high) / 2;
```

The first form avoids potential integer overflow when `low` and `high` are very large.

### 3. Forgetting boundary updates

Binary Search must update:

```c
low = mid + 1;
```

or:

```c
high = mid - 1;
```

Otherwise, the loop can fail to make progress.

### 4. Confusing logarithm base with Big-O

`log₂(n)` and `log₃(n)` are different mathematical values, but both belong to:

```text
O(log n)
```

because logarithm bases differ only by a constant factor.

---

# Conclusion

Both Binary Search and Ternary Search have logarithmic worst-case complexity.

However, **dividing the search space into more pieces does not automatically make an algorithm faster**.

Binary Search generally performs fewer comparisons per iteration and is therefore the standard choice for searching a sorted array.

The main lesson is:

> **Algorithm performance depends not only on how quickly the input size decreases, but also on how much work is performed during each step.**

---

## Future Improvements

Possible extensions to this project:

* Add a complete execution-time benchmark to `main()`.
* Test arrays of different sizes such as `100`, `1,000`, `10,000`, and `1,000,000`.
* Generate random search targets.
* Compare successful and unsuccessful searches.
* Calculate average iterations.
* Calculate average execution time.
* Plot Binary Search vs Ternary Search performance.
* Add recursive implementations.
* Compare against Linear Search.

---

## Learning Outcome

After completing this project, you should be able to explain:

```text
Why Binary Search is O(log n)
Why Ternary Search is O(log n)
Why Binary Search is usually faster in practice
Why both algorithms require sorted data
Why iterative implementations use O(1) auxiliary space
Why more divisions do not necessarily mean better performance
```
