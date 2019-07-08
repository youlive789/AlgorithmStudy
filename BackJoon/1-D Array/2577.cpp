#include <iostream>

using namespace std;

int main() {

    int numberDict[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int firstNum, secondNum, thirdNum, multiple;

    cin >> firstNum >> secondNum >> thirdNum;

    multiple = firstNum * secondNum * thirdNum;
    while (multiple != 0) {
        int check = multiple % 10;
        multiple /= 10;
        numberDict[check]++;
    }

    for (int index = 0; index < 10; index++) {
        cout << numberDict[index] << endl;
    }

    return 0;
}