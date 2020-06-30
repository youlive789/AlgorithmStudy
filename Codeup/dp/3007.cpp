#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<int> idx_start;
vector<int> idx_end;

int main() {

    int numberCnt, cases;
    cin >> numberCnt >> cases;

    for (int i = 0; i < numberCnt; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    while (cases--) {
        int startIdx, endIdx;
        cin >> startIdx >> endIdx;

        startIdx--;
        endIdx--;

        idx_start.push_back(startIdx);
        idx_end.push_back(endIdx);
    }
    
    // 가장 큰 범위를 지정
    int lowStart, maxEnd;
    lowStart = *min_element(idx_start.begin(), idx_start.end());
    maxEnd = *max_element(idx_end.begin(), idx_end.end());

    // 합계를 미리 계산
    int sumCache = 0;
    for (int i = lowStart; i <= maxEnd; i++)
        sumCache += numbers[i];

    for (int i = 0; i < idx_start.size(); i++) {

        int nowAnswer = sumCache;

        if (idx_start[i] == idx_end[i]) {
            cout << numbers[idx_start[i]] << endl;
            continue;
        }

        if (lowStart < idx_start[i]) {
            for (int idx = lowStart; idx < idx_start[i]; idx++) {
                nowAnswer -= numbers[idx];
            }
                
        }

        if (maxEnd > idx_end[i]) {
            for (int idx = idx_end[i] + 1; idx <= maxEnd; idx++) {
                nowAnswer -= numbers[idx];
            }
        }

        cout << nowAnswer << endl;
    }

    return 0;
}