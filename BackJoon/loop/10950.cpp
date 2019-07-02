#include <iostream>

using namespace std;

int main() {

    int countCase, firstNum, secondNum; 
    cin >> countCase;
    for (int caseIndex = 0; caseIndex < countCase; ++caseIndex) {
        cin >> firstNum;
        cin >> secondNum;
        cout << firstNum + secondNum << endl;
    }

    return 0;
}