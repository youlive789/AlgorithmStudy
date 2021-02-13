#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int divisor = 2;
    while (divisor <= n) {
        if (n % divisor == 0) {
            n /= divisor;
            cout << divisor << endl;
        }
        else {
            divisor++;
        }
    }

    return 0;
}