#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int sum = 0;
bool block[20];

void findMinium(queue<int> target, int N, int firstOpen, int secondOpen) {

    for (int i = 0; i < N; i++) {
        cout << block[i] << " ";
    }
    cout << "==> " << sum << "  처리해야할 위치 : " << target.front() << endl;

    // 기저사례: 모든 위치를 순회했다면 
    if (target.empty()) {
        return;
    }

    // 처리해야하는 인덱스 가져오기
    int nowIdx = target.front() - 1;
    target.pop();

    // 현재 열어야 되는 블록이 열려있다면
    if (block[nowIdx]) {
        findMinium(target, N, firstOpen, secondOpen);
    }
    // 안열려있다면
    else {
        int firstRight, firstLeft, secondRight, secondLeft;
        if (nowIdx > firstOpen) {
            firstRight = abs(firstOpen - nowIdx);
            firstLeft = N - abs(firstOpen - nowIdx);
        }
        else {
            firstRight = N - abs(firstOpen - nowIdx);
            firstLeft = abs(firstOpen - nowIdx);
        }

        if (nowIdx > secondOpen) {
            secondRight = abs(secondOpen - nowIdx);
            secondLeft = N - abs(secondOpen - nowIdx);
        }
        else {
            secondRight = N - abs(secondOpen - nowIdx);
            secondLeft = abs(secondOpen - nowIdx);
        }
        
        // 시작지점 찾기
        int firstShortest = firstRight > firstLeft ? firstLeft : firstRight;
        int secondShortest = secondRight > secondLeft ? secondLeft : secondRight;
        int targetIdx = firstShortest > secondShortest ? secondOpen : firstOpen;
        int shortest = firstShortest > secondShortest ? secondShortest : firstShortest;

        // 방향 찾기
        int rightShortest = firstRight > secondRight ? secondRight : firstRight;
        int leftShortest = firstLeft > secondLeft ? secondLeft : firstLeft;
        bool isRight = leftShortest > rightShortest ? true : false;

        /*
        grid를 환형 자료구조로 바꾸면 편할것 같다 !!!
        */

        // 오른쪽 순회가 효율적이라면
        if (isRight) {
            cout << "오른쪽 " << "거리 : " << shortest << endl;

            int idx = targetIdx;
            while (shortest--) {
                if (idx >= N) idx = 0;
                int next = idx + 1;
                if (next >= N) next = 0;
                cout << idx << " " << next << endl;
                int tmp = block[idx];
                block[idx] = block[next];
                block[next] = tmp;
                sum++;
                idx++;
            }
        }
        // 왼쪽 순회가 효율적이라면
        else {
            cout << "왼쪽" << "거리 : " << shortest << endl;

            int idx = targetIdx;
            while (shortest--) {
                if (idx < 0) idx = N-1;
                int next = idx - 1;
                if (next < 0) next = N-1;
                cout << idx << " " << next << endl;
                int tmp = block[idx];
                block[idx] = block[next];
                block[next] = tmp;
                sum++;
                idx--;
            }
        }
        
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

10
1 2
10
8
3
9
4
2
5
10
1
6
7
=> 25

*/