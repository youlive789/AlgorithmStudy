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

void dfs(int index, int N, int toChoose) {
    // 기저사례: 더 이상 칠할 수 없다면
    if (index > N) return;
    if (index == N) {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++) {
        cout << grid[i] << " ";
    }
    cout << endl;

    // 위치 선택과 칠하기
    for (int idx = toChoose; idx < black.size(); idx++) {
        int size = black[idx];
        if (index + size - 1 < N) {
            fill(index, size);
            dfs(index + size + 1, N, idx + 1);
            unfill(index, index + size - 1);
            dfs(index + 1, N, idx);
        }
    }
}

int main() {

    int N, k;
    cin >> N >> k;

    while (k--) {
        int tmp;
        cin >> tmp;
        black.push_back(tmp);
    }

    dfs(0, N, 0);

    cout << answer << endl;

    return 0;
}