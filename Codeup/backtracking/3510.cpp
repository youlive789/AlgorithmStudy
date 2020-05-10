#include <iostream>

using namespace std;

int answer = 0;
int activity[21] = {-1};

void getOptimalBuget(int idx, int maxNum, int sum, int budget) {

    // 기저사례 : activity가 인덱스를 넘어갔다면
    if (idx > maxNum) return;

    // 기저사례 : 순회를 완료했다면
    if (idx == maxNum && sum <= budget) {
        if (answer < sum) answer = sum;
        return;
    }

    getOptimalBuget(idx + 1, maxNum, sum + activity[idx], budget);
    getOptimalBuget(idx + 1, maxNum, sum, budget);
}

int main() {

    int budget, cases;
    cin >> budget >> cases;

    for (int i = 0; i < cases; i++) {
        int tmp;
        cin >> tmp;
        activity[i] = tmp;
    }

    getOptimalBuget(0, cases, 0, budget);
    cout << answer << endl;

    return 0;
}