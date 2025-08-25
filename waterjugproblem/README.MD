# Water Jug Problem Solver

## 📌 Description
This project solves the **Water Jug Problem**, a classic puzzle in Artificial Intelligence and Algorithms.  
The problem states:  
> Given two jugs with capacities **X** and **Y**, and a target amount **Z**, find a sequence of steps to measure exactly **Z liters** of water.

---

## 🧮 Mathematical Foundation
The solvability of the problem is based on a theorem in **Number Theory**:

- The target amount **Z** can be measured **iff**:
  1. `Z <= max(X, Y)`  
  2. `Z` is a multiple of `gcd(X, Y)`  

This follows from **Bézout’s Identity**:  
For any two integers `X` and `Y`, there exist integers `m` and `n` such that:  


Thus, any multiple of `gcd(X, Y)` can be represented using combinations of `X` and `Y`.  
If `Z` is such a multiple, the water jug problem has a solution.


## ⚙️ Simulation Strategy
The program uses a **greedy simulation** to actually generate the steps:

1. **Fill A**: If Jug A is empty, fill it to capacity.  
2. **Empty B**: If Jug B is full, empty it.  
3. **Pour A → B**: Transfer water from Jug A to Jug B until either Jug A is empty or Jug B is full.  

These three actions are repeated until either jug contains exactly **Z liters**.

This simulation demonstrates the practical process of reaching the target amount, not just proving its existence.

---

## 🚀 How to Run
### Compile
```bash
g++ water_jug.cpp -o water_jug
