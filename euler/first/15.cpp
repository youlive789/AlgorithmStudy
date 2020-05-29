#include <iostream>

using namespace std;

int grid[21][21];
unsigned long long cache[21][21];

unsigned long long findDirection(int row, int col) {
    if (row > 20 || col > 20) return 0;
    if (grid[20][20]) return 1;
    
    unsigned long long right;
    if (cache[row][col + 1]) {
        right = cache[row][col + 1];
    }
    else {
        grid[row][col + 1] = 1;
        right = cache[row][col + 1] = findDirection(row, col + 1);
        grid[row][col + 1] = 0;
    }


    unsigned long long down;
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

    long long result = findDirection(0, 0);
    cout << result << endl;

    return 0;
}