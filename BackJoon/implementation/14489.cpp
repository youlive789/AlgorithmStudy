#include <iostream>

using namespace std;

int main() {

    unsigned long long a, b, cost;
    cin >> a >> b >> cost;

    if (a + b < (cost * 2)) {
        cout << a + b << endl;
    }
    else {
        cout << a + b - (cost * 2) << endl;
    }

    return 0;
}