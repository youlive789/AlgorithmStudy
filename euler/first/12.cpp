#include <iostream>

using namespace std;

int getCountDivisors(const int& triNumber) {
    int cnt = 0;
    // 약수의 성질을 이용한 로직
    // 30의 약수
    // 1 30
    // 2 15
    // 3 10
    // 5 6
    // 작은 약수들을 구했을 때 이미 큰 약수를 알고있다!
    // 결과적으로 logN 복잡도가 된다.
    for (int i = 1; i * i <= triNumber; i++) {
        if (triNumber % i == 0) {
            cnt++;
            if (i * i < triNumber) {
                cnt++;
            }
        }
    }

    return cnt;
}

long long getNumber(int n) {
    return n * (n + 1) / 2;
}

int main() {

    int n = 1, triNumber = 0;
    int cntDivisors = 0;
    while (cntDivisors < 500) {
        triNumber = getNumber(n);
        cntDivisors = getCountDivisors(triNumber);
        n++;
    }

    cout << triNumber << endl;

    return 0;
}