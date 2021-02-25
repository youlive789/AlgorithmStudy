#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    for (int i = 0; i < caseCount; i++) {
        string carNumber;
        cin >> carNumber;

        string front = carNumber.substr(0, 3);
        string back = carNumber.substr(4, 4);

        int frontSum = 0, backSum = 0;
        for (int i = 0; i < 3; i++) {
            frontSum += ((int)front.at(i) - 65) * (int)pow(26, 2-i);
        }
        backSum += stoi(back);

        int diff = frontSum - backSum;
        if (abs(diff) <= 100) {
            cout << "nice" << endl;
        }
        else {
            cout << "not nice" << endl;
        }
    }

    return 0;
}