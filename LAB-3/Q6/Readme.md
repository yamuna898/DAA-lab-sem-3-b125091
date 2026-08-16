# Selection Sort — Comparison and Swap Analysis

A C implementation of **Selection Sort** that sorts an array in ascending order while explicitly counting:

* The number of **element comparisons**
* The number of **swaps**

The program also tests three different input arrangements:

1. Unsorted array
2. Already sorted array
3. Reverse sorted array

This demonstrates an important property of Selection Sort: **its number of comparisons is fixed regardless of the initial ordering of the array**, while the number of swaps can vary significantly.

---

# Overview

Selection Sort divides the array into two conceptual parts:

```text
Sorted portion | Unsorted portion
       ↑                ↑
    finished         remaining
```

At every iteration:

1. Find the smallest element in the unsorted portion.
2. Swap it with the first element of the unsorted portion.
3. Expand the sorted portion by one position.

Example:

```text
[64, 25, 12, 22, 11, 90]
 ↑
Find minimum in entire array → 11

[11, 25, 12, 22, 64, 90]
     ↑
Find minimum in remaining array → 12

[11, 12, 25, 22, 64, 90]
         ↑
Find minimum → 22

[11, 12, 22, 25, 64, 90]
```

---

# Algorithm

For an array of size `n`:

```text
for i = 0 to n-2:

    assume A[i] is minimum

    for j = i+1 to n-1:
        compare A[j] with current minimum

        if A[j] is smaller:
            update minimum index

    swap A[i] with minimum element
```

The implementation follows exactly this procedure.

---

# Step-by-Step Example

Consider:

```text
[64, 25, 12, 22, 11, 90]
```

## Pass 1

Search the entire array:

```text
64  25  12  22  11  90
                  ↑
                minimum
```

Minimum:

```text
11
```

Swap `64` and `11`:

```text
[11, 25, 12, 22, 64, 90]
```

Now index `0` is sorted.

---

## Pass 2

Search:

```text
[25, 12, 22, 64, 90]
```

Minimum:

```text
12
```

Swap:

```text
[11, 12, 25, 22, 64, 90]
```

---

## Pass 3

Search:

```text
[25, 22, 64, 90]
```

Minimum:

```text
22
```

Result:

```text
[11, 12, 22, 25, 64, 90]
```

---

## Pass 4

Minimum in:

```text
[25, 64, 90]
```

is already `25`.

No swap is required.

---

## Pass 5

Minimum in:

```text
[64, 90]
```

is already `64`.

No swap is required.

Final:

```text
[11, 12, 22, 25, 64, 90]
```

---

# Why Is It Called Selection Sort?

At every pass, the algorithm **selects** one element:

```text
smallest remaining element
```

and places it in its final position.

Hence:

```text
Selection Sort
      ↓
Select minimum
      ↓
Place it
      ↓
Repeat
```

---

# Comparison Count

The program counts every execution of:

```c
(*comparisons)++;
```

inside the inner loop.

For an array of size `n`:

### First pass

Compare:

```text
n - 1
```

elements.

### Second pass

Compare:

```text
n - 2
```

elements.

### Third pass

Compare:

```text
n - 3
```

elements.

Eventually:

```text
2 + 1
```

comparisons are performed.

Therefore, total comparisons are:

```text
(n - 1) + (n - 2) + ... + 2 + 1
```

This is an arithmetic series.

Its sum is:

```text
n(n - 1) / 2
```

Therefore:

```text
Comparisons = n(n - 1)/2
```

---

# Example: `n = 6`

The program uses:

```text
n = 6
```

Therefore:

```text
6(6 - 1) / 2
= 6 × 5 / 2
= 15
```

So every test case performs exactly:

```text
15 comparisons
```

regardless of whether the array is sorted, unsorted, or reverse sorted.

---

# Why Comparisons Do Not Change

This is an important property of Selection Sort.

Even if the array is already sorted:

```text
[11, 12, 22, 25, 64, 90]
```

the algorithm still has to search the remaining portion to prove that there is no smaller element.

It cannot simply assume that the remaining elements are already in the correct order.

Therefore:

```text
Best Case Comparisons = n(n-1)/2
Average Case Comparisons = n(n-1)/2
Worst Case Comparisons = n(n-1)/2
```

All three are:

```text
Θ(n²)
```

---

# Swap Count

Unlike comparisons, the number of swaps is **not fixed**.

A swap happens only when:

```c
if (min_idx != i)
```

is true.

Therefore, if the minimum element is already in the correct position, no swap occurs.

---

# Best Case

Consider an already sorted array:

```text
[11, 12, 22, 25, 64, 90]
```

At every pass:

```text
min_idx == i
```

Therefore:

```text
Swaps = 0
```

So the best case has:

```text
Comparisons = n(n-1)/2
Swaps = 0
```

---

# Worst Case for Swaps

A reverse-sorted array generally causes many elements to be moved.

For:

```text
[90, 64, 25, 22, 12, 11]
```

Selection Sort performs swaps as it places the smallest remaining element into position.

However, an important detail is:

> Selection Sort performs at most `n - 1` swaps.

It does **not** perform `O(n²)` swaps.

Even in the worst case:

```text
Swaps ≤ n - 1
```

---

# Complexity Analysis

Let:

```text
n = number of elements
```

## Time Complexity

The nested loops perform:

```text
(n - 1) + (n - 2) + ... + 1
```

comparisons.

Therefore:

```text
T(n) = n(n - 1)/2
```

which simplifies asymptotically to:

```text
O(n²)
```

### All Cases

