#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bignumTable[28200];

bool isBignum(int n) {
    int divisorSum = 0;
    for (int i = 1; i < n - 1; i++) {
        if (n % i == 0) divisorSum += i;
    }
    if (divisorSum > n) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    // 1 - 28123 까지의 초과수를 구한다.
    for (int i = 1; i <= 28123; i++) {
        if (isBignum(i)) {
            bignumTable[i] = true;
        }
    }
    
    // 1 - 28123 까지 초과수 두개의 합으로 나타낼 수 없는 정수를 구한다.
    int answer = 0;
    for (int i = 1; i <= 28123; i++) {
        if (i <= 12) {
            answer += i;
        }
        else {
            for (int idx = 1; idx < 28200; idx++) {
                if (i - idx <= 0) {
                    answer += i;
                    break;
                }
                else {
                    if (bignumTable[i - idx] && bignumTable[idx]) break;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}