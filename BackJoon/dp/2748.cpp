#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

long cache[91];

long fibo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        if (cache[n] != -1) return cache[n];
        return cache[n] = fibo(n - 1) + fibo(n - 2);
    }
}

int main() {
    memset(cache, -1, sizeof(cache));

    int test;
    cin >> test;
    cout << fibo(test) << endl;

    return 0;
}