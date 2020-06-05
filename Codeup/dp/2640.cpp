#include <iostream>

using namespace std;

int cache[100000003];

int mul(int n, int k) {
    if (k == 1) {
        return n;
    }
    else {
        if (cache[k]) {
            return cache[k];
        }
        else {
            return cache[k] = (mul(n, k-1) * n) % 1000000007;
        }
    }
}

int main() {

    int n, k;
    cin >> n >> k;
    cout << mul(n, k) << endl;

    return 0;
}
// 100000 100000000