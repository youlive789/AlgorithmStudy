#include <iostream>

using namespace std;

int calcFactorial(const int& number) {
    int answer = 1;
    int calcNumber = number;
    while (calcNumber) {
        answer *= calcNumber;
        --calcNumber;
    }
    return answer;
}

int main() {

    int inputNumber;
    cin >> inputNumber;

    cout << calcFactorial(inputNumber) << endl;

    return 0;
}