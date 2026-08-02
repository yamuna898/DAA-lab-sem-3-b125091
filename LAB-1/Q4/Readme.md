# 🗼 DAA Lab 01

______________________________________
# Q4: Tower of Hanoi Analysis
______________________________________

---

# 📌 Overview

This repository contains the C programming implementation for **Question 4** of the **Design and Analysis of Algorithms (DAA) Laboratory – Assignment 01**.

The objective of this experiment is to solve the classic **Tower of Hanoi** problem using the **Divide and Conquer** technique based on **recursion**. Along with displaying the sequence of moves required to solve the puzzle, the program also analyzes how the number of moves grows as the number of disks increases.

The experiment demonstrates one of the most well-known recursive algorithms and illustrates why the Tower of Hanoi problem has **exponential time complexity**.

---

# 🎯 Objective

The objectives of this experiment are:

- To understand recursive problem solving.
- To implement the Tower of Hanoi algorithm using recursion.
- To display the complete sequence of disk movements.
- To verify the mathematical formula for the minimum number of moves.
- To study the exponential growth of recursive algorithms.

---

# 📝 Problem Statement

The Tower of Hanoi puzzle consists of three pegs:

- Source Peg
- Auxiliary (Helper) Peg
- Destination Peg

A number of disks of different sizes are initially stacked on the Source peg in decreasing order of size.

The objective is to move the entire stack to the Destination peg while following these rules:

1. Only one disk can be moved at a time.
2. Only the topmost disk of any peg can be moved.
3. A larger disk can never be placed on top of a smaller disk.

The challenge is to complete the task using the minimum possible number of moves.

---

# 💡 Methodology

The solution uses a **recursive Divide and Conquer** strategy.

Instead of attempting to move all disks simultaneously, the problem is repeatedly divided into smaller subproblems until only a single disk remains.

The program performs the following tasks:

- Prints each move required to solve the puzzle.
- Counts the total number of moves performed.
- Generates a table showing the minimum number of moves required for different numbers of disks.

---

# ⚙️ Algorithmic Logic

The recursive solution follows three simple steps.

### Step 1

Move the top **n − 1** disks from the **Source** peg to the **Auxiliary** peg.

---

### Step 2

Move the largest (nth) disk directly from the **Source** peg to the **Destination** peg.

---

### Step 3

Move the **n − 1** disks from the **Auxiliary** peg to the **Destination** peg.

The same three steps continue recursively until only one disk remains.

---

## Base Case

When only one disk remains:

- Move it directly from the Source peg to the Destination peg.
- The recursion terminates.

---

# 📐 Mathematical Analysis

The recurrence relation for the Tower of Hanoi problem is:

```
T(n) = 2T(n−1) + 1
```

Solving the recurrence gives:

```
T(n) = 2ⁿ − 1
```

where:

- **n** = Number of disks
- **T(n)** = Minimum number of moves required

This shows that the number of moves doubles with every additional disk, resulting in exponential growth.

---

# 📊 Experimental Output

The program first demonstrates the complete solution for **3 disks** by printing every move performed.

Example:

```
Step 1 : Move Disk 1 from A to C
Step 2 : Move Disk 2 from A to B
Step 3 : Move Disk 1 from C to B
...
```

After completing the puzzle, the program prints the total number of moves required.

---

## Exponential Growth Analysis

The program also generates the following table.

| Number of Disks (n) | Minimum Moves (2ⁿ − 1) |
| :---: | :---: |
| 3 | 7 |
| 4 | 15 |
| 5 | 31 |
| ... | ... |
| 20 | 1,048,575 |

This demonstrates how rapidly the number of required moves increases as the number of disks grows.

---

# 📈 Time Complexity Analysis

| Complexity Measure | Value |
|--------------------|-------|
| Best Case | O(2ⁿ) |
| Average Case | O(2ⁿ) |
| Worst Case | O(2ⁿ) |
| Auxiliary Space | O(n) |

The recursive call stack grows proportionally to the number of disks, resulting in **O(n)** auxiliary space.

---

# 📖 Observations

- Every additional disk approximately doubles the total number of required moves.
- Even a small increase in the number of disks causes a significant increase in execution steps.
- Recursive algorithms can become computationally expensive for large input sizes.
- The Tower of Hanoi is a classic example of an algorithm with exponential time complexity.

---

# 🔍 Key Findings

- The Tower of Hanoi problem follows the Divide and Conquer strategy.
- Recursion naturally models the problem.
- The minimum number of moves follows the mathematical formula **2ⁿ − 1**.
- The recursive depth increases linearly with the number of disks.
- Although elegant, the algorithm becomes impractical for large values of **n** because of its exponential growth.

---

# ▶ How to Compile

Using GCC:

```bash
gcc TowerOfHanoi.c -o hanoi
```

Run the program:

```bash
./hanoi
```

For Windows (MinGW):

```bash
gcc TowerOfHanoi.c -o hanoi.exe
hanoi.exe
```

---

# ✔ Verification

The implementation can be verified using the following observations.

- The sequence of moves should correctly transfer every disk from the Source peg to the Destination peg.
- No larger disk should ever be placed above a smaller disk.
- The total number of moves should exactly equal **2ⁿ − 1**.
- The generated table should match the mathematical values for each number of disks.

---

# ✅ Conclusion

This experiment successfully demonstrates the recursive solution to the Tower of Hanoi problem using the Divide and Conquer technique.

The algorithm correctly generates the sequence of moves required to solve the puzzle while also verifying the mathematical relationship **2ⁿ − 1** for the minimum number of moves. The experiment highlights the elegance of recursion as well as the limitations of exponential-time algorithms when solving larger problem instances.
