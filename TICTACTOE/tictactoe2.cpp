#include <iostream>
using namespace std;

int board[10]; // 1..9 cells
// mapping for display
char disp(int v) {
    if (v == 2) return ' ';
    if (v == 3) return 'X';
    if (v == 5) return 'O';
    return '?';
}

void initBoard() {
    for (int i = 1; i <= 9; i++) board[i] = 2; // all blanks
}

void showBoard() {
    cout << "\n";
    for (int i = 1; i <= 9; i++) {
        cout << " " << disp(board[i]) << " ";
        if (i % 3 != 0) cout << "|";
        if (i % 3 == 0 && i != 9) cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

// all possible winning lines
int lines[8][3] = {
    {1,2,3}, {4,5,6}, {7,8,9}, // rows
    {1,4,7}, {2,5,8}, {3,6,9}, // cols
    {1,5,9}, {3,5,7}           // diagonals
};

// check winner using products
int checkWin() {
    for (int i = 0; i < 8; i++) {
        int a = board[lines[i][0]];
        int b = board[lines[i][1]];
        int c = board[lines[i][2]];
        int prod = a * b * c;
        if (prod == 27) return 3; // X wins
        if (prod == 125) return 5; // O wins
    }
    return 0;
}

bool movesLeft() {
    for (int i = 1; i <= 9; i++) if (board[i] == 2) return true;
    return false;
}

void humanMove() {
    int pos;
    while (true) {
        cout << "Enter position (1-9): ";
        cin >> pos;
        if (pos >= 1 && pos <= 9 && board[pos] == 2) {
            board[pos] = 3;
            break;
        } else {
            cout << "Invalid. Try again.\n";
        }
    }
}

// find a move to win/block by checking products
int findSpot(int targetProd, int playerVal) {
    for (int i = 0; i < 8; i++) {
        int a = lines[i][0], b = lines[i][1], c = lines[i][2];
        int prod = board[a]*board[b]*board[c];
        if (prod == targetProd) {
            if (board[a] == 2) return a;
            if (board[b] == 2) return b;
            if (board[c] == 2) return c;
        }
    }
    return 0;
}

void aiMove() {
    // 1) win if possible
    int pos = findSpot(50, 5); // 2*5*5
    if (pos) { board[pos] = 5; return; }

    // 2) block X
    pos = findSpot(18, 3); // 2*3*3
    if (pos) { board[pos] = 5; return; }

    // 3) take center
    if (board[5] == 2) { board[5] = 5; return; }

    // 4) take first empty 
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 2) { board[i] = 5; return; }
    }
}

int main() {
    cout << "Tic Tac Toe (Multiplication Trick)\n";
    cout << "You = X , Computer = O\n";
    initBoard();
    showBoard();

    while (true) {
        humanMove();
        showBoard();
        if (checkWin() == 3) { cout << "You win!\n"; break; }
        if (!movesLeft()) { cout << "Draw!\n"; break; }

        cout << "Computer plays...\n";
        aiMove();
        showBoard();
        if (checkWin() == 5) { cout << "Computer wins!\n"; break; }
        if (!movesLeft()) { cout << "Draw!\n"; break; }
    }

    cout << "Game over.\n";
    return 0;
}
