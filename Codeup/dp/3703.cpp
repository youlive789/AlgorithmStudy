#include <cstdio>

using namespace std;

int grid[100][100];

int result = 0;

void findCandy(int y, int x, int N, int M, int sum) {
    if (y == N - 1 && x == M - 1) {
        printf("%d", sum);
        if (sum > result) {
            result = sum;
        }
        return;
    }

    if (y < N - 1) {
        findCandy(y + 1, x, N, M, sum + grid[x][y]);
    }

    if (x < M - 1) {
        findCandy(y, x + 1, N, M, sum + grid[x][y]);
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

    findCandy(0, 0, N, M, grid[0][0]);

    printf("%d\n", result);

    return 0;
}