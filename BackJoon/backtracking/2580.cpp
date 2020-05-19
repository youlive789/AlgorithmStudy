#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

int col[9];
int row[9];
int sqaure[9];
int grid[9][9];

// 둘 수 있는 최소 숫자를 가져온다.
int getLatestNumber(const set<int>& numbers) {
    int result = 0;
    vector<int> tmp;
    set<int> big = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set_difference(big.begin(), big.end(), numbers.begin(), numbers.end(), back_inserter(tmp));
    
    for (int i = 1; i <= 9; i++) {
        if (find(tmp.begin(), tmp.end(), i) != tmp.end()) {
            result = i;
            break;
        }
    }
    return result;
}

// row 기준으로 숫자를 둔다.
pair<int, int> putRow(int idx) {
    int firstZeroIndex = -1;
    set<int> numbers;
    for (int i = 0; i < 9; i++) {
        numbers.insert(grid[idx][i]);
        if (firstZeroIndex == -1 && grid[idx][i] == 0) firstZeroIndex = i;
    }

    int num = getLatestNumber(numbers);
    grid[idx][firstZeroIndex] = num;
    return make_pair(idx, firstZeroIndex);
}

// col 기준으로 숫자를 둔다.
pair<int, int> putCol(int idx) {
    int firstZeroIndex = -1;
    set<int> numbers;
    for (int i = 0; i < 9; i++) {
        numbers.insert(grid[i][idx]);
        if (firstZeroIndex == -1 && grid[i][idx] == 0) firstZeroIndex = i;
    }

    int num = getLatestNumber(numbers);
    grid[firstZeroIndex][idx] = num;
    return make_pair(firstZeroIndex, idx);
}

// 사각형 기준으로 숫자를 둔다.
pair<int, int> putSquare(int idx) {
    int firstZeroRow = -1, firstZeroCol = -1;
    set<int> numbers;
    int row = (idx / 3) * 3, col = (idx % 3) * 3;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            numbers.insert(grid[row + r][col + c]);
            if (grid[row + r][col + c] == 0 && firstZeroCol == -1 && firstZeroRow == -1) {
                firstZeroCol = col + c;
                firstZeroRow = row + r;
            }
        }
    }

    int num = getLatestNumber(numbers);
    grid[firstZeroRow][firstZeroCol] = num;
    return make_pair(firstZeroRow, firstZeroCol);
}

// 그리드가 가득 찼는지 검사한다.
bool done() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == 0) return false;
        }
    }
    return true;
}

// 0 개수 업데이트
void update() {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(sqaure, 0, sizeof(sqaure));

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == 0) {
                row[r]++;
                col[c]++;
            }
        }
    }

    int idx = 0, cnt = 0;
    for (int r = 0; r < 9; r += 3) {
        for (int c = 0; c < 9; c += 3) {
            if (grid[r][c] == 0) cnt++;
            if (grid[r][c+1] == 0) cnt++;
            if (grid[r][c+2] == 0) cnt++;
            if (grid[r+1][c] == 0) cnt++;
            if (grid[r+1][c+1] == 0) cnt++;
            if (grid[r+1][c+2] == 0) cnt++;
            if (grid[r+2][c] == 0) cnt++;
            if (grid[r+2][c+1] == 0) cnt++;
            if (grid[r+2][c+2] == 0) cnt++;
            sqaure[idx] = cnt;
            cnt = 0;
            idx++;
        }
    }
}

// row 중복을 체크한다.
bool checkRowDuplicated() {
    for (int i = 0; i < 9; i++) {
        set<int> check;
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] != 0 && check.find(grid[i][j]) != check.end()) {
                check.insert(grid[i][j]);
            }
            else if (grid[i][j] == 0) {
                continue;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

// col 중복을 체크한다.
bool checkColDuplicated() {
    for (int i = 0; i < 9; i++) {
        set<int> check;
        for (int j = 0; j < 9; j++) {
            if (grid[j][i] != 0 && check.find(grid[j][i]) != check.end()) {
                check.insert(grid[j][i]);
            }
            else if (grid[j][i] == 0) {
                continue;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

// 사각형 중복을 체크한다.
bool checkSquareDuplicated() {
    for (int i = 0; i < 9; i += 3) {
        set<int> check;
        set<int>::iterator it;
        for (int j = 0; j < 9; j += 3) {
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    if (grid[i+r][j+c] != 0 && check.find(grid[i+r][j+c]) != check.end()) {
                        check.insert(grid[i+r][j+c]);
                    }
                    else if (grid[i+r][j+c] == 0) {
                        continue;
                    }
                    else {
                        return false;
                    } 
                }
            }
        }
    }

    return true;
}

void sudoku() { 
    // 중복된 값이 입력됐을 때 리턴처리 필요
    // if (!checkRowDuplicated()) return;
    // if (!checkColDuplicated()) return;
    // if (!checkSquareDuplicated()) return;
    if (done()) return;

    update();

    pair<int,int> p;
    for (int idx = 0; idx < 9; idx++) {
        if (row[idx] > 0) {
            p = putRow(idx);
            sudoku();
        }
        
        if (col[idx] > 0) {
            p = putCol(idx);
            sudoku();
        }

        if (sqaure[idx] > 0) {
            p = putSquare(idx);
            sudoku();
        }
    }
}

int main() {

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            int tmp;
            cin >> tmp;
            grid[r][c] = tmp;
        }
    }
    update();
    sudoku();
    cout << endl;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0

*/