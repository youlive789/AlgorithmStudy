#include <iostream>

using namespace std;

/*
. X X .
. . . .
X . . .
*/

int answer = 0;
char pipemap[10000][500];

void searchPipe(int row, int col, int endRow, int endCol) {
    
    if (col >= endCol || row >= endRow) return;

    // 정답
    if (col == endCol - 1 && row < endRow ) {
        answer++;
        return;
    }

    // 오른쪽 위
    if (pipemap[row - 1][col + 1] == '.') {
        pipemap[row - 1][col + 1] = 'X';
        searchPipe(row - 1, col +1, endRow, endCol);
    }
    // 오른쪽
    else if (pipemap[row - 1][col + 1] == '.') {
        pipemap[row][col + 1] = 'X';
        searchPipe(row, col +1, endRow, endCol);
    }
    // 오른쪽 아래
    else if (pipemap[row + 1][col + 1] == '.') {
        pipemap[row + 1][col + 1] = 'X';
        searchPipe(row + 1, col +1, endRow, endCol);
    }
}

int main() {

    int row, col;
    cin >> row >> col;

    for (int rowIndex = 0; rowIndex < row; rowIndex++) {
        for (int colIndex = 0; colIndex < col; colIndex++) {
            char map;
            cin >> map;
            pipemap[rowIndex][colIndex] = map;
        }
    }

    for (int rowIndex = 0; rowIndex < row; rowIndex++) {
        searchPipe(rowIndex, 0, row, col);
    }

    // cout << endl;
    // for (int rowIndex = 0; rowIndex < row; rowIndex++) {
    //     for (int colIndex = 0; colIndex < col; colIndex++) {
    //         cout << pipemap[rowIndex][colIndex] << " ";
    //     }
    //     cout << endl;
    // }

    cout << answer << endl;

    return 0;
}