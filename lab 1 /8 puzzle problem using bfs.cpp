from heapq import heappush, heappop

# ---------- Problem setup ----------
GOAL = (1,2,3,
        4,5,6,
        7,8,0)  # 0 = blank

moves = {
    0: [('R',1), ('D',3)],
    1: [('L',0), ('R',2), ('D',4)],
    2: [('L',1), ('D',5)],
    3: [('U',0), ('R',4), ('D',6)],
    4: [('U',1), ('L',3), ('R',5), ('D',7)],
    5: [('U',2), ('L',4), ('D',8)],
    6: [('U',3), ('R',7)],
    7: [('U',4), ('L',6), ('R',8)],
    8: [('U',5), ('L',7)],
}

def is_solvable(state):
    """For 3x3: solvable iff inversion count is even."""
    arr = [x for x in state if x != 0]
    inv = 0
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if arr[i] > arr[j]:
                inv += 1
    return inv % 2 == 0

# ---------- Manhattan Distance Heuristic ----------
def h_manhattan(state):
    goal_pos = {v: (i//3, i%3) for i, v in enumerate(GOAL)}
    total = 0
    for i, v in enumerate(state):
        if v == 0: 
            continue
        r, c = i//3, i%3
        gr, gc = goal_pos[v]
        total += abs(r - gr) + abs(c - gc)
    return total

# ---------- Best-First Search (Greedy: f = h) ----------
def best_first_search(start):
    if isinstance(start, list):
        start = tuple(start)
    if not is_solvable(start):
        return None, {"expanded": 0, "message": "Unsolvable puzzle"}

    frontier = []
    tie = 0
    heappush(frontier, (h_manhattan(start), tie, start))
    came_from = {start: (None, None)}  # state -> (parent_state, move)
    visited = set()

    expanded = 0
    while frontier:
        _, _, state = heappop(frontier)
        if state in visited:
            continue
        visited.add(state)
        expanded += 1

        if state == GOAL:
            # reconstruct path
            path = []
            cur = state
            while came_from[cur][0] is not None:
                parent, mv = came_from[cur]
                path.append(mv)
                cur = parent
            path.reverse()
            return path, {"expanded": expanded, "depth": len(path), "message": "Solved"}

        zero = state.index(0)
        for mv, nxt_idx in moves[zero]:
            new_state = list(state)
            new_state[zero], new_state[nxt_idx] = new_state[nxt_idx], new_state[zero]
            new_state = tuple(new_state)
            if new_state in came_from:
                continue
            came_from[new_state] = (state, mv)
            tie += 1
            heappush(frontier, (h_manhattan(new_state), tie, new_state))

    return None, {"expanded": expanded, "message": "No solution found"}

# ---------- Helpers ----------
def pretty(state):
    for r in range(3):
        print(' '.join(str(x) if x != 0 else '·' for x in state[r*3:(r+1)*3]))
    print()

def apply_moves(state, moves_seq):
    s = list(state)
    for mv in moves_seq:
        zero = s.index(0)
        for cand_mv, idx in moves[zero]:
            if cand_mv == mv:
                s[zero], s[idx] = s[idx], s[zero]
                break
    return tuple(s)

# ---------- Example run ----------
if __name__ == "__main__":
    start = (1, 2, 3,
             4, 0, 6,
             7, 5, 8)

    print("Start state:")
    pretty(start)

    path, info = best_first_search(start)
    print(info)
    if path:
        print("Moves:", ''.join(path))
        end_state = apply_moves(start, path)
        print("\nGoal state:")
        pretty(end_state)
