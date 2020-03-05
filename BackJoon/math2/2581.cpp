#include <iostream>
#include <cmath>

bool isPrime(const int& number) {
    if (number == 1) return false;
    if (number == 2) return true;
    for (int index = 2; index <= sqrt(number); index++) {
        if (number % index == 0) return false;
    }
    return true;
}

int main() {

    using namespace std;

    int first, second;
    cin >> first >> second;

    int primeCount = 0;
    int primeSum = 0;
    int primeMinima = 9999999;
    for (int index = first; index <= second; index++) {
        if (isPrime(index)) {
            primeCount++;
            primeSum += index;
            if (primeMinima > index) {
                primeMinima = index;
            }
        }
        
    }

    if (primeCount != 0) {
        cout << primeSum << endl;
        cout << primeMinima << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}