#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int sum = 0;
bool block[20];

void findMinium(queue<int> target, int N, int firstOpen, int secondOpen) {
    // 기저사례: 모든 위치를 순회했다면 
    if (target.empty()) {
        return;
    }

    // 처리해야하는 인덱스 가져오기
    int nowIdx = target.front() - 1;
    target.pop();

    // 현재 열어야 되는 블록이 열려있다면
    if (block[nowIdx])
    {
        findMinium(target, N, firstOpen, secondOpen);
    }
    // 안열려있다면
    else {
        
        // 가장 효율적인 문 위치, 방향 결정하기
        // 첫번째 열려있는 문에서 오른쪽 순회거리
        // 첫번째 열려있는 문에서 왼쪽 순회거리
        // 두번째 열려있는 문에서 오른쪽 순회거리
        // 두번째 열려있는 문에서 왼쪽 순회거리

        // 오른쪽 순회가 효율적이라면
        // 왼쪽 순회가 효율적이라면

        // 인덱스 갱신
        int firstIdx = -1, secondIdx = -1;
        for (int i = 0; i < N; i ++) {
            if (block[i]) {
                if (firstIdx == -1) 
                    firstIdx = i;
                else if (firstIdx != -1 && secondIdx == -1) 
                    if (block[i] && secondIdx == -1 && firstIdx != -1) secondIdx = i;
            } 
        }

        findMinium(target, N, firstIdx, secondIdx);
    }
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
    queue<int> target;
    while (cases--) {
        cin >> tmp;
        target.push(tmp);
    }
    findMinium(target, N, firstOpen - 1, secondOpen - 1);
    cout << sum << endl;

    return 0;
}

/*
7
2 5
4
3
1
6
5
=> 5

10
1 10
3
6
10
7
=> 6

*/