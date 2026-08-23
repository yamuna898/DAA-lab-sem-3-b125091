# 📈 DAA Lab 04
__________________________________
Q2: Application of sorting-II (Two-Set Target Sum)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 2** of our DAA Lab-04 assignment.
The objective is to determine whether there exists a pair of elements $(a, b)$ such that $a \in S_1$, $b \in S_2$, and $a + b = x$, given two sets $S_1$ and $S_2$ (each of size $n$) and a target value $x$ in $O(n \log n)$ time.

## ⚙️ Algorithmic Logic & Justification

1. **Sort Phase:** Sort set $S_1$ in ascending order and set $S_2$ in ascending order using Merge Sort in $O(n \log n)$ time.
2. **Two-Pointer Traversal:** Place pointer $i$ at the beginning of $S_1$ ($i = 0$) and pointer $j$ at the end of $S_2$ ($j = n - 1$).
3. **Linear Scan:**
   * If $S_1[i] + S_2[j] == x$, a valid pair is found.
   * If $S_1[i] + S_2[j] < x$, increment $i$ to increase the sum.
   * If $S_1[i] + S_2[j] > x$, decrement $j$ to decrease the sum.
4. **Justification:** Sorting takes $2 \cdot O(n \log n) = O(n \log n)$ time. The two-pointer search runs in at most $2n$ steps ($O(n)$). The overall worst-case runtime is strictly dominated by sorting at $O(n \log n)$.
-------------------------------------------

## 💻 Given the output below showing the execution of the search

Below is the computational output evaluating the algorithm on two input sets of size $n = 5$ with target $x = 19$.

### Performance Comparison (Set Sizes $n = 5$, Target $x = 19$)

| Set $S_1$ Elements | Set $S_2$ Elements | Pair Found $(a, b)$ | Total Comparisons | Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `{14, 3, 9, 1, 7}` | `{10, 2, 25, 4, 18}` | **(1, 18)** | 5 | **$O(n \log n)$** |

---   

Note: Sorting both sets requires $\approx 2 \times (5 \log_2 5)$ operations; the scan phase resolves the pair in linear time.
