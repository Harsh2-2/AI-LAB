#include <iostream>
#include <limits>
#include <map>
#include <vector>
using namespace std;

struct Node {
    vector<vector<char>> state;
    int cost;   // evaluation score
    bool solved;
    vector<Node*> children;

    Node(vector<vector<char>> s) : state(s), cost(0), solved(false) {}
};

// Utility function to print the board
void printBoard(vector<vector<char>> &board) {
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

// Evaluate board state
int evaluate(vector<vector<char>> &board) {
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
bool isMovesLeft(vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

// AO* recursive procedure
int AOStar(Node* node, bool isMax) {
    int score = evaluate(node->state);

    if (score == 10 || score == -10) {
        node->cost = score;
        node->solved = true;
        return score;
    }
    if (!isMovesLeft(node->state)) {
        node->cost = 0;
        node->solved = true;
        return 0;
    }

    if (isMax) { // OR node (AI's choice)
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (node->state[i][j] == ' ') {
                    auto childState = node->state;
                    childState[i][j] = 'O';
                    Node* child = new Node(childState);
                    node->children.push_back(child);
                    int val = AOStar(child, false);
                    best = max(best, val);
                }
            }
        }
        node->cost = best;
        return best;
    } else { // AND node (Opponent’s move)
        int worst = numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (node->state[i][j] == ' ') {
                    auto childState = node->state;
                    childState[i][j] = 'X';
                    Node* child = new Node(childState);
                    node->children.push_back(child);
                    int val = AOStar(child, true);
                    worst = min(worst, val);
                }
            }
        }
        node->cost = worst;
        return worst;
    }
}

// Find best move using AO*
pair<int,int> findBestMove(vector<vector<char>> &board) {
    int bestVal = numeric_limits<int>::min();
    pair<int,int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                auto childState = board;
                childState[i][j] = 'O';
                Node* child = new Node(childState);
                int moveVal = AOStar(child, false);
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
    vector<vector<char>> board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    cout << "Tic Tac Toe (You: X, AI: O) with AO* Algorithm\n";
    printBoard(board);

    while (true) {
        int row, col;
        cout << "Enter your move (row and col: 0-2 0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = 'X';
        printBoard(board);

        if (evaluate(board) == -10) {
            cout << "You win!\n";
            break;
        }
        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }

        cout << "AI is making a move...\n";
        pair<int,int> aiMove = findBestMove(board);
        board[aiMove.first][aiMove.second] = 'O';
        printBoard(board);

        if (evaluate(board) == 10) {
            cout << "AI wins!\n";
            break;
        }
        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }
    return 0;
}
