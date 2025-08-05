# 8-Puzzle Solver using DFS and BFS

This project implements a solution to the classic **8-puzzle problem** using **Depth-First Search (DFS)** and **Breadth-First Search (BFS)** algorithms in C++. The 8-puzzle is a sliding puzzle that consists of a 3×3 grid with 8 numbered tiles and one empty space. The goal is to move the tiles around until they match the desired final configuration.

## Problem Statement

Given an initial state of the 8-puzzle, the objective is to transform it into the goal state using a series of legal moves (up, down, left, right) where the empty tile (represented by `0`) can slide into adjacent positions. This implementation checks whether the goal can be reached from the initial configuration using **DFS** and **BFS** traversal techniques.

---

##  Features

- Solves the 8-puzzle using:
  - **Depth-First Search (DFS)**
  - **Breadth-First Search (BFS)**
- Custom state representation using 2D vectors
- Dynamic move generation (Up, Down, Left, Right)
- Tracks explored nodes using a closed list
- Simple and readable implementation

---

##  Implementation Details

### Programming Language

- C++

### Data Structures Used

- `std::vector` for matrix representation of the puzzle
- `std::stack` for DFS
- `std::queue` for BFS
- `std::vector` as a closed list to prevent revisiting states

### Functions

- `printNode(matrix node)` — Prints the current state of the puzzle
- `checkSame(matrix a, matrix b)` — Compares two puzzle states
- `move()` — Moves the blank tile to a new position
- `findZero()` — Locates the position of the blank tile
- `genChildren()` — Generates all valid children states from a current state
- `presentInClosedList()` — Checks if a state has already been visited
- `DFS()` — Runs Depth-First Search
- `BFS()` — Runs Breadth-First Search

---

