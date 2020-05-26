#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int sum = 0;
bool block[20];

void findMinium(vector<int> target, int N, int firstOpen, int secondOpen) {
    // 기저사례: 모든 위치를 순회했다면 
    if (target.empty()) {
        return;
    }

    // 처리해야하는 인덱스 가져오기
    int nowIdx = target.front() - 1;
    target.front() = move(target.back());
    target.pop_back();
    cout << "처리해야할 인덱스 : " << nowIdx << endl;

    // 현재 열어야 되는 블록이 열려있다면
    if (block[nowIdx])
    {
        findMinium(target, N, firstOpen, secondOpen);
    }
    // 안열려있다면
    else {
        // 정방향과 역방향중 효율적인 루트를 계산한다.
        int nFirst = abs(firstOpen - nowIdx);
        int nSecond = abs(secondOpen - nowIdx);
        int nShortest = nFirst > nSecond ? nSecond : nFirst;
        int nearest =  nFirst > nSecond ? secondOpen : firstOpen;

        int rFirst = N - nFirst;
        int rSecond = N - nSecond;
        int rShortest = rFirst > rSecond ? rSecond : rFirst;
        int reverseNearest = rFirst > rSecond ? secondOpen: firstOpen;

        // 정방향이 효율적이라면
        if (nShortest < rShortest) {
            // 가까운 블록이 열려는 블록보다 인덱스가 작다면
            if (nearest < nowIdx) {
                // 인덱스가 큰 쪽으로 차례대로 갱신한다.
                for (int idx = nearest; idx < nowIdx; idx++) {
                    bool tmp = block[idx];
                    block[idx] = block[idx+1];
                    block[idx+1] = tmp;
                    sum++;
                }
            }
            // 가까운 블록이 열려는 블록보다 인덱스가 크다면
            else {
                // 인덱스가 작은 쪽으로 차례대로 갱신한다.
                for (int idx = nearest; idx > nowIdx; idx--) {
                    bool tmp = block[idx];
                    block[idx] = block[idx-1];
                    block[idx-1] = tmp;
                    sum++;
                }
            }
        }
        // 역방향이 효율적이라면
        else {
            int next;
            if (reverseNearest < nowIdx) {
                for (int idx = reverseNearest; idx < nowIdx; idx--) {

                    if (N - abs(nowIdx - idx) == 0) break;

                    if (idx < 0) idx = N-1;             
                    if (idx - 1 < 0) {
                        next = N - 1;
                    }
                    else {
                        next = idx - 1;
                    }

                    bool tmp = block[idx];
                    block[idx] = block[next];
                    block[next] = tmp;
                    sum++;
                }
            }
            else {
                for (int idx = reverseNearest; idx > nowIdx; idx++) {

                    if (N - abs(nowIdx - idx) == 0) break;

                    if (idx > N - 1) idx = 0;
                    if (idx + 1 > N - 1) {
                        next = 0;
                    }
                    else {
                        next = idx + 1;
                    }

                    bool tmp = block[idx];
                    block[idx] = block[next];
                    block[next] = tmp;
                    sum++;
                }
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
    vector<int> target;
    while (cases--) {
        cin >> tmp;
        target.push_back(tmp);
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