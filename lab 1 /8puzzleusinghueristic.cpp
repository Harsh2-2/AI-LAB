import random

def magic_constant(n):
    return n * (n**2 + 1) // 2

def cost(square, n, M):
    """Heuristic cost function for a given square"""
    total_cost = 0
    # Rows
    for i in range(n):
        total_cost += abs(sum(square[i*n:(i+1)*n]) - M)
    # Columns
    for j in range(n):
        total_cost += abs(sum(square[j::n]) - M)
    # Diagonals
    total_cost += abs(sum(square[i*n + i] for i in range(n)) - M)
    total_cost += abs(sum(square[i*n + (n-i-1)] for i in range(n)) - M)
    return total_cost

def hill_climb(n, max_iters=100000):
    M = magic_constant(n)
    square = list(range(1, n*n + 1))
    random.shuffle(square)

    best = square[:]
    best_cost = cost(best, n, M)

    for _ in range(max_iters):
        # pick two positions and swap
        i, j = random.sample(range(n*n), 2)
        square[i], square[j] = square[j], square[i]

        new_cost = cost(square, n, M)
        if new_cost < best_cost:
            best = square[:]
            best_cost = new_cost
            if best_cost == 0:
                break  # Found magic square
        else:
            # Undo swap (since worse)
            square[i], square[j] = square[j], square[i]

    return best, best_cost

def print_square(square, n):
    for i in range(n):
        print(square[i*n:(i+1)*n])

# Example run
n = 3
solution, c = hill_climb(n)
print("Cost:", c)
print_square(solution, n)
