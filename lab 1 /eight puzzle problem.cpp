#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

const int N = 3;
set<string> visited;

int goal[N][N] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Serialize board state into a string
string serialize(int board[N][N]) {
    string s = "";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            s += to_string(board[i][j]);
    return s;
}

// Check if the current state is the goal
bool isGoal(int board[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] != goal[i][j])
                return false;
    return true;
}

// Print current state
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
}

// Recursive DFS
void dfs(int board[N][N], int i_blank, int j_blank) {
    string state = serialize(board);
    if (visited.count(state)) return;

    visited.insert(state);

    if (isGoal(board)) {
        cout << "Goal Reached:\n";
        printBoard(board);
        return;
    }

    // Move Up
    if (i_blank - 1 >= 0) {
        swap(board[i_blank][j_blank], board[i_blank - 1][j_blank]);
        dfs(board, i_blank - 1, j_blank);
        swap(board[i_blank][j_blank], board[i_blank - 1][j_blank]);  // backtrack
    }

    // Move Down
    if (i_blank + 1 < N) {
        swap(board[i_blank][j_blank], board[i_blank + 1][j_blank]);
        dfs(board, i_blank + 1, j_blank);
        swap(board[i_blank][j_blank], board[i_blank + 1][j_blank]);  // backtrack
    }

    // Move Left
    if (j_blank - 1 >= 0) {
        swap(board[i_blank][j_blank], board[i_blank][j_blank - 1]);
        dfs(board, i_blank, j_blank - 1);
        swap(board[i_blank][j_blank], board[i_blank][j_blank - 1]);  // backtrack
    }

    // Move Right
    if (j_blank + 1 < N) {
        swap(board[i_blank][j_blank], board[i_blank][j_blank + 1]);
        dfs(board, i_blank, j_blank + 1);
        swap(board[i_blank][j_blank], board[i_blank][j_blank + 1]);  // backtrack
    }
}

int main() {
    int board[N][N];
    int i_blank = 0, j_blank = 0;

    cout << "Enter the 3x3 board (use 0 for the blank space):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                i_blank = i;
                j_blank = j;
            }
        }
    }

    dfs(board, i_blank, j_blank);

    return 0;
}
