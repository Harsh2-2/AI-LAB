# 🎮 Tic Tac Toe with Alpha-Beta Pruning (C++)

This is a **Tic Tac Toe game in C++** where a human (`X`) plays against an **AI (`O`)** that uses the **Alpha-Beta Pruning algorithm**.  
The AI is **unbeatable** and plays optimally while being more efficient than the plain Minimax approach.  

---

## 📌 Features
- Human (`X`) vs AI (`O`)
- AI never loses (at best, you can draw)
- Uses **Alpha-Beta Pruning** for efficiency
- Detects wins, losses, and draws
- Console-based game interface

---

## 🧠 Alpha-Beta Pruning (Quick Explanation)
Alpha-Beta Pruning is an optimization of the **Minimax algorithm**.  
It eliminates branches in the game tree that don’t affect the final decision, making the AI faster.  

- **Alpha (α):** The best already explored option along the path for the maximizer (AI).  
- **Beta (β):** The best already explored option along the path for the minimizer (Human).  
- If at any point `α >= β`, further exploration of that branch is **pruned** (ignored).  

This ensures the AI evaluates fewer states but still finds the **optimal move**.

---

