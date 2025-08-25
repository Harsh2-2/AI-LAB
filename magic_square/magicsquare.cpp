#include <iostream>
using namespace std;

void generateOdd(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    int i = 0, j = n / 2; 

    for (int num = 1; num <= n * n; num++) {
        square[i][j] = num;
        i--; j++; 

        if (num % n == 0) { 
            i += 2; j--; 
        } else {
            if (i < 0) i = n - 1; 
            if (j == n) j = 0;    
        }
    }

    cout << "Magic Square of size " << n << ":\n";
    for (auto &row : square) {
        for (int x : row) cout << setw(3) << x << " ";
        cout << "\n";
    }
    cout << "Magic constant = " << n * (n * n + 1) / 2 << "\n";
}

void generateDoublyEven(int n) {
    vector<vector<int>> square(n, vector<int>(n));
    int num = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = num++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3)) {
                square[i][j] = n * n + 1 - square[i][j];
            }
        }
    }

    cout << "Magic Square of size " << n << ":\n";
    for (auto &row : square) {
        for (int x : row) cout << setw(3) << x << " ";
        cout << "\n";
    }
    cout << "Magic constant = " << n * (n * n + 1) / 2 << "\n";
}

int main() {
    int n;
    cout << "Enter n (must be perfect square like 4, 9, 16...): ";
    cin >> n;

    int m = sqrt(n);
    if (m * m != n) {
        cout << "No, n must be a perfect square!\n";
        return 0;
    }

    if (m % 2 == 1) {
        generateOdd(m);            
    } else if (m % 4 == 0) {
        generateDoublyEven(m);    
    } else {
        cout << "NO,  Singly even size (like 6x6, 10x10) not supported in this simple version.\n";
    }
    return 0;
}
