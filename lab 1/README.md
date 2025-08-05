# 8-Puzzle Solver using DFS and BFS

This project implements a solution to the classic **8-puzzle problem** using **Depth-First Search (DFS)** and **Breadth-First Search (BFS)** algorithms in C++. The 8-puzzle is a sliding puzzle that consists of a 3×3 grid with 8 numbered tiles and one empty space. The goal is to move the tiles around until they match the desired final configuration.

## Problem Statement

Given an initial state of the 8-puzzle, the objective is to transform it into the goal state using a series of legal moves (up, down, left, right) where the empty tile (represented by `0`) can slide into adjacent positions. This implementation checks whether the goal can be reached from the initial configuration using **DFS** traversal techniques.

---

##  Features

- Solves the 8-puzzle using:
  - **Depth-First Search (DFS)**
- Custom state representation using 2D array
- Dynamic move generation (Up, Down, Left, Right)
- Tracks explored nodes using a closed list
- Simple and readable implementation

---

##  Implementation Details

### Programming Language

- C++

### Data Structures Used

- `array` are used for matrix representation of the puzzle
- `set and string` are used to prevent revisiting states

### Functions

- `serialize()` — keeps track of the already visited state
- `isGoal()` — Checks if the current state is in the solution state 
- `printBoard()` — prints the current state of the board
- `dfs()` — This function is used to make the move by recursively calling of itself and backtrack in the process


---

