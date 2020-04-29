#include <iostream>
#include <string.h>

using namespace std;

unsigned int cache[100000000] = {0};

int colatz(int partial_result, long long int n) {
    if (n == 1) return partial_result;

    if (cache[n]) {
        return cache[n];
    }
    else {
        if (n % 2 == 1) {
            return cache[n] = colatz(partial_result + 1, 3 * n + 1);
        }
        else {
            return cache[n] = colatz(partial_result + 1, n / 2);
        }
    }
}

int main() {

    printf("%d\n", colatz(1, 60975));

    // long long int a, b;
    // cin >> a >> b;

    // int ans = INT8_MAX;
    // int cnt = INT8_MIN;
    // int tmp;
    // for (a; a <= b; a++) {
    //     tmp = colatz(1, a);

    //     if (tmp > cnt) {
    //         ans = a;
    //         cnt = tmp;
    //     }
    //     else if (tmp == cnt && ans > a) {
    //         ans = a;
    //     }
    // }
    // cout << ans << " " << cnt << endl;

    return 0;
}