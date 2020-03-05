#include <iostream>
#include <cmath>
#include <cstdio>

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

    for (int index = first; index <= second; index++) {
        if (isPrime(index)) {
            printf("%d\n", index);
        } 
    }
}