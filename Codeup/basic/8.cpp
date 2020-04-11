#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() {

    long a, d, c;
    cin >> a >> d >> c;

    int day = 1;
    while (day % a != 0 || day % d != 0 || day % c != 0) {
        day++;
    }
    cout << day << endl;

    return 0;
}