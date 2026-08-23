# 📈 DAA Lab 04
__________________________________
Q6: Application of sorting-VI (Point in Maximum Intervals)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 6** of our DAA Lab-04 assignment.
The objective is to identify a point $p$ on a real line that is contained within the maximum number of intervals from a given set $S$ of $n$ intervals $(l_i, r_i)$ in $O(n \log n)$ time.

## ⚙️ Algorithmic Logic & Justification

1. **Endpoint Discretization:** Convert every closed interval $[l_i, r_i]$ into a Start event `(+1)` at $l_i$ and an End event `(-1)` at $r_i$.
2. **Sorting with Boundary Rules:** Sort all $2n$ endpoints in ascending order in $O(n \log n)$ time. If a start and end point share the same coordinate ($l_i = r_j$), the Start event is ordered first to ensure inclusive boundary overlap.
3. **Prefix Overlap Scan:** Traverse through the sorted coordinates, maintaining a running sum of active intervals. Track the coordinate that generates the global maximum sum.
4. **Justification:** Sorting $2n$ points takes $O(n \log n)$ time. Finding the peak point during the single scan requires $O(n)$ operations, achieving an optimal $O(n \log n)$ bound.

-------------------------------------------

## 💻 Given the output below showing the execution of the search

Below is the computational output evaluating the optimal point selection on interval set $S$.

### Performance Comparison (Interval Count $n = 4$)

| Input Interval Set ($S$)[cite: 1] | Peak Overlapping Intervals | Identified Point ($p$) | Time Complexity |
| :--- | :--- | :--- | :--- |
| `{(10,40), (20,60), (50,90), (15,70)}` | **3 Intervals** | **$p = 50$** (or any point in $[20, 40]$) | **$O(n \log n)$** |

---   

Note: At point $p = 50$, intervals $(20,60)$, $(50,90)$, and $(15,70)$ all overlap simultaneously.
