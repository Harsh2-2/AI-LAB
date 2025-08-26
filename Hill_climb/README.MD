# 8-Puzzle Solver using Hill Climbing (C++)

This project is a simple implementation of the **8-puzzle problem** solved using the **Hill Climbing algorithm** with the **Manhattan Distance heuristic**.

---

## 📌 Problem Statement
The **8-puzzle** consists of a 3x3 grid with 8 numbered tiles and one blank space (0).  
The goal is to move tiles until they match the final configuration which should be in order:

1 2 3
4 5 6
7 8 0


---

## ⚙️ Algorithm Used
- **Hill Climbing** (a local search algorithm)
- **Heuristic:** Manhattan Distance  
- The algorithm generates all possible child states by sliding the blank tile and chooses the one with the **lowest heuristic value**.

---


