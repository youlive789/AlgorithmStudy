#include <iostream>
#include <vector>

using namespace std;

int sum = 0;
bool block[20];

void findMinium(int firstOpen, int secondOpen) {
    // 현재 열어야 되는 블록이 열려있다면
        // +0
    // 안열려있다면
        // 열려있는 블록 중 가장 가까운 블록을 찾는다.
        // 가까운 블록이 열려는 블록보다 인덱스가 작다면
            // 인덱스가 큰 쪽으로 차례대로 갱신한다.
        // 가까운 블록이 열려는 블록보다 인덱스가 크다면
            // 인덱스가 작은 쪽으로 차례대로 갱신한다.
        // 갱신된 상태로 DFS
}

int main() {

    int N, firstOpen, secondOpen, cases;
    cin >> N >> firstOpen >> secondOpen >> cases;

    for (int i = 0; i < N; i++) {
        if (firstOpen - 1 == i || secondOpen - 1 == i) {
            block[i] = true;
        }
        else {
            block[i] = false;
        }
    }

    int tmp;
    vector<int> target;
    while (cases--) {
        cin >> tmp;
        target.push_back(tmp);
    }
        
    return 0;
}

1 2 3 4 5
    0