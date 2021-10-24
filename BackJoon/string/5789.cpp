#include <iostream>
#include <string>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        
        string target;
        cin >> target;

        int compare1 = (target.size() / 2);
        int compare2 =  compare1 - 1;

        if (target[compare1] == target[compare2]) {
            cout << "Do-it" << "\n";
        }
        else {
            cout << "Do-it-Not" << "\n";
        }
    }

    return 0;
}