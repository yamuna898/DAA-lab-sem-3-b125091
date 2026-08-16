# Defective Coin Detection Using Binary Search

A C implementation for finding a **single defective lighter coin** among a collection of coins using a binary-search-based strategy.

Instead of weighing every coin individually, the algorithm compares the total weight of two equal-sized groups and eliminates the half that cannot contain the defective coin.

The program uses **prefix sums** to calculate the total weight of any range in `O(1)` time.

---

## Problem Statement

Suppose we have `n` coins where:

* Every normal coin has the same weight.
* Exactly **one coin may be defective**.
* The defective coin is **lighter** than the normal coins.
* We know the weights of the coins in the array.
* We want to find the index of the defective coin efficiently.

Example:

```text
Normal weight = 10

[10, 10, 10, 10, 10, 9, 10, 10, 10, ...]
                         ↑
                    defective
```

The goal is to find:

```text
Index = 5
Weight = 9
```

without linearly checking every coin.

---

# Main Idea

The algorithm repeatedly divides the current range into two equal-sized groups.

For example:

```text
[0 1 2 3] [4 5 6 7]
    Left      Right
```

If:

```text
Left Weight < Right Weight
```

the defective coin must be in the left half.

If:

```text
Right Weight < Left Weight
```

the defective coin must be in the right half.

If:

```text
Left Weight == Right Weight
```

then neither half contains the defective coin.

If there is one unpaired middle coin, that coin is checked separately.

Therefore, approximately half of the possible positions are eliminated at every step.

This gives the searching part of the algorithm a logarithmic complexity.

---

# Why Prefix Sums Are Used

To compare two groups, we need their total weights.

A naive approach would calculate each group's sum every time:

```text
Sum of left half
Sum of right half
```

This would require iterating over the elements in each range.

That would make every comparison potentially `O(n)`.

Instead, the program first constructs a **prefix-sum array**.

For:

```text
coins = [10, 10, 10, 9]
```

the prefix array becomes:

```text
pref = [0, 10, 20, 30, 39]
```

The meaning is:

```text
pref[i] = sum of coins from index 0 to i-1
```

So:

```text
pref[0] = 0
pref[1] = 10
pref[2] = 20
pref[3] = 30
pref[4] = 39
```

---

# Range Sum Formula

The function:

```c
long long get_range_weight(const long long pref[], int l, int r)
```

calculates:

```text
sum(l ... r) = pref[r + 1] - pref[l]
```

For example:

```text
coins = [10, 10, 10, 9]
```

To calculate:

```text
coins[1] + coins[2]
```

we use:

```text
pref[3] - pref[1]
= 30 - 10
= 20
```

Therefore, a range sum can be obtained in:

```text
O(1)
```

time.

---

# Algorithm

The main searching function is:

```c
binary_search_defective()
```

It receives:

```text
coins
prefix sum array
low
high
```

where `[low, high]` represents the current candidate range.

---

## Step 1 — Divide the Range

Suppose:

```text
low = 0
high = 19
```

There are:

```text
m = high - low + 1
  = 20
```

coins.

The size of each half is:

```text
k = m / 2
  = 10
```

So the range becomes:

```text
Left:  0 ... 9
Right: 10 ... 19
```

---

## Step 2 — Calculate Both Weights

The program calculates:

```c
long long left_weight =
    get_range_weight(pref, left_start, left_end);

long long right_weight =
    get_range_weight(pref, right_start, right_end);
```

Because prefix sums are already available, both calculations take:

```text
O(1)
```

time.

---

# Step 3 — Determine Which Half Contains the Defective Coin

### Case 1: Left Side Is Lighter

```text
left_weight < right_weight
```

The defective coin must be in the left half.

Therefore:

```c
low = left_start;
high = left_end;
```

The search space is reduced by approximately half.

---

### Case 2: Right Side Is Lighter

```text
right_weight < left_weight
```

The defective coin must be in the right half.

Therefore:

```c
low = right_start;
high = right_end;
```

Again, approximately half the candidates are eliminated.

---

### Case 3: Both Sides Have Equal Weight

```text
left_weight == right_weight
```

If the number of coins is even, there is no middle coin:

```text
[Left half] [Right half]
```

If both halves weigh the same, the defective coin cannot be inside either half under the problem's assumption.

Therefore:

```text
No defective coin found
```

---

# Odd Number of Coins

Consider:

```text
[0 1 2] [3 4 5] [6]
  Left     Right    Middle
```

The two halves contain the same number of coins, while one coin remains unpaired.

If:

```text
left_weight == right_weight
```

the algorithm checks the middle coin.

```c
int mid = low + k;
```

It compares the middle coin's weight against a standard/reference coin.

If:

```text
coins[mid] < standard_coin_weight
```

then:

```text
mid
```

is the defective coin.

---

# Example Walkthrough

The program uses:

```c
int coins[] = {
    10, 10, 10, 10, 10,
     9,
    10, 10, 10, 10, 10,
    10, 10, 10, 10, 10,
    10, 10, 10, 10
};
```

There are `20` coins.

The defective coin is:

```text
index = 5
weight = 9
```

### First iteration

```text
Range: 0 ... 19
```

Divide into:

```text
Left:  0 ... 9
Right: 10 ... 19
```

Weights:

```text
Left  = 99
Right = 100
```

Therefore:

```text
Left < Right
```

