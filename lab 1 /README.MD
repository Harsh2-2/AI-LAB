
**Aim:**  
To implement and compare Depth First Search (DFS) and Breadth First Search (BFS) algorithms for solving the 8-puzzle problem.

---

## Theory  
The **8-Puzzle Problem** is a sliding puzzle consisting of a 3×3 grid with 8 numbered tiles and one empty space.  
The objective is to reach the goal state from a given initial state by sliding the tiles into the empty space.

Two classical search strategies can be used to solve this problem:

### Breadth First Search (BFS)  
- Explores all the nodes at the present depth level before moving on to nodes at the next depth level.  
- Guarantees the shortest path solution if one exists.  
- Uses a **queue (FIFO)** data structure.  

### Depth First Search (DFS)  
- Explores as far as possible along each branch before backtracking.  
- Does **not** guarantee the shortest solution.  
- Uses a **stack (LIFO)** or recursion.  

---

## Algorithm  

### BFS for 8-Puzzle  
1. Start with the initial state and insert it into a queue.  
2. Repeat until the queue is empty:  
   a. Remove the front node from the queue.  
   b. If it is the goal state, return success.  
   c. Otherwise, generate all valid child states by moving the blank space.  
   d. Insert the child states into the queue if they are not already visited.  

### DFS for 8-Puzzle  
1. Start with the initial state and insert it into a stack (or recursion).  
2. Repeat until the stack is empty:  
   a. Pop the top node from the stack.  
   b. If it is the goal state, return success.  
   c. Otherwise, generate all valid child states by moving the blank space.  
   d. Push the child states into the stack if they are not already visited.  

---

## Time and Space Complexity  

### BFS  
- **Time Complexity:** O(b^d)  
  - b = branching factor (average number of child nodes per state, ~2–4 in 8-puzzle)  
  - d = depth of the shallowest solution  
- **Space Complexity:** O(b^d) (stores all nodes in memory).  

### DFS  
- **Time Complexity:** O(b^m)  
  - m = maximum depth of the search tree  
- **Space Complexity:** O(b × m) (stores only one path with its siblings).  

---

## Conclusion  
- **BFS** always finds the shortest solution but requires high memory and time as the depth increases.  
- **DFS** requires less memory, but it may not find the shortest solution and can get stuck in deep paths.  
- For the **8-puzzle problem**, BFS is more reliable, while DFS is more memory efficient.  
