#include <iostream>
#include <string>

using namespace std;

string reverseChar(string str) {
    
    int lengthStr = str.size();
    int centerPoint = lengthStr / 2;

    char temp;
    for (int index = 0; index < centerPoint; index++) {
        temp = str[index];
        str[index] = str[lengthStr - 1 - index];
        str[lengthStr - 1 - index] = temp;
    }

    return str;
}

int main() {

    string firstNumber;
    cin >> firstNumber;

    string secondNumber;
    cin >> secondNumber;

    firstNumber = reverseChar(firstNumber);
    secondNumber = reverseChar(secondNumber);

    int num1 = atoi(firstNumber.c_str());
    int num2 = atoi(secondNumber.c_str());

    if (num1 > num2) {
        cout << num1 << endl;
    }
    else if (num1 < num2) {
        cout << num2 << endl;
    }

    return 0;
}