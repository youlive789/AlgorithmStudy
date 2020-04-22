#include <iostream>

using namespace std;

int answer = 0;

void steps(int N, int prev, int prevCount) {
    
    // 기저사례: 답이 아닌경우
    if (N < 0) return;

    // 기저사례 : 남은 계단이 0 인 경우
    if (N == 0) {
        answer++;
        return;
    }

    steps(N-1, 1, prevCount - 1);
    steps(N-2, 2, prevCount - 1);
    if (prev != 3 && prevCount <= 0) {
        steps(N-3, 3, 2);
    }
}

int main() {
    int N;
    cin >> N;

    steps(N, 0, 0);

    cout << answer << endl;

    return 0;
}