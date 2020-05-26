#include <iostream>
#include <cmath>

using namespace std;

int main() {

    unsigned int powSum = 0, sumPow = 0;
    for (int i = 1; i <= 100; i++) {
        powSum += pow(i, 2);
        sumPow += i;
    }
    cout << pow(sumPow, 2) - powSum << endl;
    return 0;
}