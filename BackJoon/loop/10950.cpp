#include <iostream>

using namespace std;

int main() {

    int countCase, firstNum, secondNum; 
    cin >> countCase;
    for (int caseIndex = 1; caseIndex <= countCase; ++caseIndex) {
        cin >> firstNum;
        cin >> secondNum;
        cout << "Case #"<< caseIndex << ": " << firstNum << " + " << secondNum << " = " << firstNum + secondNum << endl;
    }

    return 0;
}