#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int grid[9][9];

// 둘 수 있는 최소 숫자를 가져온다.
int getLatestNumber(const set<int>& numbers) {
    int last = 0, result = 0;
    for (int num : numbers) {
        if (last == 0) {
            last = num;
            continue;
        }
        if (num - last > 1) result = num + 1;
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

void rollback(pair<int,int> p) {
    grid[p.first][p.second] = 0;
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

void sudoku() {
    if (done()) {
        return;
    }

    for (int idx = 0; idx < 9; idx++) {
        pair<int,int> p = putRow(idx);
        sudoku();
        rollback(p);

        pair<int,int> p = putCol(idx);
        sudoku();
        rollback(p);

        pair<int,int> p = putSquare(idx);
        sudoku();
        rollback(p);
    }
}

int main() {

    return 0;
}