# A* Search Algorithm in C++

This project implements the **A* Search Algorithm** for finding the shortest path in a 2D grid with obstacles.  

The map is represented as a matrix:
- `1` → Wall/Obstacle  
- `0` → Open path  
- `2` → Visited path (visualization)  
- Destination cell is highlighted in **red**  

The algorithm uses the cost function:

f(n) = g(n) + h(n)


Where:
- `g(n)` = cost from start to current node  
- `h(n)` = heuristic (Manhattan distance)  

---

## 🚀 Features
- Grid visualization in terminal using ANSI colors.
- Obstacles and paths clearly shown.
- A* search to find the optimal path.
- Simple and beginner-friendly C++ implementation.

---

