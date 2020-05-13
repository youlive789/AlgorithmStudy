#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
bool chess[13][13];

void flip(bool can, int col, int row, int N) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (r == row) chess[r][c] = can;
            if (c == col) chess[r][c] = can;
            if (abs(col - row) == abs(c - r)) chess[r][c] = can;
            if (abs(col + row) == abs(c + r)) chess[r][c] = can;
        }
    }
}

void queen(int col, int N) {

    // 기저사례: 모든 열을 다 확인한 경우
    if (col == N) {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (chess[i][col]) {
            flip(false, col, i, N);          
            queen(col+1, N);
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

    queen(0, N);
    cout << answer << endl;

    return 0;
}