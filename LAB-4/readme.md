# 🚀 Design and Analysis of Algorithms (DAA) - Lab Portfolio

> **Institution:** IIIT BHUBANESWAR  
> **Course:** Design and Analysis of Algorithm (DAA) - Lab Portfolio[cite: 1]  
> **Program:** BTech CSE-B, 3rd Semester[cite: 1]  
> **Instructor:** Dr. Ajaya Kumar Dash[cite: 1]  
> **Date:** August 2026[cite: 1]  
> **Student Name:** R Yamuna | **Roll No:** B125091

---

## 📖 About This Repository
Welcome to my DAA Lab portfolio! This repository contains all the C programming assignments for **Lab 01, Lab 02, Lab 03, and Lab 04**, focused on foundational algorithmic design, asymptotic time complexity, and performance analysis.

Rather than just writing code that "works," these programs are engineered to prove mathematical concepts through empirical data generation, direct performance comparisons, and step-by-step visual simulations.

---

## 📂 Lab 01: Index of Programs

Click on any program title below to view the source code.

| Sl No. | Program Title | Algorithmic Concept Explored | Asymptotic Complexity Focus |
| :---: | :--- | :--- | :--- |
| **01** | **[Order of Growth Analysis](LAB1/1ST/Know_Function.c)** | Evaluating and ranking mathematical functions by growth rate. | $O(\log n)$ to $O(3^n)$ |
| **02** | **[Coin Toss Simulation](LAB1/2ND/COIN_TOSS.c)** | Law of Large Numbers, algorithmic weighting, and probability. | $O(n)$ Trials |
| **03** | **[Bubble Sort Performance](LAB1/3RD/PerformanceOfBubble.c)** | Unoptimized vs. Optimized early-exit sorting algorithms. | $\Omega(n)$ vs $O(n^2)$ |
| **04** | **[Tower of Hanoi (Simulation)](LAB1/4TH/TowerOfHanoi.c)** | Divide and conquer recursion and Stack state-tracking. | $O(2^n)$ Exponential |
| **05** | **[Find the Partition Point](LAB1/5TH/PartitionPoint.c)** | Searching sorted binary arrays: Linear vs. Binary search. | $O(n)$ vs $O(\log n)$ |
| **06** | **[Element Uniqueness](LAB1/6TH/Element_Uniqueness.c)** | The Space-Time Tradeoff: Nested loops vs. Hash arrays. | $O(n^2)$ vs $O(n)$ |

---

## 📂 Lab 02: Index of Programs

Click on any program title below to view the source code.

| Sl No. | Program Title | Algorithmic Concept Explored | Asymptotic Complexity Focus |
| :---: | :--- | :--- | :--- |
| **01** | **[Dictionary Operations Analysis](LAB2/1ST/Dictionary.c)** | Empirical performance validation of 7 dictionary operations across 6 distinct underlying data structures. | Array vs Linked List ($O(1)$ to $O(n)$) |
| **02** | **[Modified Merge Sort (3-Way)](LAB2/2ND/ThreeWayMergeSort.c)** | Divide and conquer by thirds with a three-way merge subroutine and growth-rate plotting. | $O(n \log_3 n)$ |
| **03** | **[Merging K Sorted Arrays](LAB2/3RD/MergeKSortedArrays.c)** | Comparison of sequential merging (Method 1) vs. pairwise divide-and-conquer merging (Method 2). | $O(kn^2)$ vs $O(kn \log k)$ |

---

## 📂 Lab 03: Index of Programs

Click on any program title below to view the source code.

| Sl No. | Program Title | Algorithmic Concept Explored | Asymptotic Complexity Focus |
| :---: | :--- | :--- | :--- |
| **01** | **[Binary vs Ternary Search](LAB3/1ST/BinaryVsTernary.c)** | Comparing division by halves vs division by thirds to search a sorted list. | $O(\log_2 n)$ vs $O(\log_3 n)$ |
| **02** | **[Defective Coin Finder](LAB3/2ND/DefectiveCoin.c)** | Divide and conquer algorithm utilizing a balance weighing scale to identify a lighter defective coin. | $O(\log_2 n)$ |
| **03** | **[Max and Min (D&C)](LAB3/3RD/MaxMinDC.c)** | Divide and conquer approach to locate maximum and minimum array elements. | Bounded by $\frac{3n}{2}$ |
| **04** | **[Strassen's Matrix Multiplication](LAB3/4TH/StrassenMatrix.c)** | Multiplying two $n \times n$ square matrices utilizing Strassen's method. | $O(n^{2.81})$ |
| **05** | **[Special Pattern Matrix Mult](LAB3/5TH/SpecialMatrixMult.c)** | Divide-and-conquer multiplication of matrices with identical diagonal and off-diagonal recursive blocks. | $O(n^2)$ |
| **06** | **[Selection Sort & Loop Invariants](LAB3/6TH/SelectionSortInvariant.c)** | Proving sorting correctness using initialisation, maintenance, and termination loop invariants. | $\Theta(n^2)$ |

---

## 📂 Lab 04: Index of Programs

Click on any program title below to view the source code.

| Sl No. | Program Title | Algorithmic Concept Explored | Asymptotic Complexity Focus |
| :---: | :--- | :--- | :--- |
| **01** | **[Stable Color Partitioning](LAB4/1ST/1stSortByColor.c)** | Stable 3-color sorting of pre-sorted numeric pairs using counting sort/bucket partitioning. | $O(n)$ |
| **02** | **[Target Sum Pair in Two Sets](LAB4/2ND/2ndSumEqualTo.c)** | Finding an element pair across two disjoint sets $S_1, S_2$ that sums to $x$ via sorting and two-pointer/binary search. | $O(n \log n)$ |
| **03** | **[K-Sum Subproblem Finder](LAB4/3RD/3rdValueEqualT.c)** | Determining whether any combination of $k$ distinct elements in set $S$ sums to target $T$. | $O(n^{k-1} \log n)$ |
| **04** | **[Peak Party Attendees](LAB4/4TH/4thCamera.c)** | Sweep-line event scheduling to locate the timestamp of maximum simultaneous party attendees. | $O(n \log n)$ |
| **05** | **[Merge Overlapping Intervals](LAB4/5TH/5thMergeOverlap.c)** | Sorting intervals by start coordinate and consolidating overlapping contiguous intervals. | $O(n \log n)$ |
| **06** | **[Max Interval Overlap Point](LAB4/6TH/6thLargestOnInterval.c)** | Event-based sweep-line algorithm to find a point $p$ contained within the maximum number of closed intervals. | $O(n \log n)$ |

---

## 🛠️ Technology Stack & Prerequisites
All programs in this repository are written in **Standard C** and are designed to be run directly from the terminal. There are no heavy external dependencies required.

* **Compiler:** GCC (GNU Compiler Collection)
* **Libraries Used:** `<stdio.h>`, `<stdlib.h>`, `<stdbool.h>`, `<time.h>`, `<math.h>`

---

## 💻 General Compilation Instructions

If you are evaluating these files on a Linux/Unix environment, you can compile and run any of the `.c` files using the standard `gcc` command:

```bash
# Example compilation for Lab 04
gcc LAB4/1ST/ColorSort.c -o ColorSort
./ColorSort