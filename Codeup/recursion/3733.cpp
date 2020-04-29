#include <iostream>

using namespace std;

int cache[100000000] = {0};

int colatz(long long int n) {
    if (n == 1) return 1;

    if (n < 100000000) {
        if (cache[n]) {
            return cache[n];
        }
        else {
            if (n % 2 == 1) {
                return cache[n] = 1 + colatz( 3 * n + 1);
            }
            else {
                return cache[n] = 1 + colatz(n / 2);
            }
        }
    }
    else {
         if (n % 2 == 1) {
            return 1 + colatz(3 * n + 1);
        }
        else {
            return 1 + colatz(n / 2);
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    int ans = INT8_MAX;
    int cnt = INT8_MIN;
    for (a; a <= b; a++) {
        int tmp = colatz(a);

        if (tmp > cnt) {
            ans = a;
            cnt = tmp;
        }
        else if (tmp == cnt && ans > a) {
            ans = a;
        }
    }
    cout << ans << " " << cnt << endl;

    return 0;
}