#include <cstdio>
#include <algorithm>

using namespace std;

int grid[100][100];
int cache[100][100];

// 하단, 오른쪽을 따로 캐싱하면 안된다!!!
int findCandy(int y, int x, int N, int M) {
    if (y >= N || x >= M) {
        return 0;
    }

    if (cache[y][x]) {
        return cache[y][x];
    }
    else {
        return cache[y][x] = max(grid[y][x] + findCandy(y + 1, x, N, M), grid[y][x] + findCandy(y, x + 1, N, M) );
    }
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