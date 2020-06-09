#include <iostream>

using namespace std;

long long cache[50000000];

long long mul(int n, int k, int answer) {
    if (k == 0) {
        return 1;
    }
    else if (k == 1) {
        return answer;
    }
    else {
        if (cache[k]) {
            cout << "호출" << endl;
            return cache[k];
        }
        else {
            return cache[k] = mul(n, k-1, (answer * n) % 1000000007);
        }
    }
}

// k를 기하급수적으로 조정하면 cache값을 얻을 수 있다.
long long getMultiply(int n, int k) {
    int oddTrigger = 0;
    if (k % 2 == 1) oddTrigger = 1;
    return (mul(n, k / 2, n) * mul(n, k / 2 + oddTrigger, n)) % 1000000007;
}

int main() {

    int n, k;
    cin >> n >> k;
    cout << getMultiply(n, k) << endl;

    return 0;
}
// 100000 100000000