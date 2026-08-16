# Structured Matrix Multiplication in O(n²)

A C implementation of **structured matrix multiplication** that exploits a special block structure to reduce the time complexity of matrix multiplication from the general `O(n³)` to **`O(n²)`**.

The algorithm recursively divides the matrices into blocks and performs only **two recursive matrix multiplications** instead of the usual eight.

---

# Overview

General multiplication of two `n × n` matrices requires:

```text
O(n³)
```

time.

This implementation takes advantage of a specific matrix structure.

The matrices have the form:

```text
        ┌────────┬────────┐
A =     │   A1   │   A2   │
        ├────────┼────────┤
        │   A2   │   A1   │
        └────────┴────────┘
```

and:

```text
        ┌────────┬────────┐
B =     │   B1   │   B2   │
        ├────────┼────────┤
        │   B2   │   B1   │
        └────────┴────────┘
```

Because of this structure, the product can also be represented using only two matrix multiplications.

The key formulas are:

```text
P1 = (A1 + A2)(B1 + B2)

P2 = (A1 - A2)(B1 - B2)
```

Then:

```text
C1 = (P1 + P2) / 2
C2 = (P1 - P2) / 2
```

and the final matrix is:

```text
        ┌────────┬────────┐
C =     │   C1   │   C2   │
        ├────────┼────────┤
        │   C2   │   C1   │
        └────────┴────────┘
```

---

# Matrix Structure

The algorithm only works for matrices satisfying the special block structure:

```text
A = [ A1  A2 ]
    [ A2  A1 ]
```

and:

```text
B = [ B1  B2 ]
    [ B2  B1 ]
```

Here, `A1`, `A2`, `B1`, and `B2` are themselves square matrices.

This is the most important assumption of the algorithm.

It is **not** a general-purpose matrix multiplication algorithm.

---

# Example Input

The program uses:

```text
A =
[ 2  1  4  3 ]
[ 1  2  3  4 ]
[ 4  3  2  1 ]
[ 3  4  1  2 ]
```

This can be divided into:

```text
A1 = [ 2  1 ]
     [ 1  2 ]

A2 = [ 4  3 ]
     [ 3  4 ]
```

Therefore:

```text
A = [ A1  A2 ]
    [ A2  A1 ]
```

Similarly:

```text
B =
[ 1  2  3  1 ]
[ 2  1  1  3 ]
[ 3  1  1  2 ]
[ 1  3  2  1 ]
```

can be represented as:

```text
B1 = [ 1  2 ]
     [ 2  1 ]

B2 = [ 3  1 ]
     [ 1  3 ]
```

so:

```text
B = [ B1  B2 ]
    [ B2  B1 ]
```

---

# Mathematical Derivation

We have:

```text
A = [ A1  A2 ]
    [ A2  A1 ]

B = [ B1  B2 ]
    [ B2  B1 ]
```

Normal block multiplication gives:

```text
C11 = A1B1 + A2B2

C12 = A1B2 + A2B1

C21 = A2B1 + A1B2

C22 = A2B2 + A1B1
```

Notice:

```text
C11 = C22
```

and:

```text
C12 = C21
```

Therefore:

```text
C = [ C1  C2 ]
    [ C2  C1 ]
```

where:

```text
C1 = A1B1 + A2B2
C2 = A1B2 + A2B1
```

---

# Reducing Four Multiplications to Two

Calculating `C1` and `C2` directly requires four matrix multiplications:

```text
A1B1
A2B2
A1B2
A2B1
```

Instead, use:

```text
P1 = (A1 + A2)(B1 + B2)
```

Expanding:

```text
P1 = A1B1 + A1B2 + A2B1 + A2B2
```

and:

```text
P2 = (A1 - A2)(B1 - B2)
```

Expanding:

```text
P2 = A1B1 - A1B2 - A2B1 + A2B2
```

Now add them:

```text
P1 + P2
```

which gives:

```text
2A1B1 + 2A2B2
```

Therefore:

```text
(P1 + P2) / 2
= A1B1 + A2B2
```

So:

```text
C1 = (P1 + P2) / 2
```

Similarly:

```text
P1 - P2
```

gives:

```text
2A1B2 + 2A2B1
```

Therefore:

```text
C2 = (P1 - P2) / 2
```

This is the key optimization.

---

# Algorithm

The recursive function is:

```c
structured_matrix_mult(A, B, C, n)
```

---

## Step 1 — Base Case

When:

```c
n == 1
```

there is only one element in each matrix.

Therefore:

```c
C[0][0] = A[0][0] * B[0][0];
```

This takes:

```text
O(1)
```

time.

---

# Step 2 — Divide the Matrices

The matrices are divided into four blocks.

However, because of the special structure, only four blocks need to be stored:

```text
A1
A2
B1
B2
```

