#include <iostream>

using namespace std;

int cache[10001][501];
char pipemap[10001][501];

int searchPipe(int row, int col, int endRow, int endCol, int lastDirection, bool fail) {
    
    if (cache[row][col]) {
        return cache[row][col];
    }
    else {
        if (col >= endCol || row >= endRow || col < 0 || row < 0) {
            return 0;
        }
        if (col == endCol - 1 && row < endRow ) {
            return 1;
        }

        int answer = 0;

        bool canNotGoRightUp = fail && (lastDirection == 1);
        bool canNotGoRight = fail && (lastDirection == 2);
        bool canNotGoRightDown = fail && (lastDirection == 3);

        // 오른쪽 위
        if (pipemap[row - 1][col + 1] == '.' && !canNotGoRightUp) {
            pipemap[row - 1][col + 1] = 'x';
            answer += searchPipe(row - 1, col +1, endRow, endCol, 1, false);
        }
        // 오른쪽
        else if (pipemap[row][col + 1] == '.' && !canNotGoRight) {
            pipemap[row][col + 1] = 'x';
            answer += searchPipe(row, col +1, endRow, endCol, 2, false);
        }
        // 오른쪽 아래
        else if (pipemap[row + 1][col + 1] == '.' && !canNotGoRightDown) {
            pipemap[row + 1][col + 1] = 'x';
            answer += searchPipe(row + 1, col +1, endRow, endCol, 3, false);
        }
        else {
            pipemap[row][col] = '.';
            switch (lastDirection)
            {
                case 1: answer += searchPipe(row + 1, col -1, endRow, endCol, 1, true); break;
                case 2: answer += searchPipe(row, col -1, endRow, endCol, 2, true); break;
                case 3: answer += searchPipe(row - 1, col -1, endRow, endCol, 3, true); break;
                default: break;
            }
        }

        return cache[row][col] = answer;
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

    int answer = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++) {
        answer += searchPipe(rowIndex, 0, row, col, 0, false);
    }

    cout << answer << endl;

    return 0;
}