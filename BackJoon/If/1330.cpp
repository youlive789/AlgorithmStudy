#include <iostream>

using namespace std;

int main() {

    int firstNumber;
    int secondNumber;

    cin >> firstNumber;
    cin >> secondNumber;

    if (firstNumber < secondNumber) {
        cout << "<" << endl;
    } 
    else if (firstNumber > secondNumber) {
        cout << ">" << endl;
    } 
    else if (firstNumber == secondNumber) {
        cout << "==" << endl;
    }

    return 0;
}