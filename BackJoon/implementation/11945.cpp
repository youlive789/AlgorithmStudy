#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int board[10][10];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
           board[i][j] = row.at(j) - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            swap(board[i][j], board[i][m-j-1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}