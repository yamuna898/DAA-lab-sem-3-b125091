# Strassen Matrix Multiplication in C

A C implementation of **Strassen's Matrix Multiplication algorithm**, a Divide and Conquer technique that reduces the number of recursive matrix multiplications from **8 to 7**.

The program supports matrices whose dimensions are **not necessarily powers of 2** by automatically padding them with zeros before applying Strassen's algorithm.

---

# Overview

The standard matrix multiplication of two `n × n` matrices requires:

```text
n³
```

scalar multiplications, giving:

```text
O(n³)
```

time complexity.

Strassen's algorithm improves the asymptotic complexity by dividing each matrix into four submatrices and using **7 recursive multiplications instead of 8**.

Its recurrence is:

```text
T(n) = 7T(n/2) + O(n²)
```

which gives:

```text
T(n) = O(n^log₂7)
```

Since:

```text
log₂7 ≈ 2.807
```

the complexity is approximately:

```text
O(n^2.807)
```

which is asymptotically better than:

```text
O(n³)
```

---

# What This Program Does

The program:

1. Allocates matrices dynamically.
2. Accepts square matrices.
3. Finds the next power of 2 greater than or equal to `n`.
4. Pads the matrices with zeros.
5. Recursively applies Strassen's algorithm.
6. Combines the resulting submatrices.
7. Removes the padding.
8. Prints the final matrix.
9. Frees all dynamically allocated memory.

---

# Example

The program uses:

```text
A =
[ 1  2  3  4 ]
[ 5  6  7  8 ]
[ 9  1  2  3 ]
[ 4  5  6  7 ]
```

and:

```text
B =
[ 1  0  0  1 ]
[ 0  1  1  0 ]
[ 1  1  0  0 ]
[ 0  0  1  1 ]
```

The program calculates:

```text
C = A × B
```

using Strassen's algorithm.

---

# Standard Matrix Multiplication

For two matrices:

```text
A × B = C
```

each element of `C` is calculated as:

```text
C[i][j] = Σ A[i][k] × B[k][j]
```

For an `n × n` matrix:

* `n²` output elements
* `n` multiplications per element
* `n` additions per element

Therefore:

```text
Time Complexity = O(n³)
```

---

# Why Strassen's Algorithm?

Suppose:

```text
A and B
```

are divided into four `n/2 × n/2` blocks:

```text
A = | A11  A12 |
    | A21  A22 |

B = | B11  B12 |
    | B21  B22 |
```

Normal Divide and Conquer multiplication requires:

```text
8 matrix multiplications
```

because:

```text
C11 = A11B11 + A12B21
C12 = A11B12 + A12B22
C21 = A21B11 + A22B21
C22 = A21B12 + A22B22
```

That produces the recurrence:

```text
T(n) = 8T(n/2) + O(n²)
```

which remains:

```text
O(n³)
```

---

# Strassen's Main Idea

Strassen discovered that the same result can be obtained using only **7 matrix multiplications**.

The program calculates:

```text
M1 = (A11 + A22)(B11 + B22)

M2 = (A21 + A22)B11

M3 = A11(B12 - B22)

M4 = A22(B21 - B11)

M5 = (A11 + A12)B22

M6 = (A21 - A11)(B11 + B12)

M7 = (A12 - A22)(B21 + B22)
```

These are the seven recursive multiplications.

---

# Constructing the Result

After calculating `M1` through `M7`, the four result blocks are constructed.

## C11

```text
C11 = M1 + M4 - M5 + M7
```

In the code:

```c
add(M1, M4, tempA, k);
subtract(tempA, M5, tempB, k);
add(tempB, M7, C11, k);
```

---

## C12

```text
C12 = M3 + M5
```

Code:

```c
add(M3, M5, C12, k);
```

---

## C21

```text
C21 = M2 + M4
```

Code:

```c
add(M2, M4, C21, k);
```

---

## C22

```text
C22 = M1 - M2 + M3 + M6
```

Code:

```c
subtract(M1, M2, tempA, k);
add(tempA, M3, tempB, k);
add(tempB, M6, C22, k);
```

---

# Visual Representation

The input matrices are divided as:

```text
             Matrix A
        ┌────────┬────────┐
        │  A11   │  A12   │
        ├────────┼────────┤
        │  A21   │  A22   │
        └────────┴────────┘

             Matrix B
        ┌────────┬────────┐
        │  B11   │  B12   │
        ├────────┼────────┤
        │  B21   │  B22   │
        └────────┴────────┘
```

