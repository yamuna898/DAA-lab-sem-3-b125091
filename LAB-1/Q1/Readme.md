# 📈 DAA Lab 01 – Question 1: Order of Growth Analysis

---

# 📚 Introduction

This repository contains the implementation for **Question 1** of the **Design and Analysis of Algorithms (DAA) Laboratory - Assignment 01**.

The objective of this experiment is to study the **asymptotic growth** of different mathematical functions and compare how quickly they increase as the input size (`n`) becomes large. Understanding the growth rate of functions is one of the fundamental concepts in algorithm analysis because it helps determine how an algorithm will perform as the problem size increases.

Instead of relying only on theoretical Big-O analysis, this program also performs **numerical evaluation** of each function for multiple values of `n` ranging from **10 to 50**. The calculated values are displayed in neatly formatted tables, allowing us to observe the practical difference in growth among the functions.

An additional **SVG graph** has also been included in this repository. The graph provides a visual comparison of the growth curves, making it easier to understand why certain functions dominate others for sufficiently large input sizes.

---

# 🎯 Objective

The primary goals of this experiment are:

- To evaluate a collection of mathematical functions for increasing values of `n`.
- To understand the concept of **asymptotic growth**.
- To compare functions using **Big-O notation**.
- To identify which functions grow slowly and which grow rapidly.
- To verify the theoretical ordering through actual computed values.
- To visualize the behavior of these functions using the provided SVG graph.

---

# 📝 Problem Statement

Given the following mathematical functions,

- `log₂(n)`
- `12√n`
- `50√n`
- `n^0.51`
- `2^32 × n`
- `n log₂(n)`
- `100n² + 6n`
- `n² − 324`
- `2n³`
- `n^(log₂n)`
- `3^n`

determine their order of growth for sufficiently large values of `n` and verify the ordering through computational evaluation.

---

# 💡 Methodology

The program is implemented in **C language**.

For every function, values are computed for

```
n = 10, 20, 30, 40, 50
```

The output is printed directly to the terminal in tabular form. No external graphing or plotting libraries are used for computation.

After obtaining the numerical values, the functions are arranged according to their asymptotic growth rate, ignoring constant multipliers and lower-order terms wherever applicable.

---

# 📊 Asymptotic Ordering (Slowest → Fastest)

Based on theoretical analysis and experimental observations, the functions are ordered as follows:

| Rank | Function | Growth Type |
|------|----------|-------------|
| 1 | `log₂(n)` | Logarithmic |
| 2 | `12√n` | Square Root |
| 3 | `50√n` | Square Root |
| 4 | `n^0.51` | Fractional Polynomial |
| 5 | `2^32 × n` | Linear |
| 6 | `n log₂(n)` | Linearithmic |
| 7 | `100n² + 6n` | Quadratic |
| 8 | `n² − 324` | Quadratic |
| 9 | `2n³` | Cubic |
| 10 | `n^(log₂n)` | Quasi-polynomial |
| 11 | `3^n` | Exponential |

---

# 📖 Observations

### 1. Logarithmic Function

`log₂(n)` grows the slowest among all the given functions. Even when the input size increases significantly, the output increases very gradually. This is why logarithmic algorithms are considered highly efficient.

---

### 2. Square Root Functions

Both `12√n` and `50√n` belong to the same asymptotic class **O(√n)**.

Although `50√n` always produces larger numerical values because of its larger constant multiplier, constants do not affect asymptotic complexity. Therefore, both functions have identical growth behavior.

---

### 3. Fractional Polynomial

The function `n^0.51` grows slightly faster than square root functions but remains much slower than linear functions.

Since its exponent is just greater than `0.5`, it eventually overtakes any square-root function while still remaining below linear growth.

---

### 4. Linear Function with a Huge Constant

`2^32 × n` demonstrates an important property of asymptotic analysis.

Although its numerical values are extremely large due to the enormous constant `2^32`, it is still fundamentally a **linear function**.

As `n` increases, only the variable part determines the growth rate, while the constant factor merely shifts the curve upward.

---

### 5. Linearithmic Function

`n log₂(n)` grows faster than every linear function because of the additional logarithmic factor.

Many efficient algorithms such as **Merge Sort**, **Heap Sort**, and **Quick Sort (average case)** have this complexity because it provides an excellent balance between performance and scalability.

