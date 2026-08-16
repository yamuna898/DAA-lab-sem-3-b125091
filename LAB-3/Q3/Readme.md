# Finding Minimum and Maximum Using Divide and Conquer

A C implementation that finds the **minimum and maximum elements** of an array using the **Divide and Conquer** technique.

The algorithm recursively divides the array into smaller parts, finds the minimum and maximum of each part, and then combines their results.

It also counts the number of element comparisons and verifies the result against the theoretical comparison bound of approximately **`3n/2`**.

---

## Problem Statement

Given an array of `n` elements, find:

* The **minimum** element
* The **maximum** element

A straightforward approach would scan the array and compare every element with both the current minimum and maximum.

That requires approximately:

```text
2(n - 1)
```

comparisons.

The Divide and Conquer approach reduces this number.

For an even-sized array, the optimal comparison count is:

```text
3n/2 - 2
```

which is below the commonly stated upper bound:

```text
3n/2
```

---

# Approach

The algorithm uses three main steps:

```text
Divide
   ↓
Solve smaller subarrays
   ↓
Combine their min/max results
```

For example:

```text
[8, 3, 10, 2, 6, 1, 9, 4]

             Divide
               ↓
      [8, 3, 10, 2] [6, 1, 9, 4]
             ↓              ↓
        Find min/max    Find min/max
             ↓              ↓
             └──────┬───────┘
                    ↓
              Combine results
                    ↓
             Min = 1
             Max = 10
```

---

# Data Structure

The program defines:

```c
typedef struct {
    int min;
    int max;
} MinMaxPair;
```

This structure allows the recursive function to return both values together.

For example:

```text
MinMaxPair
├── min
└── max
```

Instead of returning only one value, the function returns the complete result for the current subarray.

---

# Algorithm

The main function is:

```c
get_min_max_dc()
```

It receives:

```text
arr
low
high
comparisons
```

where `[low, high]` represents the current portion of the array.

---

## Case 1 — One Element

If:

```c
low == high
```

there is only one element.

That element is automatically both the minimum and maximum:

```text
min = arr[low]
max = arr[low]
```

No comparison is required.

### Comparisons

```text
0
```

---

# Case 2 — Two Elements

If:

```c
high == low + 1
```

there are exactly two elements.

Only one comparison is required:

```c
if (arr[low] < arr[high])
```

If the first element is smaller:

```text
min = arr[low]
max = arr[high]
```

Otherwise:

```text
min = arr[high]
max = arr[low]
```

### Comparisons

```text
1
```

This special case is important because it avoids unnecessary recursive calls.

---

# Case 3 — More Than Two Elements

The array is divided into two halves.

The midpoint is calculated using:

```c
int mid = low + (high - low) / 2;
```

The two recursive calls are:

```c
left_result =
    get_min_max_dc(arr, low, mid, comparisons);

right_result =
    get_min_max_dc(arr, mid + 1, high, comparisons);
```

The left and right halves independently return their minimum and maximum values.

---

# Combining the Results

After both halves are solved, their results must be combined.

Suppose:

```text
Left:
min = 2
max = 10

Right:
min = 1
max = 8
```

To find the overall minimum:

```c
if (left_result.min < right_result.min)
```

This requires:

```text
1 comparison
```

To find the overall maximum:

```c
if (left_result.max > right_result.max)
```

This requires another:

```text
1 comparison
```

Therefore, combining two non-trivial subarrays requires:

```text
2 comparisons
```

---

# Complete Algorithm Flow

```text
                 Array
                   |
                Divide
                   |
          ┌────────┴────────┐
          ↓                 ↓
      Left Half         Right Half
          |                 |
      Divide Again      Divide Again
          |                 |
       min + max          min + max
          |                 |
          └────────┬────────┘
                   ↓
              Compare mins
                   +
              Compare maxes
                   ↓
              Final min/max
```

---

# Example Walkthrough

Consider:

```text
[100, 11, 445, 1, 330, 3000, -5, 230]
```

The algorithm first divides it:

```text
[100, 11, 445, 1]    [330, 3000, -5, 230]
```

Then:

```text
[100, 11] [445, 1]    [330, 3000] [-5, 230]
```

Each pair requires one comparison.

