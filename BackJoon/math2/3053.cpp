#include <iostream>
#include <cmath>

using namespace std;

/*
택시 기하학
r = |x| + |y|

유클리드 기하학
r^2 = x^2 + y^2

r = 1 (3.14, 2)
*/

int main() {

    double radius;
    cin >> radius;

    double uclid = M_PI * radius * radius;
    double taxi = 2 * radius * radius;

    cout << fixed;
    cout.precision(6);

    cout << uclid << endl;
    cout << taxi << endl;

    return 0;
}