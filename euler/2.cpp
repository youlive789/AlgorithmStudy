#include <iostream>

using namespace std;

int cache[4000000];

int fibo(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        if (cache[n]) {
            return cache[n];
        }
        else {
            return cache[n] = fibo(n - 1) + fibo(n - 2);
        }
    }
}

int main() {

    for (int i = 0; i < 4000000; i++) {
        cache[i] = 0;
    }

    int sum = 0, f = 0, i = 1;
    while (f <= 4000000) {
        f = fibo(i);
        if (f % 2 == 0)
            sum += f;
        i++;
    }

    cout << sum << endl;

    return 0;
}