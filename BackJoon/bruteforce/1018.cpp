#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int rows, cols;
    cin >> rows >> cols;

    // 보드판 초기화
    char** board = new char*[rows];
    for (int idx = 0; idx < rows; idx++) {
        board[idx] = new char[cols];
    }

    // 보드판 생성
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cin >> board[row][col];
        }
    }

    // 격자 순서대로 8 * 8 순회
    int cntCols = (cols - 8) + 1;
    int cntRows = (rows - 8) + 1;
    int blackMin = 99999, whiteMin = 99999;
    int blackCnt = 0, whiteCnt = 0;
    for (int gridrow = 0; gridrow < cntRows; gridrow++) {
        for (int gridcol = 0; gridcol < cntCols; gridcol++) {

            for (int row = gridrow; row < gridrow + 8; row++) {
                for (int col = gridcol; col < gridcol + 8; col++) {
                    int blackTrigger = (row % 2) ^ (col % 2); 
                    int whiteTrigger = !((row % 2) ^ (col % 2));

                    // 블랙 형태 세기
                    if (blackTrigger) {
                        if (board[row][col] == 'B') blackCnt++;
                    }
                    else {
                        if (board[row][col] == 'W') blackCnt++;
                    }

                    // 화이트 형태 세기
                    if (whiteTrigger) {
                        if (board[row][col] == 'B') whiteCnt++;
                    }
                    else {
                        if (board[row][col] == 'W') whiteCnt++;
                    }
                }   
            }
            blackMin = min(blackMin, blackCnt);
            whiteMin = min(whiteMin, whiteCnt);
            blackCnt = 0;
            whiteCnt = 0;
        }
    }

    int answer = min(blackMin, whiteMin);
    cout << answer << endl;

    return 0;
}