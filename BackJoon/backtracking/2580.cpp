#include <iostream>
#include <vector>

using namespace std;

int grid[9][9];
bool possible = false;
vector<pair<int,int>> list;

void save(int row, int col) {
    pair<int,int> pos = make_pair(row, col);
    list.push_back(pos);
}

bool checkRow(int num, int row) {
    for (int c = 0; c < 9; c++) {
        if (grid[row][c] == num) return false;
    }
    return true;
}

bool checkCol(int num, int col) {
    for (int r = 0; r < 9; r++) {
        if (grid[r][col] == num) return false;
    }
    return true;
}

bool checkSquare(int num, int row, int col) {
    int r = row / 3;
    int c = col / 3;
    for (int rr = r * 3; rr < (r * 3) + 3; rr++) {
        for (int cc = c * 3; cc < (c * 3) + 3; cc++) {
            if (grid[rr][cc] == num) return false;
        }
    }
    return true;
}

bool putable(int num, int row, int col) {
    return (checkRow(num, row) && checkCol(num, col) && checkSquare(num, row, col)) ? true : false;
}

void sudoku(int idx) {
    if (idx == list.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    for (int i = 1; i <= 9; i++) {
        int x = list[idx].first;
        int y = list[idx].second;
        if (putable(i, x, y)) {
            grid[x][y] = i;
            sudoku(idx+1);
            grid[x][y] = 0;
        }
    }
}

int main() {
    // 접근방법
    // 0인 위치를 저장해둔다.
    // 스도쿠 조건에 해당하면 해당위치에 숫자를 두고 DFS
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            grid[i][j] = tmp;
            if (tmp == 0) save(i, j);
        }
    }

    sudoku(0);
    if (!possible) cout << "Not Possible" << endl;

    return 0 ;
}