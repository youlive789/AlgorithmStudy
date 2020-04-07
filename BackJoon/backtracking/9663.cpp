#include <iostream>

using namespace std;

int answer = 0;
const int direction[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

void init(int** board, int N);
void queen(int** board, int x, int y, int count, int N);
void path(int** board, int x, int y, int dx, int dy, int N);

void init(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }
}

void queen(int** board, int x, int y, int count, int N) {
    if (count == N) {
        answer++;
        return;
    } 
    
    board[y][x] = 1;
    for (int idx = 0; idx < 8; idx++) {
        path(board, x + direction[idx][0], y + direction[idx][1], direction[idx][0], direction[idx][1], N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ' ' <<board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (board[j][i] != 0 && board[j][i] != 1) {
                queen(board, i, j, count+1, N);
            }
        }
    }
}

void path(int** board, int x, int y, int dx, int dy, int N) {
    if (x < 0 || y < 0) return;
    if (x > N - 1 || y > N - 1) return;
    if (board[y][x] != 1) {
        board[y][x] = 0;
    }
    path(board, x + dx, y + dy, dx, dy, N);
}

int main() {

    int N;
    cin >> N;

    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
    }

    init(board, N);

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            queen(board, i, j, 1, N);
            init(board, N);
        }
    } 

    cout << answer << endl;
    // -1 : 퀸과 이동경로가 아닌 곳
    //  0 : 이동경로
    //  1 : 퀸이 있는 곳

    // 더이상 경우의 수가 없을 때까지 반복
        // 왼쪽 위부터 퀸을 놓는다.
            // 퀸이 N개가 될 때까지 반복
            // 이동경로를 모두 칠한다. (8방향)
            // 이동경로가 아닌 곳에 퀸을 놓는다.

    return 0;
}