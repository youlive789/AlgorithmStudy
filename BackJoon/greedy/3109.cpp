#include <iostream>

using namespace std;

int answer;
char pipemap[10000][500];



void searchPipe() {
    // 오른쪽 상으로 이동할 수 있다면
    // 오른쪽으로 이동할 수 있다면
    // 오른쪽 하로 이동할 수 있다면
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
        searchPipe();
    }

    cout << answer << endl;

    return 0;
}