The defective coin must be somewhere in:

```text
0 ... 9
```

---

### Second iteration

Current range:

```text
0 ... 9
```

Divide into:

```text
Left:  0 ... 4
Right: 5 ... 9
```

Weights:

```text
Left  = 50
Right = 49
```

Therefore:

```text
Right < Left
```

The defective coin must be somewhere in:

```text
5 ... 9
```

---

### Next iteration

The algorithm continues dividing the candidate range until only a small number of candidates remain.

Eventually:

```text
index = 5
```

is identified as the defective coin.

---

# Complexity Analysis

Let:

```text
n = number of coins
```

## Prefix Sum Construction

The prefix array is constructed using one loop:

```c
for (int i = 0; i < n; i++)
```

Therefore:

```text
Time = O(n)
```

---

## Range Weight Calculation

The range sum uses:

```c
pref[r + 1] - pref[l]
```

There is no loop.

Therefore:

```text
Time = O(1)
```

---

## Binary Search

At every iteration, the candidate range is reduced approximately by half:

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
k = log₂(n)
```

So:

```text
Binary Search = O(log n)
```

Because each iteration performs only `O(1)` work using prefix sums.

---

# Overall Time Complexity

The program has two major stages:

| Operation               |    Time Complexity |
| ----------------------- | -----------------: |
| Build prefix sum        |             `O(n)` |
| Each range-weight query |             `O(1)` |
| Defective coin search   |         `O(log n)` |
| **Total**               | **`O(n + log n)`** |

Since:

```text
n + log n = O(n)
```

the overall complexity is:

```text
O(n)
```

However, this should be understood correctly:

> The **search itself** is `O(log n)`, but constructing the prefix-sum array costs `O(n)`.

If the prefix sum is already available, finding the defective coin takes:

```text
O(log n)
```

---

# Space Complexity

The prefix sum array contains:

```text
n + 1
```

elements.

Therefore:

```text
Auxiliary Space = O(n)
```

The binary search itself uses only a constant number of variables:

```text
low
high
m
k
mid
```

so the search procedure itself uses:

```text
O(1)
```

auxiliary space.

Overall:

```text
Space Complexity = O(n)
```

because of the prefix-sum array.

---

# Complexity Summary

| Component               |       Time |      Space |
| ----------------------- | ---------: | ---------: |
| Prefix Sum Construction |     `O(n)` |     `O(n)` |
| Range Weight Query      |     `O(1)` |     `O(1)` |
| Defective Coin Search   | `O(log n)` |     `O(1)` |
| **Overall Program**     | **`O(n)`** | **`O(n)`** |

---

# Why Prefix Sum Makes the Algorithm Efficient

Without prefix sums:

```text
Calculate left weight  → O(n)
Calculate right weight → O(n)
```

This could make every binary-search iteration expensive.

With prefix sums:

```text
Left weight  → O(1)
Right weight → O(1)
```

Therefore:

```text
O(1) work per search iteration
×
O(log n) iterations
=
O(log n)
```

This is the key optimization used in the implementation.

---

# Important Assumptions

This implementation relies on several assumptions.

### 1. At most one defective coin

The algorithm assumes that there is not more than one defective coin.

### 2. The defective coin is lighter

The comparison:

```c
left_weight < right_weight
```

assumes the abnormal coin decreases the total weight.

A heavier defective coin would require different logic.

### 3. Normal coins have identical weights

The algorithm assumes all normal coins weigh the same.

For example:

```text
10, 10, 10, 10, 10
```

A normal coin should not randomly have a weight of `9` or `11`.

### 4. The array contains actual weights

Unlike the classic coin-weighing puzzle, this implementation already has the numerical weights of the coins available.

Therefore, the "weighing" operation is simulated using array values and prefix sums.

---

# Potential Edge Case

The final part of the search contains:

```c
int reference_idx = (low == 0) ? 1 : 0;
```

This assumes that there is another coin available for comparison.

Therefore, an input containing only one coin:

```text
n = 1
```

would require additional handling because index `1` would be outside the array.

A robust implementation should explicitly handle:

```text
n < 2
```

before performing the search.

---

# Program Output

For the provided input, the expected result is:

```text
==========================================
Defective lighter coin found at index: 5 (weight = 9)
==========================================
```

---

# Concepts Demonstrated

This project combines several important algorithmic concepts:

* Binary Search
* Divide-and-conquer
* Prefix Sum
* Range Sum Queries
* Time Complexity
* Space Complexity
* Iterative algorithms
* Dynamic memory allocation
* Pointer-based arrays
* `malloc()`
* `free()`

---

# Key Takeaway

The important optimization is not simply "use binary search."

The complete idea is:

```text
Prefix Sum
    ↓
O(1) range-weight calculation
    ↓
Binary Search
    ↓
Discard approximately half the candidates
    ↓
O(log n) search
```

Without prefix sums, calculating the weight of each half could dominate the running time.

With prefix sums, each comparison is constant time, allowing the **defective-coin search itself to run in `O(log n)` time**.

---

# Possible Improvements

* Handle `n < 2` safely.
* Validate that exactly zero or one defective coin exists.
* Support both lighter and heavier defective coins.
* Generate random coin arrays for testing.
* Compare this approach with a linear-search solution.
* Benchmark performance for large values of `n`.
* Add a version that simulates physical balance-scale weighings rather than using direct coin weights.
