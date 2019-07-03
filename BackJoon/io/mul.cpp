#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int firstNumber = 0;
    int secondNumber = 0;
    int calcNumber = 0;
    int answer = 0;

    cin >> firstNumber;
    cin >> secondNumber;

    calcNumber = secondNumber;

    int i = 0;
    while (calcNumber != 0) {
        // 두번째 숫자의 자리수를 구한다.
        int multiply = calcNumber % 10;
        calcNumber /= 10;

        // 첫번째 수와 곱하고 출력한다.
        int tempNumber = multiply * firstNumber;
        cout << tempNumber << endl;

        // 10 ^ 자리수를 곱하고 합산한다.
        answer += tempNumber * pow(10, i);
        i++;
    }

    cout << answer << endl;

    return 0;
}