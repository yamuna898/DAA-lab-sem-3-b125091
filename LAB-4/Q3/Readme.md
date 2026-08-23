# 📈 DAA Lab 04
__________________________________
Q3: Application of sorting-III ($k$-Sum Problem)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 3** of our DAA Lab-04 assignment.
The objective is to test whether $k$ distinct integers in a set $S$ of size $n$ add up to a target integer $T$ in $O(n^{k-1} \log n)$ time.

## ⚙️ Algorithmic Logic & Justification

1. **Sort Phase:** Sort the array $S$ in ascending order in $O(n \log n)$ time.
2. **Combination Generation:** Iterate through all distinct combinations of $(k-1)$ elements $(s_1, s_2, \dots, s_{k-1})$ using $(k-1)$ nested loops. The total number of tuples is $\binom{n}{k-1} = O(n^{k-1})$.
3. **Binary Search for Remainder:** For each $(k-1)$-tuple, calculate the required remaining value $R = T - \sum_{m=1}^{k-1} s_m$ and search for $R$ in $S$ using Binary Search in $O(\log n)$ time.
4. **Justification:** Combining $O(n^{k-1})$ tuple evaluations with an $O(\log n)$ binary search per iteration yields an overall time complexity of $O(n^{k-1} \log n)$.

-------------------------------------------

## 💻 Given the output below showing the execution of the search

Below is the computational output evaluating the $k$-Sum algorithm for $k = 3$ and target $T = 14$ on a set of size $n = 6$.

### Performance Comparison (Array Size $n = 6$, $k = 3$, Target $T = 14$)

| Input Set $S$ | Combination Size ($k$) | Target ($T$) | Found Elements | Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `{12, 3, 7, 1, 9, 4}` | **3** | **14** | **(1, 4, 9)** | **$O(n^2 \log n)$** |

---   

Note: For $k=3$, generating pairs takes $O(n^2)$ and searching for the 3rd element takes $O(\log n)$.
