#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
bool chess[13][13];

void flip(bool can, int col, int row, int N) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            // 행
            if (r == row) chess[r][c] = can;
            // 열
            if (c == col) chess[r][c] = can;
            // 대각선
            if (abs(col - row) == abs(c - r)) chess[r][c] = can;
            if (abs(col + row) == abs(c + r)) chess[r][c] = can;
        }
    }
}

void queen(int col, int N, int cntQueen) {

    // 기저사례: 모든 열을 다 확인한 경우
    if (col == N) {
        // 퀸을 모두 배치할 수 있었다면
        if (N == cntQueen) answer++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (chess[i][col]) {
            flip(false, col, i, N);
            queen(col+1, N, cntQueen+1);
            flip(true, col, i, N);
        }
    }
}

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            chess[i][j] = true;
        }
    }

    queen(0, N, 0);
    cout << answer << endl;

    return 0;
}