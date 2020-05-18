#include <iostream>
using namespace std;

int row[9];
int col[9];
int square[9];
int grid[9][9];

void checkSquare() {
    int idx = 0;
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (grid[i][j] == 0) square[idx]++;
            if (grid[i][j+1] == 0) square[idx]++;
            if (grid[i][j+2] == 0) square[idx]++;
            if (grid[i+1][j] == 0) square[idx]++;
            if (grid[i+1][j+1] == 0) square[idx]++;
            if (grid[i+1][j+2] == 0) square[idx]++;
            if (grid[i+2][j] == 0) square[idx]++;
            if (grid[i+2][j+1] == 0) square[idx]++;
            if (grid[i+2][j+2] == 0) square[idx]++;
            idx++;
        }
    }
}

void sudoku() {
    // 기저사례: row, col, square 모두 0이면 종료
    if (done()) {
        return;
    }

    for (int idx = 0; idx < 9; idx++) {
        if (row[idx] == 1) {
            // 채우기
            sudoku();
        }

        if (col[idx] == 1) {
            // 채우기
            sudoku();
        }

        if (square[idx] == 1) {
            // 채우기
            sudoku();
        }
    }
}

int main() {
    
    for (int i = 0; i < 9; i++) {
        int cntRowZero = 0;
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            grid[i][j] = tmp;
            if (tmp == 0) {
                cntRowZero++;
                col[j]++;
            }
        }
        row[i] = cntRowZero;
    }

    checkSquare();


    return 0;
}