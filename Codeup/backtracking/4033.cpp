#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
bool grid[20];
vector<int> black;

int fill(int startIdx, int size) {
    for (int i = 0; i < size; i++) {
        grid[startIdx + i] = true;
    }
}

int unfill(int startIdx, int endIdx) {
    for (int i = startIdx; i <= endIdx; i++) {
        grid[i] = false;
    }
}

void dfs(int index, int N, int toChoose, int cnt) {
    // 기저사례: K만큼 칠했다면
    if (cnt == black.size()) {
        answer++;
        return;
    }

    // 위치 선택과 칠하기
    for (int idx = toChoose; idx < black.size(); idx++) {
        int size = black[idx];

        if (index + size - 1 < N) {
            fill(index, size);
            dfs(index + size + 1, N, idx + 1, cnt + 1);
            unfill(index, index + size - 1);
            dfs(index + 1, N, idx, cnt);
        }
    }
}

int main() {

    int N, k;
    cin >> N >> k;
    int numCnt = k;

    while (numCnt--) {
        int tmp;
        cin >> tmp;
        black.push_back(tmp);
    }

    if (k == 1) {
        cout << N - black[0] + 1 << endl;
        return 0;
    }
    else {
        dfs(0, N, 0, 0);
        cout << answer << endl;
        return 0;
    }
}