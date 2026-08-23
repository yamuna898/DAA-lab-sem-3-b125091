# 📈 DAA Lab 04
__________________________________
Q1: Application of sorting-I (Color-Based Stable Sort)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 1** of our DAA Lab-04 assignment.
The objective is to take $n$ pairs of items sorted by number, where each pair contains a number and one of three colors (Red, Blue, Yellow), and sort the items by color (all Reds before Blues before Yellows) in $O(n)$ time while ensuring numbers for identical colors stay in their original relative sorted order.

## ⚙️ Algorithmic Logic & Justification

1. **Stable Counting / Bucket Partition:** Since the key domain consists of exactly three distinct colors, a two-pass counting approach achieves linear time.
2. **Frequency Count:** Traverse the list once to record the frequencies of Red, Blue, and Yellow.
3. **Prefix Pointers:** Compute starting indices for each color category.
4. **Stable Write Pass:** Iterate through the original numerically sorted array sequentially, placing elements into their respective color blocks.
5. **Justification:** Because the input array is already sorted by number and elements are copied left-to-right into their corresponding color buckets, their relative numerical order is preserved (stability) in $O(n)$ time and $O(n)$ auxiliary space.

-------------------------------------------

## 💻 Given the output below showing the execution of the sort

Below is the computational output evaluating the stable color partition algorithm on a sample sorted-by-number input list.

### Performance Comparison (Array Size $n = 6$)

| Input Element Pairs | Target Order | Sorting Method | Total Passes | Time Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `(1,B), (2,R), (3,Y), (4,R), (5,B), (6,Y)` | Red $\to$ Blue $\to$ Yellow| Stable 3-Way Bucket Sort | 2 Passes | **$O(n)$** |

---   

Note: Output yields `(2,R), (4,R), (1,B), (5,B), (3,Y), (6,Y)`. Numbers for identical colors remain perfectly sorted without comparison-based overhead.
