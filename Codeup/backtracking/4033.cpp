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

bool validate(int N) {
    vector<int> checker;

    int blackCnt = 0;
    bool blackTrigger = false;
    for (int idx = 0; idx < N; idx++) {
        if (grid[idx] == true) {
            blackCnt++;
            blackTrigger = true;
        }
        else {
            if (blackTrigger) checker.push_back(blackCnt);
            blackCnt = 0;
            blackTrigger = false;
        }

        if (idx + 1 == N && blackTrigger) checker.push_back(blackCnt);
    }

    if (checker.size() != black.size()) return false;
    
    // for (int i = 0; i < checker.size(); i++) {
    //     if (checker[i] != black[i]) return false;
    // }

    return true;
}

void dfs(int index, int N, int toChoose) {
    // 기저사례: 더 이상 칠할 수 없다면
    // for (int i = 0; i < N; i++) {
    //     cout << grid[i] << " ";
    // }
    // cout << " ==> index : " << index << " toChoose : " << toChoose << endl;

    if (validate(N)) {
        answer++;
        return;
    }

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
        dfs(0, N, 0);
        cout << answer << endl;
        return 0;
    }
}