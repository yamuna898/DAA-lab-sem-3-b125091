# 🎯 DAA Lab 01

______________________________________
# Q5: Finding the Partition Point
______________________________________

---

# 📌 Overview

This repository contains the C programming implementation for **Question 5** of the **Design and Analysis of Algorithms (DAA) Laboratory – Assignment 01**.

The objective of this experiment is to determine the **partition point** in a sorted binary array containing only `0`s and `1`s. The partition point represents the index where the sequence of `0`s ends and the sequence of `1`s begins.

For example:

```
0 0 0 0 0 1 1 1 1
```

In the above array, the partition point is the index of the first occurrence of `1`.

Since the input array is already sorted, this problem can be solved much more efficiently than scanning every element sequentially. The program demonstrates this by implementing an **Optimized Binary Search** approach, which significantly reduces the number of operations required compared to a traditional Linear Search.

The experiment highlights how utilizing the properties of sorted data can greatly improve algorithm efficiency.

---

# 🎯 Objective

The objectives of this experiment are:

- To identify the partition point in a sorted binary array.
- To understand the advantage of Binary Search on sorted data.
- To compare the efficiency of Binary Search with Linear Search.
- To analyze the reduction in the number of operations achieved through algorithmic optimization.
- To study the practical application of logarithmic-time algorithms.

---

# 📝 Problem Statement

Given a sorted array consisting only of `0`s followed by `1`s, determine the position where the transition from `0` to `1` occurs.

Example:

```
Input:
0 0 0 0 0 0 1 1 1 1

Output:
Partition Point = Index of first 1
```

The solution should efficiently locate the transition point while minimizing the number of comparisons performed.

---

# 💡 Methodology

The program takes advantage of the fact that the input array is already sorted.

Instead of examining every element one by one, it repeatedly divides the search space into two halves using the Binary Search technique.

During every iteration, only one half of the array is considered while the other half is discarded. This process continues until the first occurrence of `1` is located.

The total number of operations performed during the search is also counted to demonstrate the efficiency of the algorithm.

---

# ⚙️ Algorithmic Logic

The array contains only two possible values:

- `0`
- `1`

Since all `0`s always appear before all `1`s, the transition point can be found without scanning the entire array.

The algorithm works as follows:

### Step 1

Select the middle element of the current search range.

---

### Step 2

If the middle element is `0`, then every element to its left must also be `0`.

Therefore, the partition point must lie in the **right half** of the array.

The left half is discarded.

---

### Step 3

If the middle element is `1`, check the previous element.

- If the previous element is `0`, the current position is the partition point.
- If the previous element is also `1`, the partition point lies somewhere in the **left half** of the array.

The right half is discarded.

---

### Step 4

Repeat the above process until the first occurrence of `1` is found.

By repeatedly halving the search space, the algorithm quickly converges to the correct answer.

---

# 📖 Why Binary Search?

A Linear Search examines elements one after another until the first `1` is encountered.

In the worst case, this requires checking every element in the array.

Binary Search, however, eliminates half of the remaining search space during each iteration.

This dramatically reduces the number of operations, especially for large arrays.

For an array containing **n** elements:

- Linear Search requires up to **n** comparisons.
- Binary Search requires only **log₂(n)** comparisons.

This makes Binary Search significantly more efficient for sorted datasets.

---

# 📊 Experimental Output

The program was executed using an array of size **16**, and the following results were obtained.

| Search Algorithm | Time Complexity | Partition Point (Index) | Total Operations |
| :--- | :--- | :--- | :--- |
| **Optimized Binary Search** | `O(log n)` | **11** | **3** |

---

# 📈 Time Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Linear Search | O(1) | O(n) | O(n) |
| Binary Search | O(1) | O(log n) | O(log n) |

---

# 📖 Observations

### Linear Search

- Checks each element sequentially.
- Does not utilize the sorted property of the array.
- The number of comparisons increases directly with array size.

---

### Binary Search

- Takes advantage of the sorted nature of the input.
- Eliminates half of the remaining search space during every iteration.
- Requires significantly fewer operations than Linear Search.

---

### Experimental Result

For an array of **16 elements**, the Binary Search algorithm successfully identified the partition point in only **3 operations**, illustrating the efficiency of logarithmic-time searching.

---

# 🔍 Key Findings

- Binary Search is highly efficient for sorted arrays.
- The number of operations grows very slowly as the array size increases.
- Linear Search becomes increasingly inefficient for large datasets.
- Exploiting the sorted property of data can greatly improve algorithm performance.
- The partition point can be located without examining every element.

---

# ▶ How to Compile

Using GCC:

```bash
gcc partition_point.c -o partition
```

Run the program:

```bash
./partition
```

For Windows (MinGW):

```bash
gcc partition_point.c -o partition.exe
partition.exe
```

---

# ✔ Verification

The correctness of the implementation can be verified as follows:

- Ensure that the reported index corresponds to the **first occurrence of `1`**.
- Verify that every element before the reported index is `0`.
- Verify that every element from the reported index onward is `1`.
- Confirm that the number of operations is considerably smaller than the array size, demonstrating the efficiency of Binary Search.

---

# ✅ Conclusion

This experiment demonstrates how Binary Search can efficiently solve the Partition Point problem by utilizing the sorted nature of the input array.

Unlike Linear Search, which may examine every element, Binary Search repeatedly reduces the search space by half, allowing the transition point to be located in logarithmic time. The experimental results clearly show that the algorithm identifies the partition point using only a small number of operations, making it a highly efficient solution for large sorted datasets.

