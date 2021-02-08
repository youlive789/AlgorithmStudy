#include <iostream>
#include <string>

using namespace std;

int main() {

    int length;
    cin >> length;

    string target;
    cin >> target;

    int aCount = 0, bCount = 0;
    for (auto vote : target) {
        if (vote == 'A') {
            aCount++;
        }
        else {
            bCount++;
        }
    }

    if (aCount > bCount) {
        cout << "A" << endl;
    }
    else if (aCount < bCount) {
        cout << "B" << endl;
    }
    else {
        cout << "Tie" << endl;
    }

    return 0;
}