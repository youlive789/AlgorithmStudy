#include <iostream>
#include <string>
using namespace std;

int board[9][9];

int printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void searchRow(int row) {
    int sum = 0;
    int zeroIndex = 0;
    int zeroCount = 0;
    for (int i = 0; i < 9; i++) {
        if (zeroCount > 1) return;
        if (board[row][i] == 0) {
            zeroCount++;
            zeroIndex = i;
        }
        sum += board[row][i];
    }
    if (zeroCount == 0) return;
    board[row][zeroIndex] = 45 - sum;
}

void searchCol(int col) {
    int sum = 0;
    int zeroIndex = 0;
    int zeroCount = 0;
    for (int i = 0; i < 9; i++) {
        if (zeroCount > 1) return;
        if (board[i][col] == 0) {
            zeroCount++;
            zeroIndex = i;
        }
        sum += board[i][col];
    }
    if (zeroCount == 0) return;
    board[zeroIndex][col] = 45 - sum;
}

void searchSquare() {

}

int main() {
    
    // 초기화
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
    
    for (int i = 0; i < 9; i++) {
        searchRow(i);
    }

    for (int i = 0; i < 9; i++) {
        searchCol(i);
    }

    cout << endl;
    printBoard();

    return 0;
}