For example:

```text
[100, 11]

100 > 11

min = 11
max = 100
```

and:

```text
[445, 1]

445 > 1

min = 1
max = 445
```

Then the results are combined:

```text
Left:
min = 1
max = 445

Right:
min = -5
max = 3000
```

Compare the minimums:

```text
1 vs -5
```

Therefore:

```text
min = -5
```

Compare the maximums:

```text
445 vs 3000
```

Therefore:

```text
max = 3000
```

Final result:

```text
Minimum = -5
Maximum = 3000
```

---

# Comparison Count

One of the important goals of this program is not just finding the answer, but counting how many comparisons are performed.

The counter is passed by pointer:

```c
int *comparisons
```

Whenever an actual element comparison happens:

```c
(*comparisons)++;
```

is executed.

This allows every recursive call to update the same comparison counter.

---

# Theoretical Comparison Bound

For this problem, the standard Divide and Conquer algorithm achieves approximately:

```text
3n/2
```

comparisons.

For an even `n`, the exact number is:

```text
3n/2 - 2
```

For example, when:

```text
n = 8
```

the exact comparison count is:

```text
3(8)/2 - 2
= 12 - 2
= 10
```

Therefore, the algorithm requires:

```text
10 comparisons
```

for an 8-element array.

The program checks the actual count against:

```c
int theoretical_bound = (3 * n) / 2;
```

---

# Why `3n/2`?

Consider an array with an even number of elements.

First, divide the array into `n/2` pairs.

For each pair:

```text
1 comparison
```

is needed to determine which element is smaller and which is larger.

Therefore:

```text
n/2 comparisons
```

are used.

After that, we have:

```text
n/2 minimum candidates
n/2 maximum candidates
```

Finding the minimum among the minimum candidates requires:

```text
n/2 - 1 comparisons
```

Finding the maximum among the maximum candidates requires:

```text
n/2 - 1 comparisons
```

Total:

```text
n/2 + (n/2 - 1) + (n/2 - 1)
```

which gives:

```text
3n/2 - 2
```

Therefore:

```text
3n/2 - 2 < 3n/2
```

So the algorithm satisfies the `3n/2` upper bound.

---

# Recurrence Relation

The Divide and Conquer algorithm can be represented using the recurrence:

```text
T(n) = 2T(n/2) + 2
```

Why?

Each recursive call solves approximately half of the array:

```text
2T(n/2)
```

Then the results are combined using two comparisons:

```text
+ 2
```

Therefore:

```text
T(n) = 2T(n/2) + 2
```

Using the Master Theorem:

```text
a = 2
b = 2
f(n) = O(1)
```

Since:

```text
n^(log₂2) = n
```

we get:

```text
T(n) = O(n)
```

So the algorithm has **linear time complexity**.

---

# Time Complexity

| Case         | Complexity |
| ------------ | ---------: |
| Best Case    |     `O(n)` |
| Average Case |     `O(n)` |
| Worst Case   |     `O(n)` |

Unlike searching algorithms, finding both the minimum and maximum requires examining the elements, so the algorithm cannot generally do better than:

```text
Ω(n)
```

Thus:

```text
Time Complexity = Θ(n)
```

---

# Space Complexity

The algorithm is recursive.

For an array of size `n`, the recursion depth is approximately:

```text
log₂(n)
```

Therefore, the recursion stack requires:

```text
O(log n)
```

additional space.

The `MinMaxPair` structures themselves are constant-sized.

Therefore:

```text
Auxiliary Space = O(log n)
```

---

# Complexity Summary

| Property                       |               Result |
| ------------------------------ | -------------------: |
| Time Complexity                |               `O(n)` |
| Auxiliary Space                |           `O(log n)` |
| Recursion Depth                |           `O(log n)` |
| Comparisons                    | Approximately `3n/2` |
| Exact comparisons for even `n` |           `3n/2 - 2` |
| Input requirement              |                 None |
| Technique                      |   Divide and Conquer |

---

# Comparison With Naive Approach

A simple approach might look conceptually like:

```text
min = arr[0]
max = arr[0]

for every remaining element:
    compare with min
    compare with max
```

Each element can require two comparisons.

Approximately:

```text
2(n - 1)
```

