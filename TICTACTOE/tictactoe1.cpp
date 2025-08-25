// tic_tac_toe_magic_square.cpp
#include <iostream>
#include <vector>
using namespace std;


char boardx[10]; // 'X', 'O', or ' '

// Lo Shu magic square mapping (1..9)
//  1  2  3   ->   8 1 6
//  4  5  6        3 5 7
//  7  8  9        4 9 2
int magicVal[10] = {-1, 8,1,6, 3,5,7, 4,9,2};

void initBoard() {
    for (int i = 1; i <= 9; i++) boardx[i] = ' ';
}

void showBoard() {
    cout << "\n";
    for (int i = 1; i <= 9; i++) {
        cout << " " << boardx[i] << " ";
        if (i % 3 != 0) cout << "|";
        if (i % 3 == 0 && i != 9) cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

// collect magic numbers of the squares owned by player ch
vector<int> ownedMagic(char ch) {
    vector<int> a;
    for (int i = 1; i <= 9; i++) {
        if (boardx[i] == ch) a.push_back(magicVal[i]);
    }
    return a;
}

// magic-square win check: any 3 of player's magic numbers sum to 15
bool someoneWon(char ch) {
    vector<int> a = ownedMagic(ch);
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if (a[i] + a[j] + a[k] == 15) return true;
            }
        }
    }
    return false;
}

bool movesLeft() {
    for (int i = 1; i <= 9; i++) if (boardx[i] == ' ') return true;
    return false;
}

// super simple input (student style), minimal validation
void humanMove() {
    int pos;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> pos;
        if (pos >= 1 && pos <= 9 && boardx[pos] == ' ') {
            boardx[pos] = 'X';
            break;
        } else {
            cout << "Invalid. Try again.\n";
        }
    }
}

// helper: try a move and see if it wins (uses magic-square win check)
int canWin(char ch) {
    for (int i = 1; i <= 9; i++) {
        if (boardx[i] == ' ') {
            boardx[i] = ch;
            bool ok = someoneWon(ch);
            boardx[i] = ' ';
            if (ok) return i;
        }
    }
    return 0;
}


void aiMove() {
    // try to win
    int mv = canWin('O');
    if (mv) { boardx[mv] = 'O'; return; }

    // block human
    mv = canWin('X');
    if (mv) { boardx[mv] = 'O'; return; }

    // center
    if (boardx[5] == ' ') { boardx[5] = 'O'; return; }

    // corners
    int corners[4] = {1,3,7,9};
    for (int c = 0; c < 4; c++) {
        if (boardx[corners[c]] == ' ') { boardx[corners[c]] = 'O'; return; }
    }

    // sides
    int sides[4] = {2,4,6,8};
    for (int s = 0; s < 4; s++) {
        if (boardx[sides[s]] == ' ') { boardx[sides[s]] = 'O'; return; }
    }
}

int main() {
    cout << "Tic Tac Toe (Magic Square version)\n";
    cout << "You are X, Computer is O\n";
    initBoard();
    showBoard();

    // simple loop: human -> AI -> check each time
    while (true) {
        // human
        humanMove();
        showBoard();
        if (someoneWon('X')) { cout << "You win!\n"; break; }
        if (!movesLeft()) { cout << "Draw!\n"; break; }

        // ai
        cout << "Computer is thinking...\n";
        aiMove();
        showBoard();
        if (someoneWon('O')) { cout << "Computer wins!\n"; break; }
        if (!movesLeft()) { cout << "Draw!\n"; break; }
    }

   
    cout << "Game over.\n";
    return 0;
}
