#include <iostream>
#include <string>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    bool found = false;
    while (caseCount--) {
        string target;
        cin >> target;

        if (target == "anj") {
            found = true;
        }
    }

    if (found) {
        cout << "뭐야;" << endl;
    }
    else {
        cout << "뭐야?" << endl;
    }

    return 0;
}