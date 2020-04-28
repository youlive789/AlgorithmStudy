#include <iostream>

using namespace std;

int cache[4][100005] = {0};

int steps(int step, int n) {
    if (n < 0) return 0;
    if (n == 0) {
        return 1;
    }

    if (cache[step][n]) {
        return cache[step][n];
    }
    else {
        return cache[step][n] = (steps(1, n - 1) + steps(2, n - 2) + steps(3, n - 3)) % 1000;
    }
}

int main() {

    int n;
    cin >> n;

    cout << steps(0, n) << endl;

    return 0;
}