Seven recursive products are calculated:

```text
M1 M2 M3 M4 M5 M6 M7
```

Then:

```text
        ┌────────┬────────┐
        │  C11   │  C12   │
        ├────────┼────────┤
        │  C21   │  C22   │
        └────────┴────────┘
```

is constructed.

---

# Algorithm Flow

```text
Input A, B
    ↓
Check matrix size
    ↓
Find next power of 2
    ↓
Zero-pad A and B
    ↓
Divide matrices into 4 blocks
    ↓
Calculate M1 ... M7 recursively
    ↓
Calculate C11, C12, C21, C22
    ↓
Combine blocks
    ↓
Remove zero padding
    ↓
Return C
```

---

# Base Case

The recursion stops when:

```c
if (n == 1)
```

At this point, matrix multiplication is simply:

```c
C[0][0] = A[0][0] * B[0][0];
```

No further division is required.

---

# Handling Non-Power-of-2 Sizes

Strassen's algorithm naturally works most conveniently when:

```text
n = 2^k
```

For example:

```text
1
2
4
8
16
32
64
...
```

But the program can accept other sizes.

It calculates:

```c
int m = 1;

while (m < n) {
    m *= 2;
}
```

For example:

| Original Size | Padded Size |
| ------------: | ----------: |
|       `3 × 3` |     `4 × 4` |
|       `4 × 4` |     `4 × 4` |
|       `5 × 5` |     `8 × 8` |
|       `7 × 7` |     `8 × 8` |
|       `8 × 8` |     `8 × 8` |
|     `10 × 10` |   `16 × 16` |

The extra cells are initialized to zero using:

```c
calloc()
```

so the padding does not affect the mathematical result.

---

# Dynamic Matrix Allocation

The program uses:

```c
int** allocate_matrix(int n)
```

to dynamically allocate an `n × n` matrix.

First, memory is allocated for the row pointers:

```c
int** mat = (int**)malloc(n * sizeof(int*));
```

Then each row is allocated separately:

```c
mat[i] = (int*)calloc(n, sizeof(int));
```

`calloc()` is useful here because it initializes all elements to zero, which is important when padding matrices.

---

# Memory Deallocation

Every dynamically allocated matrix must eventually be freed.

The program uses:

```c
void free_matrix(int** mat, int n)
```

which first frees every row:

```c
free(mat[i]);
```

and then frees the array of row pointers:

```c
free(mat);
```

This is especially important in Strassen's implementation because many temporary matrices are created during every recursive call.

---

# Time Complexity

Let:

```text
n = matrix dimension
```

At each level, Strassen's algorithm performs:

```text
7 recursive multiplications
```

on matrices of size:

```text
n/2 × n/2
```

Additionally, matrix additions and subtractions require:

```text
O(n²)
```

work.

Therefore:

```text
T(n) = 7T(n/2) + O(n²)
```

Using the Master Theorem:

```text
a = 7
b = 2
f(n) = O(n²)
```

Calculate:

```text
n^(log₂7)
```

Since:

```text
log₂7 ≈ 2.807
```

and:

```text
n² < n^2.807
```

the recurrence gives:

```text
T(n) = Θ(n^log₂7)
```

Therefore:

```text
T(n) ≈ O(n^2.807)
```

---

# Comparison With Standard Multiplication

| Algorithm                       | Recurrence              |  Time Complexity |
| ------------------------------- | ----------------------- | ---------------: |
| Standard Multiplication         | `T(n) = n²T(n-1) + ...` |          `O(n³)` |
| Divide & Conquer Multiplication | `8T(n/2) + O(n²)`       |          `O(n³)` |
| **Strassen**                    | **`7T(n/2) + O(n²)`**   | **`O(n^2.807)`** |

The important improvement is:

```text
8 recursive multiplications
        ↓
7 recursive multiplications
```

That one reduction changes the asymptotic complexity.

---

# Space Complexity

The implementation creates many temporary matrices:

```text
A11 A12 A21 A22
B11 B12 B21 B22
M1 ... M7
C11 C12 C21 C22
tempA
tempB
```

Each matrix at a recursion level contains:

```text
O((n/2)²) = O(n²)
```

elements.

Because the recursive implementation allocates temporary matrices at multiple levels, the memory usage is significantly higher than standard matrix multiplication.

The auxiliary space is approximately:

```text
O(n²)
```

