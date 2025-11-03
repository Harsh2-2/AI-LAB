#include <bits/stdc++.h>
using namespace std;

const int BOARD_SIZE = 8;

struct Move {
    int startX, startY, endX, endY;
};

struct Piece {
    char type;  // 'P', 'R', 'N', 'B', 'Q', 'K'
    char color; // 'W' or 'B'
};

Piece board[BOARD_SIZE][BOARD_SIZE];

// Initialize standard chess setup
void initBoard() {
    string backRow = "RNBQKBNR";
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[0][i] = { backRow[i], 'B' };
        board[1][i] = { 'P', 'B' };
        board[6][i] = { 'P', 'W' };
        board[7][i] = { backRow[i], 'W' };
    }
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = { ' ', ' ' };
}

// Display the board
void printBoard() {
    cout << "\n   a b c d e f g h\n";
    cout << "  -----------------\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << 8 - i << "| ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == ' ')
                cout << ". ";
            else
                cout << board[i][j].type << " ";
        }
        cout << "| " << 8 - i << "\n";
    }
    cout << "  -----------------\n";
    cout << "   a b c d e f g h\n\n";
}

// Basic piece values for evaluation
int pieceValue(char type) {
    switch (type) {
        case 'P': return 10;
        case 'N': return 30;
        case 'B': return 30;
        case 'R': return 50;
        case 'Q': return 90;
        case 'K': return 900;
        default: return 0;
    }
}

// Evaluate the board (positive if White is better)
int evaluateBoard() {
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece p = board[i][j];
            if (p.type != ' ') {
                int val = pieceValue(p.type);
                score += (p.color == 'W' ? val : -val);
            }
        }
    }
    return score;
}

// Generate basic pseudo-legal moves (simplified)
vector<Move> generateMoves(char color) {
    vector<Move> moves;
    int dir = (color == 'W') ? -1 : 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece p = board[i][j];
            if (p.color != color) continue;

            if (p.type == 'P') {
                int ni = i + dir;
                if (ni >= 0 && ni < 8) {
                    if (board[ni][j].type == ' ')
                        moves.push_back({i, j, ni, j});
                    if (j > 0 && board[ni][j - 1].color != color && board[ni][j - 1].type != ' ')
                        moves.push_back({i, j, ni, j - 1});
                    if (j < 7 && board[ni][j + 1].color != color && board[ni][j + 1].type != ' ')
                        moves.push_back({i, j, ni, j + 1});
                }
            }

            // Add simple rook moves (for demonstration)
            if (p.type == 'R') {
                int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                for (auto &d : dirs) {
                    int x = i + d[0], y = j + d[1];
                    while (x >= 0 && y >= 0 && x < 8 && y < 8) {
                        if (board[x][y].type == ' ')
                            moves.push_back({i, j, x, y});
                        else {
                            if (board[x][y].color != color)
                                moves.push_back({i, j, x, y});
                            break;
                        }
                        x += d[0];
                        y += d[1];
                    }
                }
            }
        }
    }
    return moves;
}

// Make and undo move
Piece makeMove(Move m) {
    Piece captured = board[m.endX][m.endY];
    board[m.endX][m.endY] = board[m.startX][m.startY];
    board[m.startX][m.startY] = {' ', ' '};
    return captured;
}

void undoMove(Move m, Piece captured) {
    board[m.startX][m.startY] = board[m.endX][m.endY];
    board[m.endX][m.endY] = captured;
}

// Minimax with alpha-beta pruning
int minimax(int depth, bool maximizingPlayer, int alpha, int beta) {
    if (depth == 0) return evaluateBoard();

    char color = maximizingPlayer ? 'W' : 'B';
    vector<Move> moves = generateMoves(color);

    if (moves.empty()) return evaluateBoard();

    int best = maximizingPlayer ? INT_MIN : INT_MAX;

    for (auto &m : moves) {
        Piece captured = makeMove(m);
        int eval = minimax(depth - 1, !maximizingPlayer, alpha, beta);
        undoMove(m, captured);

        if (maximizingPlayer) {
            best = max(best, eval);
            alpha = max(alpha, eval);
        } else {
            best = min(best, eval);
            beta = min(beta, eval);
        }

        if (beta <= alpha) break;
    }

    return best;
}

Move findBestMove(char color) {
    vector<Move> moves = generateMoves(color);
    Move bestMove;
    int bestVal = (color == 'W') ? INT_MIN : INT_MAX;

    for (auto &m : moves) {
        Piece captured = makeMove(m);
        int boardVal = minimax(3, color == 'B', INT_MIN, INT_MAX);
        undoMove(m, captured);

        if ((color == 'W' && boardVal > bestVal) || (color == 'B' && boardVal < bestVal)) {
            bestVal = boardVal;
            bestMove = m;
        }
    }
    return bestMove;
}

// Convert chess notation (e.g., e2e4) into Move
bool parseMove(string input, Move &m) {
    if (input.size() != 4) return false;
    m.startY = input[0] - 'a';
    m.startX = 8 - (input[1] - '0');
    m.endY = input[2] - 'a';
    m.endX = 8 - (input[3] - '0');
    return (m.startX >= 0 && m.startX < 8 && m.startY >= 0 && m.startY < 8 &&
            m.endX >= 0 && m.endX < 8 && m.endY >= 0 && m.endY < 8);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initBoard();
    printBoard();

    while (true) {
        cout << "Enter your move (e.g., e2e4): ";
        string input;
        cin >> input;
        Move userMove;
        if (!parseMove(input, userMove)) {
            cout << "Invalid input format!\n";
            continue;
        }
        makeMove(userMove);
        printBoard();

        cout << "AI is thinking...\n";
        Move aiMove = findBestMove('B');
        makeMove(aiMove);
        printBoard();
    }

    return 0;
}