comparisons are performed.

The Divide and Conquer approach reduces this to approximately:

```text
3n/2
```

comparisons.

### Comparison

| Approach         | Approximate Comparisons |   Time |
| ---------------- | ----------------------: | -----: |
| Naive scan       |                    `2n` | `O(n)` |
| Divide & Conquer |                  `3n/2` | `O(n)` |

Both are `O(n)`, but the Divide and Conquer approach performs fewer comparisons.

---

# Program Test Cases

The program tests two arrays.

### Test Case 1

```c
int arr1[] = {
    100, 11, 445, 1,
    330, 3000, -5, 230
};
```

Expected:

```text
Minimum = -5
Maximum = 3000
```

### Test Case 2

```c
int arr2[] = {
    22, 14, -8, 89,
    53, 102, 3
};
```

Expected:

```text
Minimum = -8
Maximum = 102
```

The program also prints:

* Array size
* Array contents
* Minimum
* Maximum
* Actual comparison count
* Theoretical `3n/2` limit
* Whether the comparison bound was respected

---

# Sample Output

```text
Array (n = 8): 100 11 445 1 330 3000 -5 230
Minimum Element        : -5
Maximum Element        : 3000
Actual Comparisons     : 10
Theoretical 3n/2 Limit : 12
Bound Respected?       : YES (PASSED)
--------------------------------------------------

Array (n = 7): 22 14 -8 89 53 102 3
Minimum Element        : -8
Maximum Element        : 102
Actual Comparisons     : ...
Theoretical 3n/2 Limit : 10
Bound Respected?       : YES (PASSED)
--------------------------------------------------
```

The exact comparison count for an odd-sized array depends on how the recursive partitions terminate.

---

# Why Pass `comparisons` as a Pointer?

The function needs to update the same comparison counter across all recursive calls.

Therefore:

```c
int *comparisons
```

is passed to the function.

When the function executes:

```c
(*comparisons)++;
```

it modifies the original variable in `main()`.

Without a pointer, each recursive call would receive its own copy of the counter.

---

# Important Implementation Details

### Safe midpoint calculation

The program uses:

```c
int mid = low + (high - low) / 2;
```

instead of:

```c
int mid = (low + high) / 2;
```

This avoids potential integer overflow when `low` and `high` are very large.

---

### Base Cases

The recursive function has two important base cases:

```text
1 element → 0 comparisons
2 elements → 1 comparison
```

These prevent unnecessary recursion and make the comparison count more efficient.

---

# Common Mistakes

### 1. Forgetting the second comparison

After finding the minimum of the left and right halves, you still need another comparison for the maximum.

```text
Minimum → 1 comparison
Maximum → 1 comparison
```

Total:

```text
2 comparisons
```

during the combine step.

### 2. Counting assignments as comparisons

This:

```c
result.min = left_result.min;
```

is an assignment, not an element comparison.

Only operations such as:

```c
left_result.min < right_result.min
```

should be counted.

### 3. Confusing `O(n)` with `O(log n)`

The algorithm divides the array recursively, but it still processes all elements.

Therefore, its time complexity is:

```text
O(n)
```

not:

```text
O(log n)
```

The `log n` part describes the **recursion depth**, not the total amount of work.

---

# How to Compile

Using GCC:

```bash
gcc min_max.c -o min_max
```

Run:

```bash
./min_max
```

On Windows:

```bash
min_max.exe
```

---

# Concepts Demonstrated

This project demonstrates:

* Divide and Conquer
* Recursion
* Recurrence Relations
* Master Theorem
* Minimum and Maximum algorithms
* Comparison counting
* Structs in C
* Pointer parameters
* Recursion stack
* Time complexity
* Space complexity
* Lower/upper comparison bounds

---

# Key Takeaway

The important result of this algorithm is not simply:

```text
Find min and max → O(n)
```

The more interesting result is the **number of comparisons**.

A naive approach can require approximately:

```text
2n
```

comparisons.

The Divide and Conquer approach reduces this to approximately:

```text
3n/2
```

while remaining:

```text
O(n)
```

in time.

So this algorithm demonstrates an important distinction:

> **Two algorithms can have the same Big-O complexity while performing significantly different numbers of operations.**
