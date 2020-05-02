#include <iostream>

using namespace std;

int cache[21] = {0};

int fibo(int k) {

    if (cache[k]) {
        return cache[k];
    }
    else {
        if (k == 1) {
            return cache[k] = 2;
        }
        else if (k == 2) {
            return cache[k] = 3;
        }
        else {
            return cache[k] = fibo(k - 1) + fibo(k - 2);
        }
    }
}

int main() {

    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}