The program extracts:

```c
A1[i][j] = A[i][j];
A2[i][j] = A[i][j + k];

B1[i][j] = B[i][j];
B2[i][j] = B[i][j + k];
```

where:

```text
k = n / 2
```

---

# Step 3 — Create the Required Sums and Differences

The program calculates:

```text
SA = A1 + A2
DA = A1 - A2

SB = B1 + B2
DB = B1 - B2
```

These require only element-wise operations.

Each matrix addition/subtraction costs:

```text
O(k²)
```

---

# Step 4 — Perform Two Recursive Multiplications

The two important products are:

```c
structured_matrix_mult(SA, SB, P1, k);
structured_matrix_mult(DA, DB, P2, k);
```

Therefore, instead of four recursive multiplications, the algorithm performs only:

```text
2
```

recursive multiplications.

---

# Step 5 — Reconstruct the Result

For every element:

```text
C1 = (P1 + P2) / 2
C2 = (P1 - P2) / 2
```

The program places them into:

```text
C[i][j]         = C1
C[i+k][j+k]     = C1

C[i][j+k]       = C2
C[i+k][j]       = C2
```

giving:

```text
C = [ C1  C2 ]
    [ C2  C1 ]
```

---

# Example Calculation

For the provided matrices:

```text
A1 = [ 2  1 ]
     [ 1  2 ]

A2 = [ 4  3 ]
     [ 3  4 ]

B1 = [ 1  2 ]
     [ 2  1 ]

B2 = [ 3  1 ]
     [ 1  3 ]
```

Calculate:

```text
A1 + A2 =
[ 6  4 ]
[ 4  6 ]
```

and:

```text
B1 + B2 =
[ 4  3 ]
[ 3  4 ]
```

Therefore:

```text
P1 = (A1 + A2)(B1 + B2)
```

Similarly:

```text
A1 - A2 =
[ -2  -2 ]
[ -2  -2 ]
```

and:

```text
B1 - B2 =
[ -2   1 ]
[  1  -2 ]
```

giving:

```text
P2 = (A1 - A2)(B1 - B2)
```

Finally:

```text
C1 = (P1 + P2) / 2
C2 = (P1 - P2) / 2
```

The resulting matrix is:

```text
C =
[ 19  18  17  16 ]
[ 18  19  16  17 ]
[ 17  16  19  18 ]
[ 16  17  18  19 ]
```

---

# Recurrence Relation

At every recursive level, the algorithm performs:

```text
2 recursive matrix multiplications
```

on matrices of size:

```text
n/2
```

Additionally, it performs matrix additions, subtractions, and result construction.

Each of those operations requires:

```text
O(n²)
```

work.

Therefore:

```text
T(n) = 2T(n/2) + O(n²)
```

---

# Solving the Recurrence

Using the Master Theorem:

```text
a = 2
b = 2
f(n) = O(n²)
```

Calculate:

```text
n^(log₂2)
= n
```

We compare:

```text
f(n) = n²
```

with:

```text
n^(log₂2) = n
```

Since:

```text
n²
```

dominates:

```text
n
```

the recurrence becomes:

```text
T(n) = O(n²)
```

Therefore:

```text
Time Complexity = O(n²)
```

---

# Why This Is Possible

For **general matrices**, matrix multiplication cannot simply be reduced to two recursive multiplications using this method.

The `O(n²)` complexity is possible because the input matrices contain a lot of structure.

Instead of having four independent blocks:

```text
A11 A12
A21 A22
```

we know:

```text
A11 = A22 = A1
A12 = A21 = A2
```

Similarly:

```text
B11 = B22 = B1
B12 = B21 = B2
```

This dramatically reduces the amount of independent information that needs to be multiplied.

---

# Complexity Comparison

| Algorithm                            | Recursive Multiplications | Time Complexity |
| ------------------------------------ | ------------------------: | --------------: |
| Standard Matrix Multiplication       |                         8 |         `O(n³)` |
| Strassen                             |                         7 |    `O(n^2.807)` |
| **Structured Matrix Multiplication** |                     **2** |       **O(n²)** |

The improvement comes from exploiting the matrix structure rather than from a general improvement to matrix multiplication.

---

# Space Complexity

The implementation dynamically allocates several `n/2 × n/2` matrices:

```text
A1
A2
B1
B2
SA
DA
SB
DB
P1
P2
```

Each contains:

```text
O((n/2)²)
```

elements.

Therefore, the auxiliary memory required at a recursion level is:

```text
O(n²)
```

The recursion depth is:

```text
O(log n)
```

because the matrix size is halved at every recursive call.

The implementation frees the temporary matrices before returning from each recursive call.

Therefore, the dominant auxiliary space is:

```text
O(n²)
```

with significant allocation overhead due to the use of separate dynamically allocated matrices.

