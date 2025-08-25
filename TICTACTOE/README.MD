# 🎮 Tic Tac Toe – Math-Based Implementations

This repository contains **two unique implementations of Tic Tac Toe** using mathematical tricks instead of traditional board checking.  
It is written in **C++** .

---
## 🔹 1. Magic Square Method

### 🧠 Logic
- A **3×3 Magic Square** is used, where every row, column, and diagonal sums to **15**:
8 1 6
3 5 7
4 9 2

- Each cell in the Tic Tac Toe board is mapped to one of these numbers.
- A player **wins if the sum of any 3 chosen numbers = 15**.
- Instead of checking rows/columns/diagonals explicitly, we just check combinations of numbers chosen by a player.

### 📌 Example
- X selects `8, 1, 6` → sum = 15 → **X wins**.
- O selects `4, 5, 6` → sum = 15? No → **Game continues**.

✅ This reduces the win-checking problem to a **subset-sum problem**.

---

## 🔹 2. Multiplication / Prime Trick Method

### 🧠 Logic
Each board state is represented by numbers:
- Empty → **2**
- X → **3**
- O → **5**

We use multiplication to detect wins:
- `3 × 3 × 3 = 27` → 3 X’s → **X wins**  
- `5 × 5 × 5 = 125` → 3 O’s → **O wins**  
- `2 × 3 × 3 = 18` → X about to win → block required  
- `2 × 5 × 5 = 50` → O about to win → play to win  

### 📌 Example
- Line: `X, X, _` → product = 18 → X close to winning → block.  
- Line: `O, O, _` → product = 50 → O close to winning → take winning move.  

✅ This avoids complex `if` conditions → just check **products**.

---




