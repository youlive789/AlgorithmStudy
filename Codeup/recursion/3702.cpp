#include <iostream>
#include <cmath>

using namespace std;

int cache[100][100] = {0};

int comb(int n, int r) {
    if (n == r || r == 0) return 1;
    if (cache[n][r]) {
        return cache[n][r];
    }
    else {
        return cache[n][r] = (comb(n - 1, r) + comb(n - 1, r - 1)) % 100000000;
    }
}

int main() {

    int r, c;
    cin >> r >> c;

    int n = r + c - 2;
    int s = n % 2 == 0 ? 1 : 0;
    int t = abs(c - n) - s;

    cout << comb(n, t) << endl;

    return 0;
}