# Magic Square Construction Methods

## Aim
To study and implement different methods of constructing magic squares and analyze their theoretical concepts, approaches, and computational complexities.

---

## Introduction
A **magic square** is a square matrix of order `n × n` filled with distinct integers from `1` to `n²` such that the sum of numbers in each row, each column, and both main diagonals is the same.  
This common value is known as the **magic constant**:

\[
M = \frac{n(n^2 + 1)}{2}
\]

There are multiple methods to construct magic squares depending on the order `n`.

---

## Method 1: Siamese Method (De la Loubère’s Method)

### Applicability
- Works for **odd-order magic squares** (n = 3, 5, 7, ...).

### Algorithm / Steps
1. Start with `1` placed in the **middle cell of the top row**.
2. The next number is placed **one cell up and one cell right** (diagonal up-right move).
3. If the move goes out of bounds:
   - Wrap around (from top to bottom or right to left).
4. If the target cell is already filled:
   - Place the number **directly below** the previous cell instead.
5. Repeat until all `n²` numbers are placed.

### Example (3×3 Magic Square)

8 1 6
3 5 7
4 9 2


Here, each row/column/diagonal sums to `15`.

### Time Complexity
- Each number from `1` to `n²` is placed exactly once.
- Time Complexity: **O(n²)**
- Space Complexity: **O(n²)** for storing the square.

---

## Method 2: 4×4 Method (Doubly Even Order Method)

### Applicability
- Works for **doubly even order magic squares** (n divisible by 4: 4, 8, 12, ...).

### Algorithm / Steps
1. Fill the matrix sequentially from `1` to `n²` row-wise.
2. Identify special cells based on a pattern (usually diagonals or 4×4 sub-blocks).
3. In these positions, replace the number `x` with `(n² + 1) - x`.
4. Leave other cells as they are.
5. The resulting matrix becomes a magic square.

### Example (4×4 Magic Square)


16 2 3 13
5 11 10 8
9 7 6 12
4 14 15 1



Each row/column/diagonal sums to `34`.

### Time Complexity
- Filling numbers: O(n²).
- Flipping selected cells: O(n²).
- Time Complexity: **O(n²)**
- Space Complexity: **O(n²)** for storing the square.

---

## Comparison of Methods

| Method            | Applicability                 | Approach Type      | Time Complexity | Space Complexity |
|-------------------|-------------------------------|-------------------|-----------------|------------------|
| Siamese Method    | Odd-order squares (3,5,7,...) | Movement-based     | O(n²)           | O(n²)            |
| 4×4 Method        | Doubly even squares (n%4=0)   | Filling + Inversion | O(n²)           | O(n²)            |

---

## Conclusion
- The **Siamese Method** is the most straightforward for **odd-order magic squares** using a positional movement rule.  
- The **4×4 Method** is efficient for **doubly even squares**, relying on a filling-and-inversion pattern.  
- Both methods achieve the same time complexity of **O(n²)** and space complexity of **O(n²)**, but differ in their construction strategy and applicability.  
