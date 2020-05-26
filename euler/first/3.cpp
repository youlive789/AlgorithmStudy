#include <iostream>

using namespace std;

bool prime(const int& div) {
    if (div == 2) return true;
    for (int i = 3; i < div; i++) {
        if (div % i == 0) return false;
    }
    return true;
}

int primeFatorize(const long long& N) {
    long long divisor = N;

    int i = 2;
    while (true) {
        cout << divisor << " " << i << endl;
        if (prime(i) && divisor % i == 0) {
            divisor /= i;
            if (divisor == 1) break;
        }
        i++;
    }

    return i;
}

int main() {

    cout << primeFatorize(600851475143) << endl;

    return 0;
}