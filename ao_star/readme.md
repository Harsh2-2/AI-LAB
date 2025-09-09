# 🎮 Tic Tac Toe with AO* Algorithm (C++)

This is an **experimental Tic Tac Toe game in C++** that applies the **AO* search algorithm** (AND-OR graph search) for decision-making.  
Unlike Minimax or Alpha-Beta pruning, which are standard for adversarial games, AO* is typically used in **problem-solving with AND-OR graphs** (like planning, diagnosis, or task decomposition).  
Here, we adapt AO* to Tic Tac Toe for educational purposes.  

---

## 📌 Features
- Human (`X`) vs AI (`O`)
- AI explores the game state space using **AO***  
- Demonstrates the use of **AND-OR graph search** in a game scenario
- Detects wins, losses, and draws
- Console-based interface

---

## 🧠 AO* Algorithm (Quick Explanation)
AO* (AND-OR Star) search is a **best-first search algorithm** designed for problems that can be modeled as **AND-OR graphs**:
- **OR nodes**: A choice between different actions (like a player’s move in Tic Tac Toe).  
- **AND nodes**: Multiple conditions must hold together to reach a solution (like all opponent responses to a move).  

AO* recursively updates node costs and expands the most promising nodes until a solution graph (optimal strategy) is found.  

In this Tic Tac Toe implementation:
- Each board state = a node in the AND-OR graph.  
- Player’s move = OR node (choosing one move).  
- Opponent’s possible responses = AND nodes (all must be considered).  

---


