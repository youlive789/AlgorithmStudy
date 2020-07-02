#include <cstdio>
#include <algorithm>

using namespace std;

int grid[100][100];
int bottomCache[100][100];
int rightCache[100][100];
int leftCache[100][100];
int topCache[100][100];

int findCandy(int y, int x, int N, int M) {
    if (y == N-1 && x == M-1) {
        return grid[y][x];
    }

    int bottom = 0, right = 0, left = 0, top = 0;
    printf("%d %d\n", x, y);

    // bottom
    if (y < N-1) bottom = grid[y][x] + findCandy(y + 1, x, N, M);

    // right
    if (x < M-1) right = grid[y][x] + findCandy(y, x + 1, N, M);    

    // top
    if (y > 1) top = grid[y][x] + findCandy(y - 1, x, N, M);

    // left
    if (x > 1) left = grid[y][x] + findCandy(y, x - 1, N, M);    

    int res = max(max(bottom, right), max(top, left));
    printf("%d\n", res);

    return res;
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = findCandy(0, 0, N, M);

    printf("%d\n", result);

    return 0;
}