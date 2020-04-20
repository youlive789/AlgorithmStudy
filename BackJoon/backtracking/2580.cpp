#include <iostream>
#include <string>
using namespace std;

int board[9][9];

void printBoard() {
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            int row = i * 3;
            int col = j * 3;
            if (board[row+1][col+1] == 0) {
                sum += board[row][col];
                sum += board[row][col+1];
                sum += board[row][col+2];
                sum += board[row+1][col];
                sum += board[row+1][col+2];
                sum += board[row+2][col];
                sum += board[row+2][col+1];
                sum += board[row+2][col+2];
                board[row+1][col+1] = 45 - sum;
            }
        }
    }
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
    
    searchSquare();

    for (int i = 0; i < 9; i++) {
        searchRow(i);
    }

    for (int i = 0; i < 9; i++) {
        searchCol(i);
    }

    printBoard();

    return 0;
}