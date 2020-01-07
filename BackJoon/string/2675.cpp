#include <iostream>
#include <string>

using namespace std;

int main() {

    int count;
    cin >> count;

    while (count > 0) {
        int numIter;
        cin >> numIter;

        string inputStr;
        cin >> inputStr;

        string result = "";
        for (int index = 0; index < inputStr.length(); index++) {
            for (int i = 0; i < numIter; i++) {
                result += inputStr[index];
            }
        }
        cout << result << endl;
        count--;
    }

    return 0;
}