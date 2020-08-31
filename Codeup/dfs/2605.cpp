#include <iostream>

using namespace std;

int grid[7][7];

int answer = 0;
int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};

void findArea(int x, int y, int count, int last) {
    // 기저사례: 격자를 벗어났다면
    if (x < 0 || y < 0 || x > 7 || y > 7) return;

    if (grid[y][x] == -1) return;

    // 기저사례: 현재 위치가 이전 위치와 다르다면
    if (grid[y][x] != last) return;

    // 기저사례: count == 2 이면서 현재 위치가 last와 같다면 (정답)
    if (count == 2 && grid[y][x] == last) {
        cout << count << " " << last << endl;
        answer++;
        return;
    }

    int now = grid[y][x];

    // 8방향을 순회
    for (int idx = 0; idx < 8; idx++) {
        grid[y][x] = -1;
        findArea(x + dx[idx], y + dy[idx], count + 1, now);
        grid[y][x] = now;
    }
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
            findArea(x, y, 0, grid[y][x]);
        }
    }

    cout << answer << endl;

    return 0;
}