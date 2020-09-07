#include <iostream>

using namespace std;

int main() {

    float a, b;
    cin >> a >> b;

    float answer = -b / a;

    cout.setf(ios::showpoint);
    cout << fixed;
    cout.precision(4);
    cout << answer << endl;

    return 0;
}