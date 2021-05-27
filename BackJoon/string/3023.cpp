#include <iostream>

using namespace std;

char card[100][100];

int main() {

    int rows, cols;
    cin >> rows >> cols;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            char tmp;
            cin >> tmp;
            card[row][col] = tmp;
            card[row][2*cols - col - 1] = tmp;
            card[2*rows - row - 1][col] = tmp;
            card[2*rows - row - 1][2*cols - col - 1] = tmp;
        }
    }

    int targetRow, targetCol;
    cin >> targetRow >> targetCol;

    if (card[targetRow-1][targetCol-1] == '#') {
        card[targetRow-1][targetCol-1] = '.';
    }
    else {
        card[targetRow-1][targetCol-1] = '#';
    }

    for (int row = 0; row < 2*rows; ++row) {
        for (int col = 0; col < 2*cols; ++col) {
            cout << card[row][col];
        }
        cout << "\n";
    }

    return 0;
}