---

### 6. Quadratic Functions

Both

- `100n² + 6n`
- `n² − 324`

are quadratic functions.

The coefficient `100` and the lower-order terms (`6n` and `−324`) only influence the numerical values for smaller inputs. As `n` becomes very large, the dominant term `n²` determines the overall growth.

Therefore, both belong to the same asymptotic complexity class **O(n²)**.

---

### 7. Cubic Function

`2n³` grows substantially faster than quadratic functions.

As the exponent increases from 2 to 3, the rate of increase becomes much more significant, illustrating why cubic algorithms become impractical for large datasets.

---

### 8. Quasi-polynomial Function

`n^(log₂n)` grows faster than any fixed-degree polynomial.

Although it is still slower than exponential growth, its values increase very rapidly, making it unsuitable for large inputs.

---

### 9. Exponential Function

`3^n` is the fastest-growing function in the list.

Even for relatively small values of `n`, its output becomes extraordinarily large.

This demonstrates why exponential-time algorithms quickly become infeasible for practical applications.

---

# 📈 Computational Results

The following tables show the computed values for all functions evaluated between `n = 10` and `n = 50`.

---

## 1. Slow to Medium Growing Functions

| n | log2(n) | 12 * sqrt(n) | 50 * n^0.5 | n^0.51 | n * log2(n) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **10** | 3.32 | 37.95 | 158.11 | 3.24 | 33.22 |
| **20** | 4.32 | 53.67 | 223.61 | 4.61 | 86.44 |
| **30** | 4.91 | 65.73 | 273.86 | 5.67 | 147.21 |
| **40** | 5.32 | 75.89 | 316.23 | 6.57 | 212.88 |
| **50** | 5.64 | 84.85 | 353.55 | 7.37 | 282.19 |

---

## 2. Fast Growing Functions

| n | 100n² + 6n | n² − 324 | 2n³ | n^(log₂n) | 3^n |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **10** | 10060 | -224 | 2000 | 2.10e+03 | 5.90e+04 |
| **20** | 40120 | 76 | 16000 | 4.41e+05 | 3.49e+09 |
| **30** | 90180 | 576 | 54000 | 2.20e+07 | 2.06e+14 |
| **40** | 160240 | 1276 | 128000 | 4.81e+08 | 1.22e+19 |
| **50** | 250300 | 2176 | 250000 | 6.20e+09 | 7.18e+23 |

---

## 3. Linear Function with a Large Constant

| n | 2^32 × n |
| :--- | :--- |
| **10** | 42,949,672,960 |
| **20** | 85,899,345,920 |
| **30** | 128,849,018,880 |
| **40** | 171,798,691,840 |
| **50** | 214,748,364,800 |

---

# 📊 Graphical Representation

An **SVG graph** has been included in this repository to complement the numerical results.

The graph clearly illustrates the relative growth rates of all eleven functions.

Some important observations from the graph include:

- The logarithmic curve remains almost flat.
- Square-root functions increase slowly.
- Linear and linearithmic functions diverge gradually.
- Quadratic and cubic functions become noticeably steeper.
- The quasi-polynomial function eventually surpasses all polynomial functions.
- The exponential function rises almost vertically, dominating every other function for larger values of `n`.

The graphical visualization reinforces the theoretical ordering obtained through asymptotic analysis.

---

# 🔍 Key Findings

- Constant multipliers do **not** affect asymptotic complexity.
- Lower-order terms become insignificant for sufficiently large values of `n`.
- Polynomial functions always outgrow logarithmic and square-root functions.
- Quasi-polynomial functions eventually exceed all fixed-degree polynomial functions.
- Exponential growth is dramatically faster than every other category considered in this experiment.
- The computed values are consistent with the theoretical ordering predicted using Big-O analysis.

---

# ✅ Conclusion

This experiment successfully demonstrates the importance of asymptotic analysis in algorithm design.

Although some functions begin with very large numerical values due to constant multipliers, asymptotic analysis focuses on the long-term growth behavior as the input size becomes large. The computational results and the accompanying SVG graph both confirm the theoretical ordering of the functions.

Understanding these growth patterns is essential for evaluating algorithm efficiency, comparing competing solutions, and selecting scalable algorithms for solving computational problems.