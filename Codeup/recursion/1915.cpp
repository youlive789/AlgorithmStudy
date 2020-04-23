#include <iostream>

using namespace std;

int cache[201];

int fibo(int n) {
    if (n == 1 || n == 2)  return 1;

    if (cache[n]) {
        return cache[n];
    }
    else {
        return cache[n] = (fibo(n - 1) + fibo(n - 2)) % 10009 ;
    }
}

int main() {

    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}