at a single recursion level, with substantial allocation overhead across the recursive computation.

The exact peak memory usage depends on the implementation strategy and the lifetime of temporary matrices.

---

# Complexity Summary

| Property                       |               Complexity |
| ------------------------------ | -----------------------: |
| Standard Matrix Multiplication |                  `O(n³)` |
| Strassen Multiplication        |             `O(n^2.807)` |
| Matrix Addition                |                  `O(n²)` |
| Matrix Subtraction             |                  `O(n²)` |
| Base Case                      |                   `O(1)` |
| Auxiliary Matrix Storage       | `O(n²)` per active level |
| Recursion Depth                |               `O(log n)` |

---

# Why Strassen Is Not Always Faster

Although Strassen has better asymptotic complexity, it does **not** automatically mean it is faster for every matrix size.

The implementation performs many additional operations:

* Matrix additions
* Matrix subtractions
* Dynamic memory allocations
* Dynamic memory deallocations
* Copying submatrices
* Recursive function calls

For small matrices, standard multiplication can therefore be faster.

Strassen becomes more attractive for sufficiently large matrices.

---

# Important Implementation Detail

This implementation creates separate matrices for every submatrix:

```c
int** A11 = allocate_matrix(k);
int** A12 = allocate_matrix(k);
...
```

and copies values into them.

This makes the algorithm easier to understand, but it introduces considerable memory-allocation and copying overhead.

Production implementations often optimize this using:

* Contiguous memory
* Matrix views
* Reused temporary buffers
* Cache-aware layouts
* Thresholds that switch to normal multiplication for small matrices

---

# Common Mistakes

### 1. Forgetting that Strassen uses 7 multiplications

The main idea is:

```text
7 multiplications + additions/subtractions
```

not simply "divide the matrix recursively."

---

### 2. Getting the formulas for C11–C22 wrong

The formulas must be:

```text
C11 = M1 + M4 - M5 + M7

C12 = M3 + M5

C21 = M2 + M4

C22 = M1 - M2 + M3 + M6
```

A single sign error produces an incorrect result.

---

### 3. Forgetting zero padding

If `n` is not a power of 2, directly splitting the matrix may produce uneven submatrices.

Padding solves this:

```text
5 × 5
  ↓
8 × 8
```

with zeros filling the extra positions.

---

### 4. Forgetting to remove padding

After multiplying the padded matrices, only the original `n × n` portion should be copied back into the result.

The program correctly performs:

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        C[i][j] = paddedC[i][j];
    }
}
```

---

### 5. Memory leaks

Because the implementation dynamically allocates many matrices, every allocation must eventually have a corresponding:

```c
free_matrix()
```

Failure to do so causes memory leaks.

---

# How to Compile

Using GCC:

```bash
gcc strassen.c -o strassen
```

Run:

```bash
./strassen
```

On Windows:

```bash
strassen.exe
```

---

# Expected Output

The program first prints the input matrices:

```text
Matrix A (4x4):
  [    1    2    3    4 ]
  [    5    6    7    8 ]
  [    9    1    2    3 ]
  [    4    5    6    7 ]

Matrix B (4x4):
  [    1    0    0    1 ]
  [    0    1    1    0 ]
  [    1    1    0    0 ]
  [    0    0    1    1 ]
```

The resulting matrix is:

```text
C =
[  4   7   8   5 ]
[ 12  13  14  13 ]
[ 11   3   4  12 ]
[ 10  11  12  11 ]
```

---

# Concepts Demonstrated

This project demonstrates:

* Divide and Conquer
* Strassen's Algorithm
* Matrix multiplication
* Recursion
* Recurrence relations
* Master Theorem
* Dynamic memory allocation
* `malloc()`
* `calloc()`
* `free()`
* Matrix partitioning
* Matrix addition and subtraction
* Zero padding
* Space complexity
* Time complexity

---

# Key Takeaway

Standard matrix multiplication performs:

```text
O(n³)
```

work.

Strassen reduces the number of recursive multiplications:

```text
8 → 7
```

which changes the recurrence from:

```text
T(n) = 8T(n/2) + O(n²)
```

to:

```text
T(n) = 7T(n/2) + O(n²)
```

and therefore improves the asymptotic complexity to:

```text
O(n^log₂7) ≈ O(n^2.807)
```

The central lesson is:

> **Reducing the number of expensive recursive operations can improve the overall asymptotic complexity, even when additional lower-order operations such as additions and subtractions are introduced.**
