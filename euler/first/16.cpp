#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double test = pow(2, 1000);
    cout << test << endl;
    double result = 0;
    while (test) {
        double tmp = test / 10;
        double rest = test - (tmp * 10);
        result += rest;
        test = tmp;
    }

    cout << result << endl;

    return 0;
}