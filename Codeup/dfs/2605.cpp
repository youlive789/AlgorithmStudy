#include <iostream>

using namespace std;

int grid[7][7];

int answer = 0;

int findArea(int x, int y, int color) {
    // 기저사례: 격자를 벗어났다면
    if (x < 0 || y < 0 || x >= 7 || y >= 7) return 0;

    // 기저사례: 현재 위치가 이전 위치와 다르다면
    if (grid[y][x] != color) return 0;

    // 기저사례: 같은 곳을 탐색하지 못하게 0으로 만듬
    if (grid[y][x] == color) grid[y][x] = 0;

    // 4 방향을 순회
    return 1 + findArea(x-1, y, color) + findArea(x+1, y, color) + findArea(x, y+1, color) + findArea(x, y-1, color);
}

int main() {

    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            int tmp;
            cin >> tmp;
            grid[y][x] = tmp;
        }
    }

    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            int tmp = 0;
            if (grid[y][x] != 0) {
                tmp = findArea(x, y, grid[y][x]);
            }
            if (tmp >= 3) answer++;
        }
    }

    cout << answer << endl;

    return 0;
}