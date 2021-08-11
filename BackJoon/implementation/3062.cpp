#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        string stringNumber;
        cin >> stringNumber;

        int origin;
        origin = stoi(stringNumber);

        reverse(stringNumber.begin(), stringNumber.end());

        int reversed;
        reversed = stoi(stringNumber);

        string result = to_string(origin + reversed);
        bool isPalindrome = true;
        for (int idx = 0; idx < result.size()/2; idx++) {
            if (result[idx] != result[result.size() - idx - 1]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }

    return 0;
}