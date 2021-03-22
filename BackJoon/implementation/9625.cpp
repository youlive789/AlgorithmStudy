#include <iostream>

using namespace std;

unsigned long long cache[46] = {0};

unsigned long long fibo(const int& idx) {
    if (idx == 0) return 0;

    if (idx == 1 || idx == 2) {
        return 1;
    }
    else {
        if (cache[idx]) {
            return cache[idx];
        }
        else {
            cache[idx] = fibo(idx - 1) + fibo(idx - 2);
            return cache[idx];
        }
    }
}   

int main() {

    int caseCount;
    cin >> caseCount;

    cout << fibo(caseCount-1) << " " << fibo(caseCount) << endl;

    return 0;
}