| Case    | Comparisons | Time Complexity |
| ------- | ----------: | --------------: |
| Best    |  `n(n-1)/2` |         `O(n²)` |
| Average |  `n(n-1)/2` |         `O(n²)` |
| Worst   |  `n(n-1)/2` |         `O(n²)` |

Unlike Bubble Sort or Insertion Sort, the standard Selection Sort implementation does not become `O(n)` on an already sorted array.

---

# Space Complexity

The algorithm sorts the array **in place**.

It only uses a few variables:

```text
i
j
min_idx
temp
```

Therefore:

```text
Auxiliary Space = O(1)
```

No additional array proportional to `n` is required.

---

# Complexity Summary

| Property        |                 Selection Sort |
| --------------- | -----------------------------: |
| Best Time       |                        `O(n²)` |
| Average Time    |                        `O(n²)` |
| Worst Time      |                        `O(n²)` |
| Comparisons     |                     `n(n-1)/2` |
| Best Swaps      |                            `0` |
| Maximum Swaps   |                          `n-1` |
| Auxiliary Space |                         `O(1)` |
| In-place        |                            Yes |
| Stable          | No, in standard implementation |

---

# Test Cases

The program contains three test cases.

## Test Case 1 — Unsorted

```c
int arr1[] = {64, 25, 12, 22, 11, 90};
```

Expected:

```text
Sorted:
[11 12 22 25 64 90]

Comparisons:
15
```

---

## Test Case 2 — Already Sorted

```c
int arr2[] = {11, 12, 22, 25, 64, 90};
```

Expected:

```text
Sorted:
[11 12 22 25 64 90]

Comparisons:
15

Swaps:
0
```

This demonstrates that Selection Sort still performs all comparisons even when the input is already sorted.

---

## Test Case 3 — Reverse Sorted

```c
int arr3[] = {90, 64, 25, 22, 12, 11};
```

Expected:

```text
Sorted:
[11 12 22 25 64 90]

Comparisons:
15
```

The number of swaps is higher than the already-sorted case.

---

# Sample Output

```text
=== Test Case 1: Unsorted Array ===
Original Array : [ 64 25 12 22 11 90 ]
Sorted Array   : [ 11 12 22 25 64 90 ]
Comparisons    : 15 (Expected: 15)
Swaps          : 4

=== Test Case 2: Already Sorted Array (Best Case) ===
Original Array : [ 11 12 22 25 64 90 ]
Sorted Array   : [ 11 12 22 25 64 90 ]
Comparisons    : 15 (Expected: 15)
Swaps          : 0

=== Test Case 3: Reverse Sorted Array (Worst Case) ===
Original Array : [ 90 64 25 22 12 11 ]
Sorted Array   : [ 11 12 22 25 64 90 ]
Comparisons    : 15 (Expected: 15)
Swaps          : 3
```

---

# Selection Sort vs Other Sorting Algorithms

| Algorithm      |         Best |      Average |        Worst |        Extra Space |
| -------------- | -----------: | -----------: | -----------: | -----------------: |
| Selection Sort |      `O(n²)` |      `O(n²)` |      `O(n²)` |             `O(1)` |
| Bubble Sort*   |       `O(n)` |      `O(n²)` |      `O(n²)` |             `O(1)` |
| Insertion Sort |       `O(n)` |      `O(n²)` |      `O(n²)` |             `O(1)` |
| Merge Sort     | `O(n log n)` | `O(n log n)` | `O(n log n)` |             `O(n)` |
| Quick Sort     | `O(n log n)` | `O(n log n)` |      `O(n²)` | `O(log n)` average |

*For an optimized Bubble Sort implementation that detects whether the array is already sorted.

---

# Why Use Selection Sort?

Selection Sort is usually not the best choice for large datasets because of its `O(n²)` running time.

However, it has an important advantage:

```text
Very few swaps
```

It performs at most:

```text
n - 1
```

swaps.

This can be useful when **writing/swapping elements is expensive** but comparisons are relatively cheap.

---

# Common Mistakes

### 1. Assuming sorted input makes Selection Sort `O(n)`

It does not.

The algorithm still searches the remaining array on every pass.

```text
Best = O(n²)
Average = O(n²)
Worst = O(n²)
```

---

### 2. Saying Selection Sort performs `O(n²)` swaps

Incorrect.

It performs:

```text
O(n²) comparisons
```

but at most:

```text
O(n)
```

swaps.

---

### 3. Swapping every iteration

This implementation correctly checks:

```c
if (min_idx != i)
```

before swapping.

Without this condition, unnecessary swaps would occur.

---

### 4. Confusing `min_idx` with the minimum value

The variable:

```c
min_idx
```

stores the **index** of the smallest element, not the element itself.

For example:

```text
A = [50, 20, 30]

min_idx = 1
A[min_idx] = 20
```

---

# How to Compile

Using GCC:

```bash
gcc selection_sort.c -o selection_sort
```

Run:

```bash
./selection_sort
```

On Windows:

```bash
selection_sort.exe
```

---

# Concepts Demonstrated

This project demonstrates:

* Selection Sort
* Nested loops
* In-place sorting
* Comparison counting
* Swap counting
* Best/Average/Worst-case analysis
* Arithmetic series
* Time complexity
* Space complexity
* Arrays in C
* Pointer parameters
* Passing statistics by reference

---

# Key Takeaway

Selection Sort has a simple but important complexity profile:

```text
Comparisons → Θ(n²)
Swaps       → O(n)
Space       → O(1)
```

The most important observation is:

> **Selection Sort always performs essentially the same number of comparisons, regardless of how sorted the input already is. Its advantage is that it performs very few swaps.**

For `n = 6`:

```text
Comparisons = 6 × 5 / 2 = 15
```

and this remains `15` for the unsorted, sorted, and reverse-sorted test cases.
