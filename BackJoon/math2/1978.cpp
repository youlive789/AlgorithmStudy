#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(const int& number) {
    if (number == 1) return false;
    if (number == 2) return true;
    for (int index = 2; index <= sqrt(number); index++) {
        if (number % index == 0) return false;
    }

    return true;
}

int main() {

    int answer = 0;

    int cases;
    cin >> cases;
    while(cases--) {
        int number;
        cin >> number;
        if (isPrime(number)) answer++;
    }

    cout << answer << endl;

    return 0;
}