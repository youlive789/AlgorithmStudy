#include <cstdio>
#include <algorithm>

using namespace std;

int grid[100][100];
int bottomCache[100][100];
int rightCache[100][100];

int findCandy(int y, int x, int N, int M) {
    if (y == N-1 && x == M-1) {
        return grid[y][x];
    }

    int bottom = 0, right = 0;

    if (y < N-1) {
        if (bottomCache[y][x]) {
            return bottomCache[y][x];
        }
        else {
            bottomCache[y][x] = bottom = grid[y][x] + findCandy(y + 1, x, N, M);
        }
        
    }

    if (x < M-1) {
        if (rightCache[y][x]) {
            return rightCache[y][x];
        }
        else {
            rightCache[y][x] = right = grid[y][x] + findCandy(y, x + 1, N, M);    
        }
    }

    return max(bottom, right);
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