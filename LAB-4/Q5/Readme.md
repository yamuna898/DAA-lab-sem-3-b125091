# 📈 DAA Lab 04
__________________________________
Q5: Application of sorting-V (Interval Merging)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 5** of our DAA Lab-04 assignment.
The objective is to take a list $I$ of $n$ intervals $(x_i, y_i)$ and merge all overlapping intervals into a minimal list of disjoint intervals in worst-case $O(n \log n)$ time.

## ⚙️ Algorithmic Logic & Justification

1. **Sort Intervals:** Sort all $n$ intervals in ascending order based on their starting coordinate $x_i$ in $O(n \log n)$ time.
2. **Linear Merge Pass:**
   * Insert the first interval $(x_0, y_0)$ into the merged list.
   * Iterate through the remaining intervals $(x_i, y_i)$ from index $1$ to $n-1$:
     * If $x_i \le y_{\text{last}}$, an overlap occurs; update the current interval's upper bound to $\max(y_{\text{last}}, y_i)$.
     * Otherwise, append $(x_i, y_i)$ as a brand-new disjoint interval.
3. **Justification:** Sorting dominates the process at $O(n \log n)$. The linear scan inspects each interval exactly once in $O(n)$ time. Total worst-case runtime is $O(n \log n)$.

-------------------------------------------

## 💻 Given the output below showing the execution of the merge

Below is the computational output evaluating interval merging on the sample dataset $I$.

### Performance Comparison (Interval Count $n = 4$)

| Input Interval List ($I$) | Sorted Initial Intervals | Merged Disjoint Output Intervals | Time Complexity |
| :--- | :--- | :--- | :--- |
| `{(1,3), (2,6), (8,10), (7,18)}` | `(1,3), (2,6), (7,18), (8,10)` | **`{(1, 6), (7, 18)}`** | **$O(n \log n)$** |

---   

Note: Intervals $(1,3)$ and $(2,6)$ merge to $(1,6)$, while $(7,18)$ and $(8,10)$ merge to $(7,18)$.
