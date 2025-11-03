# 2D Chess Game using Pygame and Alpha-Beta Pruning

## Aim
To implement a 2D Chess Game in Python using Pygame for graphical interaction and Alpha-Beta Pruning as the AI decision-making algorithm, allowing a human player to compete against an intelligent computer opponent.

---

## Introduction
Chess is one of the most well-known strategy games, involving two players competing on an 8×8 board. Each player aims to checkmate the opponent’s king through a sequence of strategic moves.

In this project, we combine game development and artificial intelligence by implementing a playable chess interface where:

- The human player makes moves using a mouse-controlled GUI.
- The AI opponent determines optimal moves using Game Tree Search (Minimax with Alpha-Beta Pruning).

This implementation demonstrates how classical AI algorithms can be applied to real-time decision-making in games.

---

## Algorithm

### 1. Board Representation
The chessboard is represented as an 8×8 grid (2D array):

- Each cell stores either `None` or a `Piece` object.  
- The `Piece` class contains:
  - `type` → Type of the piece (`Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, `King`)
  - `color` → `'White'` or `'Black'`
  - `position` → Tuple `(x, y)` representing coordinates on the board

Example:
```
board[y][x] = Piece(type='Knight', color='White', position=(x, y))
```

This structure allows fast lookup, modification, and validation of moves.

---

### 2. Move Generation
Each chess piece has its own movement pattern.  
When a player selects a piece, the program:

1. Identifies the piece type.  
2. Generates all possible legal moves following chess rules.  
3. Filters out moves that:
   - Go outside the board limits.  
   - Land on a friendly piece.  
   - Result in a self-check.

This creates a move set for each piece that can be used by both the human player and the AI engine.

---

### 3. Human Interaction
The player interacts using mouse clicks:

- First click: Selects a piece.  
- All valid moves are highlighted visually.  
- Second click: Selects a target square.

If valid, the move executes and the board updates.

**Features:**

- Move highlighting  
- Capture indication  
- Visual feedback for check/checkmate  
- Buttons for Restart, Undo, or Forfeit  

All graphical updates are handled through Pygame surfaces.

---

### 4. AI Opponent — Alpha-Beta Pruning

#### Concept
The AI uses the Minimax Algorithm enhanced by Alpha-Beta Pruning to efficiently choose the best possible move.  
Minimax explores all future moves up to a certain depth, assuming both players play optimally.

#### Evaluation Function
Each board position is scored using a heuristic evaluation, based on piece values and positional factors.

**Piece Value Table:**

| Piece   | Value   |
|----------|----------|
| Pawn     | 1        |
| Knight/Bishop | 3  |
| Rook     | 5        |
| Queen    | 9        |
| King     | ∞ (or very high) |

**Other Factors:**

- Positional Advantage: Bonus for central control and mobility.  
- Mobility: Number of available legal moves.  
- King Safety: Penalty if the king is exposed.

#### Steps in Alpha-Beta Pruning
1. The AI generates all legal moves for its color.  
2. For each move, it simulates the opponent’s possible responses recursively.  

Define:

- Alpha (α): Best value the maximizer (AI) can guarantee.  
- Beta (β): Best value the minimizer (Human) can guarantee.  

During recursion:

- If α ≥ β, further exploration of that branch is cut off (pruned).  

This significantly reduces the number of states evaluated.

**Result:**  
The AI chooses the move that maximizes its minimum gain, ensuring the best possible outcome even against optimal play.

---

### 5. Game States

Different states are maintained during gameplay:

| State      | Description |
|-------------|-------------|
| Normal      | The game is ongoing. |
| Check       | The King is under direct threat. |
| Checkmate   | The King has no legal escape (game over). |
| Stalemate   | No legal moves, but the King is not in check (draw). |
| Forfeit     | The human player can end the game manually. |

These states are continuously evaluated after every move.

---

### Time Complexity
The time complexity of AI decision-making depends on the branching factor (b) and depth (d) of the search tree:

- Without pruning: \( O(b^d) \)
- With Alpha-Beta Pruning: approximately \( O(b^{(d/2)}) \) in the best case

For chess:

- Average branching factor \( b ≈ 35 \)
- Typical search depth \( d = 3–4 \)

Alpha-Beta pruning drastically reduces computational cost while maintaining decision accuracy.

Note: Human moves are processed instantly since they involve direct validation, not search.

---

## Conclusion
The implementation of a 2D Chess Game using Pygame and Alpha-Beta Pruning successfully combines fundamental concepts of game theory, heuristic search, and AI-based decision-making.

The project demonstrates:

- Use of object-oriented design for board and piece management.  
- Integration of heuristic evaluation functions in AI.  
- Optimization of Minimax search via Alpha-Beta pruning.

Future enhancements could include:

- Adaptive difficulty based on player performance.  
- Move prediction visualization.  
- Multiplayer and online support.
```
