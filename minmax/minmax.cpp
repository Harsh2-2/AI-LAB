#include <iostream>
#include <limits>
using namespace std;

const int PLAYER = -1; // Human
const int AI = +1;     // Computer

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Print board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check winner
int evaluate() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return (board[i][0] == 'O') ? +10 : -10;
        }
    }
    // Columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return (board[0][j] == 'O') ? +10 : -10;
        }
    }
    // Diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return (board[0][0] == 'O') ? +10 : -10;
    }
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return (board[0][2] == 'O') ? +10 : -10;
    }

    return 0; // No winner
}

// Check if moves left
bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

// Minimax function
int minimax(int depth, bool isMax) {
    int score = evaluate();

    // Terminal states
    if (score == 10) return score - depth;   // AI wins
    if (score == -10) return score + depth;  // Player wins
    if (!isMovesLeft()) return 0;            // Draw

    if (isMax) {
        int best = numeric_limits<int>::min();

        // Try all moves
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = max(best, minimax(depth + 1, false));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();

        // Try all moves
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = min(best, minimax(depth + 1, true));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

// Find best move for AI
pair<int,int> findBestMove() {
    int bestVal = numeric_limits<int>::min();
    pair<int,int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int moveVal = minimax(0, false);
                board[i][j] = ' ';

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main() {
    cout << "Tic Tac Toe (You: X, AI: O)\n";
    printBoard();

    while (true) {
        int row, col;
        cout << "Enter your move (row and col: 0-2 0-2): ";
        cin >> row >> col;

        if (board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[row][col] = 'X';
        printBoard();

        if (evaluate() == -10) {
            cout << "You win!\n";
            break;
        }
        if (!isMovesLeft()) {
            cout << "It's a draw!\n";
            break;
        }

        cout << "AI is making a move...\n";
        pair<int,int> aiMove = findBestMove();
        board[aiMove.first][aiMove.second] = 'O';
        printBoard();

        if (evaluate() == 10) {
            cout << "AI wins!\n";
            break;
        }
        if (!isMovesLeft()) {
            cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}

