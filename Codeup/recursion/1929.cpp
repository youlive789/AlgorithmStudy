#include <iostream>

using namespace std;

void colatz(int n) {
    if (n == 1) {
        cout << n << endl;
        return;
    }

    if (n % 2 == 1) {
        colatz(3*n + 1);
    }
    else {
        colatz(n / 2);
    }

    cout << n << endl;
}

int main() {

    int n;
    cin >> n;

    colatz(n);

    return 0;
}