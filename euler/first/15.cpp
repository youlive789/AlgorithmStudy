#include <iostream>

using namespace std;

int grid[21][21];
unsigned int cache[21][21];

long long findDirection(int row, int col) {
    if (row > 20 || col > 20) return 0;
    if (grid[20][20]) {
        return 1;
    }

    // 오른쪽 혹은 아래로 이동한다.
    unsigned int right;
    if (cache[row][col + 1]) {
        right = cache[row][col + 1];
    }
    else {
        grid[row][col + 1] = 1;
        right = cache[row][col + 1] = findDirection(row, col + 1);
        grid[row][col + 1] = 0;
    }


    unsigned int down;
    if (grid[row + 1][col]) {
        down = cache[row + 1][col];
    }
    else {
        grid[row + 1][col] = 1;
        down = cache[row + 1][col] = findDirection(row + 1, col);
        grid[row + 1][col] = 0;
    }

    return right + down;
}

int main() {

    int result = findDirection(0, 0);
    cout << result << endl;

    return 0;
}