---

# Complexity Summary

| Property                            |  Complexity |
| ----------------------------------- | ----------: |
| Matrix addition                     |     `O(n²)` |
| Matrix subtraction                  |     `O(n²)` |
| Recursive multiplications per level |         `2` |
| Time complexity                     | **`O(n²)`** |
| Recursion depth                     |  `O(log n)` |
| Auxiliary matrix storage            | **`O(n²)`** |
| Base case                           |      `O(1)` |

---

# Important Assumption

This algorithm **must not be used for arbitrary matrices**.

The matrices must have the form:

```text
A = [ A1  A2 ]
    [ A2  A1 ]
```

and:

```text
B = [ B1  B2 ]
    [ B2  B1 ]
```

If this condition is not satisfied, the formulas used by the program will not produce the correct matrix product.

This is the most important difference between this algorithm and algorithms such as standard multiplication or Strassen's algorithm.

---

# Why `double` Is Used

The matrices are declared using:

```c
double**
```

rather than:

```c
int**
```

because the algorithm performs:

```text
(P1 + P2) / 2
(P1 - P2) / 2
```

Using `double` allows the intermediate and final results to represent fractional values if the matrix structure or input values produce them.

For the current integer input, the resulting values happen to be integers.

---

# Dynamic Memory Allocation

The program uses:

```c
double** allocate_matrix(int n)
```

to dynamically create matrices.

Memory is allocated using:

```c
malloc()
calloc()
```

`calloc()` initializes the matrix elements to zero.

Every dynamically allocated matrix is eventually released using:

```c
free_matrix()
```

This is particularly important because the recursive algorithm creates several temporary matrices at every level.

---

# Common Mistakes

### 1. Treating this as general matrix multiplication

This is incorrect.

The algorithm depends on:

```text
A11 = A22
A12 = A21

B11 = B22
B12 = B21
```

Without this structure, the formulas do not apply.

---

### 2. Thinking "two recursive calls" automatically means `O(n)`

The recurrence is:

```text
T(n) = 2T(n/2) + O(n²)
```

The `O(n²)` matrix operations dominate the recurrence.

Therefore:

```text
T(n) = O(n²)
```

not `O(n)`.

---

### 3. Forgetting the division by 2

The result blocks are:

```text
C1 = (P1 + P2) / 2
C2 = (P1 - P2) / 2
```

Without `/2`, the result is twice the required value.

---

### 4. Mixing up the block arrangement

The final matrix must be:

```text
C = [ C1  C2 ]
    [ C2  C1 ]
```

not an arbitrary combination of the four blocks.

---

# Program Output

The program prints:

```text
Matrix A (Structured 4x4):
  [    2.0    1.0    4.0    3.0 ]
  [    1.0    2.0    3.0    4.0 ]
  [    4.0    3.0    2.0    1.0 ]
  [    3.0    4.0    1.0    2.0 ]

Matrix B (Structured 4x4):
  [    1.0    2.0    3.0    1.0 ]
  [    2.0    1.0    1.0    3.0 ]
  [    3.0    1.0    1.0    2.0 ]
  [    1.0    3.0    2.0    1.0 ]
```

The resulting matrix is:

```text
Result Matrix C = A x B in O(n^2):
  [   19.0   18.0   17.0   16.0 ]
  [   18.0   19.0   16.0   17.0 ]
  [   17.0   16.0   19.0   18.0 ]
  [   16.0   17.0   18.0   19.0 ]
```

---

# How to Compile

Using GCC:

```bash
gcc structured_matrix.c -o structured_matrix
```

Run:

```bash
./structured_matrix
```

On Windows:

```bash
structured_matrix.exe
```

---

# Concepts Demonstrated

This project demonstrates:

* Divide and Conquer
* Recursive matrix multiplication
* Structured matrices
* Block matrix multiplication
* Algebraic simplification
* Recurrence relations
* Master Theorem
* Dynamic memory allocation
* `malloc()`
* `calloc()`
* `free()`
* Time complexity
* Space complexity

---

# Key Takeaway

The important idea is **exploiting structure**.

For a general matrix:

```text
A × B
```

requires many independent multiplications.

But for matrices of the form:

```text
A = [ A1  A2 ]
    [ A2  A1 ]
```

and:

```text
B = [ B1  B2 ]
    [ B2  B1 ]
```

the four required block products can be reconstructed from only two:

```text
P1 = (A1 + A2)(B1 + B2)

P2 = (A1 - A2)(B1 - B2)
```

This produces the recurrence:

```text
T(n) = 2T(n/2) + O(n²)
```

and therefore:

```text
T(n) = O(n²)
```

The key lesson is:

> **Special input structure can be exploited to eliminate unnecessary computation and achieve a much better complexity than a general-purpose algorithm.**
