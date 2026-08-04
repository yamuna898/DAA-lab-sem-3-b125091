# 📈 DAA Lab 01
_________________________________________
Q3 Bubble Sort Performance Comparison
_________________________________________

---

# 📌 Overview

This repository contains the C programming implementation for **Question 3** of the **Design and Analysis of Algorithms (DAA) Laboratory – Assignment 01**.

The objective of this experiment is to compare the performance of two versions of the Bubble Sort algorithm:

- **Standard (Unoptimized) Bubble Sort**
- **Optimized Bubble Sort with Early Stopping**

Rather than measuring execution time, the program compares the **number of element comparisons** performed by each algorithm under different input conditions. Since execution time depends on hardware and system performance, comparison count provides a more reliable way to evaluate algorithm efficiency.

The program analyzes Bubble Sort using three common test cases:

- Best Case (Already Sorted Array)
- Worst Case (Reverse Sorted Array)
- Average Case (Random Array)

The results are displayed in a well-formatted table directly in the console.

---

# 🎯 Objective

The primary objectives of this experiment are:

- To implement the Standard Bubble Sort algorithm.
- To implement an Optimized Bubble Sort using Early Stopping.
- To compare the number of comparisons performed by both algorithms.
- To analyze Bubble Sort under different input conditions.
- To understand how simple optimizations can improve algorithm performance.

---

# 📝 Problem Statement

Develop a C program that implements two versions of Bubble Sort:

1. Standard Bubble Sort
2. Optimized Bubble Sort with Early Stopping

The program should test both algorithms using three different input cases:

- Best Case
- Worst Case
- Average Case

For each case, the total number of element comparisons performed during sorting is recorded and displayed.

---

# 💡 Methodology

The program is implemented using the **C programming language**.

A fixed-size array containing **50 elements** is used for all experiments.

The same input array is copied before sorting so that both Bubble Sort implementations receive identical input data, ensuring a fair comparison.

Instead of measuring execution time, the program counts the total number of comparisons performed during sorting.

The comparison results are displayed in a formatted table.

---

# ⚙️ Algorithmic Logic

## 1. Standard Bubble Sort

The Standard Bubble Sort repeatedly compares adjacent elements and swaps them whenever they are in the wrong order.

The algorithm continues executing all passes even if the array becomes sorted before completion.

Characteristics:

- Performs every pass.
- Does not detect a sorted array.
- Best Case Complexity: **O(n²)**
- Average Case Complexity: **O(n²)**
- Worst Case Complexity: **O(n²)**

---

## 2. Optimized Bubble Sort

The Optimized Bubble Sort introduces a Boolean variable named **swapped**.

During each pass:

- If at least one swap occurs, sorting continues.
- If no swaps occur, the array is already sorted.
- The algorithm immediately terminates.

This simple optimization avoids unnecessary comparisons on sorted or nearly sorted arrays.

Characteristics:

- Best Case Complexity: **O(n)**
- Average Case Complexity: **O(n²)**
- Worst Case Complexity: **O(n²)**

---

# 📊 Test Cases

The program evaluates Bubble Sort using three different input conditions.

## Best Case

The array is already sorted in ascending order.

Example:

```
1 2 3 4 5 ...
```

This is the ideal input for the optimized algorithm.

---

## Worst Case

The array is sorted in reverse order.

Example:

```
50 49 48 47 ...
```

Every comparison results in a swap, producing the maximum amount of work.

---

## Average Case

The array contains randomly generated integers.

This represents a typical real-world input.

Since the values are generated using random numbers, the comparison count may differ slightly each time the program is executed.

---

# 📖 Observations

### Best Case

The optimized Bubble Sort completes after the first pass because no swaps occur.

The Standard Bubble Sort continues executing all remaining passes, performing many unnecessary comparisons.

This demonstrates the effectiveness of the Early Stopping optimization.

---

### Worst Case

Both algorithms perform the same number of comparisons.

Since every pass contains swaps, the optimized algorithm cannot terminate early.

Therefore, both implementations exhibit identical worst-case performance.

---

### Average Case

For randomly generated arrays, the optimized version may perform slightly fewer comparisons depending on when the array becomes sorted.

However, the improvement is generally much smaller than in the Best Case.

---

# 📊 Experimental Output

The program produces output similar to the following:

| Test Case | Standard Bubble Sort | Optimized Bubble Sort |
|-----------|---------------------:|----------------------:|
| Best (Sorted) | Comparisons | Comparisons |
| Worst (Reverse) | Comparisons | Comparisons |
| Average (Random) | Comparisons | Comparisons |

> **Note:** The comparison count for the Average Case changes with each execution because the array elements are randomly generated.

---

# 📈 Time Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Standard Bubble Sort | O(n²) | O(n²) | O(n²) |
| Optimized Bubble Sort | O(n) | O(n²) | O(n²) |

---

# 🔍 Key Findings

- Both implementations have the same worst-case time complexity.
- The optimized version significantly improves the best-case performance.
- Early Stopping prevents unnecessary passes when the array is already sorted.
- Reverse sorted arrays provide no benefit from the optimization.
- Random arrays may show a small improvement depending on the data distribution.
- Counting comparisons provides a consistent way to evaluate algorithm performance.

---

# ▶ How to Compile

Using GCC:

```bash
gcc bubble_sort.c -o bubble
```

Run the program:

```bash
./bubble
```

For Windows (MinGW):

```bash
gcc bubble_sort.c -o bubble.exe
bubble.exe
```

---

# ✔ Verification

The implementation can be verified using the following observations.

### Best Case

The Optimized Bubble Sort should perform **far fewer comparisons** than the Standard Bubble Sort.

---

### Worst Case

Both algorithms should produce **exactly the same comparison count**.

---

### Average Case

The Optimized Bubble Sort should perform **equal or fewer comparisons** than the Standard Bubble Sort.

---

### Sorting Correctness

Both algorithms always produce the same correctly sorted array.

The only difference is the number of comparisons performed.

---

# ✅ Conclusion

This experiment successfully compares the Standard Bubble Sort algorithm with an Optimized Bubble Sort using Early Stopping.

Although both algorithms have the same worst-case time complexity of **O(n²)**, the optimized implementation greatly improves the best-case performance by terminating as soon as the array becomes sorted.

The results clearly demonstrate that a simple optimization can significantly reduce unnecessary comparisons while preserving the correctness of the sorting process. This highlights the importance of algorithmic optimization in improving practical efficiency without changing the overall functionality of the algorithm.

