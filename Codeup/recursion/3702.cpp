#include <iostream>

using namespace std;

int comb(int n, int r) {
    if (n == r || r == 0) return 1;
    return comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {

    int r, c;
    cin >> r >> c;

    cout << comb(r+1, c) % 100000000 << endl;

    return 0;
}