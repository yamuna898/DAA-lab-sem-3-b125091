# 🎯 DAA Lab 01

________________________________________
# Q6: Element Uniqueness Analysis
________________________________________

---

# 📌 Overview

This repository contains the C programming implementation for **Question 6** of the **Design and Analysis of Algorithms (DAA) Laboratory – Assignment 01**.

The objective of this experiment is to determine whether all elements in an array are **unique** or if one or more **duplicate values** are present.

The problem of element uniqueness is frequently encountered in computer science applications such as database validation, data preprocessing, searching, and duplicate detection. Efficiently identifying repeated elements becomes increasingly important as the size of the dataset grows.

To study different algorithmic approaches, this program implements both a **Brute Force** method and an **Optimized Frequency (Hash) Array** method. The number of operations performed by each approach is compared to demonstrate how choosing an appropriate algorithm can significantly improve performance.

---

# 🎯 Objective

The objectives of this experiment are:

- To determine whether an array contains duplicate elements.
- To compare two different approaches for solving the same problem.
- To analyze the effect of time and space complexity on algorithm performance.
- To understand the concept of the **Space-Time Tradeoff**.
- To compare the number of operations performed by each algorithm.

---

# 📝 Problem Statement

Given an array of integers, determine whether every element is unique.

If a duplicate value exists, the algorithm should identify that the array is **not unique**.

Example:

```
Input:

12 45 7 89 23 56 34 91 18 7

Output:

Duplicate Element Found
```

---

# 💡 Methodology

The experiment evaluates two different algorithms for solving the Element Uniqueness problem.

Both algorithms receive the same input array so that their performance can be compared fairly.

Instead of measuring execution time, the program records the number of operations (steps) performed by each algorithm, providing a hardware-independent measure of efficiency.

---

# ⚙️ Algorithmic Logic

## 1. Brute Force Approach

The Brute Force algorithm uses two nested loops.

Each element of the array is compared with every element that appears after it.

If two equal values are found, the algorithm immediately reports that the array contains duplicates.

Characteristics:

- Simple implementation.
- Requires no additional memory.
- Performs a large number of comparisons for bigger arrays.

Time Complexity:

```
O(n²)
```

Space Complexity:

```
O(1)
```

---

## 2. Optimized Frequency (Hash) Array Approach

The optimized approach uses an auxiliary **Frequency (Hash) Array** to keep track of previously encountered values.

The algorithm scans the input array only once.

For every element:

- If it has not been seen before, it is marked in the frequency array.
- If it has already been marked, a duplicate has been found immediately.

This approach demonstrates the **Space-Time Tradeoff**, where a small amount of additional memory is used to greatly reduce execution time.

Time Complexity:

```
O(n)
```

Space Complexity:

```
O(k)
```

where **k** represents the range of possible input values.

---

# 📖 Space-Time Tradeoff

The optimized algorithm illustrates an important concept in algorithm design known as the **Space-Time Tradeoff**.

Instead of repeatedly comparing elements, extra memory is allocated to store information about previously encountered values.

Although additional space is required, the overall running time is significantly reduced.

This technique is widely used in practical applications involving searching, duplicate detection, and hashing.

---

# 📊 Experimental Output

The program was executed using the following input array:

```
[12, 45, 7, 89, 23, 56, 34, 91, 18, 7]
```

The following results were obtained:

| Algorithm | Time Complexity | Space Complexity | Total Operations |
| :--- | :--- | :--- | :--- |
| **Frequency / Hash Array** | `O(n)` | `O(k)` | **10** |

---

# 📈 Time Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity |
|-----------|-----------|--------------|------------|------------------|
| Brute Force | O(n) | O(n²) | O(n²) | O(1) |
| Frequency / Hash Array | O(1) | O(n) | O(n) | O(k) |

---

# 📖 Observations

### Brute Force Approach

- Compares every element with the remaining elements.
- Requires no additional memory.
- Performance decreases rapidly as the array size increases.

---

### Frequency (Hash) Array Approach

- Visits each element only once.
- Detects duplicate values immediately after they appear.
- Performs significantly fewer operations than the Brute Force method.
- Requires additional memory to store frequency information.

---

### Experimental Result

For the given array containing **10 elements**, the optimized Frequency Array algorithm successfully detected the duplicate value while performing only **10 operations**, demonstrating the efficiency of linear-time searching.

---

# 🔍 Key Findings

- The Brute Force algorithm is simple but inefficient for large datasets.
- The Frequency Array algorithm reduces the running time from quadratic to linear.
- Extra memory can greatly improve execution speed.
- The experiment demonstrates the practical importance of the Space-Time Tradeoff.
- Linear-time algorithms are generally preferred for duplicate detection when additional memory is available.

---

# ▶ How to Compile

Using GCC:

```bash
gcc uniqueness.c -o uniqueness
```

Run the program:

```bash
./uniqueness
```

For Windows (MinGW):

```bash
gcc uniqueness.c -o uniqueness.exe
uniqueness.exe
```

---

# ✔ Verification

The correctness of the implementation can be verified using the following observations:

- If every element is distinct, the program should report that the array contains only unique elements.
- If any element appears more than once, the program should detect a duplicate.
- The optimized algorithm should examine each element only once.
- The number of recorded operations should approximately equal the number of elements processed.

---

# ✅ Conclusion

This experiment successfully compares two different approaches for solving the Element Uniqueness problem.

The Brute Force method requires no additional memory but performs a large number of comparisons, making it inefficient for large datasets. In contrast, the Frequency (Hash) Array approach uses extra memory to achieve linear-time performance, allowing duplicate elements to be detected much more efficiently.

The experiment clearly demonstrates that selecting an appropriate algorithm and utilizing additional memory when appropriate can significantly improve overall performance.
