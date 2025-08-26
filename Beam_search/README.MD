# Beam Search Pathfinding in C++

This project demonstrates **Beam Search** applied to a simple maze/pathfinding problem.  
It uses a grid map with walls, free paths, and a start/destination.

---

## Features
- Beam Search implementation in **C++**
- Uses **Manhattan distance** as the heuristic
- Console-based visualization:
  - 🟥 Red → Destination
  - 🟩 Green → Visited path
  - ⬜ White → Walls
  - ⬛ Black → Free path

---
1 = Wall
0 = Free path

## Example Map
{1,1,1,1,1,1,1,1,1},
{1,0,1,0,0,0,0,0,1},
{1,0,1,0,1,0,1,0,1},
{1,0,0,0,1,0,1,0,1},
{1,0,1,0,0,0,1,0,1},
{1,0,1,1,0,1,0,0,1},
{1,1,1,1,0,0,0,1,1},
{1,0,0,0,0,1,0,0,1},
{1,1,1,1,1,1,1,1,1}

## GOAL

Start → `(1,1)`  
Destination → `(7,7)`



