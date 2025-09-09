# 🎮 Tic Tac Toe with Minimax Algorithm (C++)

This is a **Tic Tac Toe game in C++** where you (the human) play against an **unbeatable AI**.  
The AI uses the **Minimax algorithm** from game theory to always make the best possible move.  

---

## 📌 Features
- Human (`X`) vs AI (`O`)
- AI is **unbeatable** (at best, you can draw)
- Detects wins, losses, and draws
- Simple console-based interface

---

## 🧠 Minimax Algorithm (Quick Explanation)
The **Minimax algorithm** explores all possible future moves in the game and assigns a score:
- `+10` → AI win  
- `-10` → Player win  
- `0` → Draw  

The AI assumes:
- It plays as the **maximizer** (trying to maximize its score)
- The human plays as the **minimizer** (trying to minimize the AI’s score)

By recursively simulating moves, the AI guarantees the best outcome.

---


