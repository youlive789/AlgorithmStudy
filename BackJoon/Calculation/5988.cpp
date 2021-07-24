#include <iostream>
#include <string>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        string numberString;
        cin >> numberString;

        int target = numberString.at(numberString.size()-1) - '0';

        if (target % 2 == 0) {
            cout << "even" << "\n";
        }
        else {
            cout << "odd" << "\n";
        }
    }

    return 0;
}