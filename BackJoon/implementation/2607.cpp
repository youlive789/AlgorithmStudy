#include <iostream>
#include <map>
#include <string>
#include <string.h>

using namespace std;

int targetTable[91] = {0};
int compareTable[91] = {0};

int main() {

    int caseNumber;
    cin >> caseNumber;

    string target;
    cin >> target;
    for (int i = 0; i < target.size(); ++i) {
        targetTable[target.at(i)]++;
    }

    int answer = 0;
    for (int i = 0; i < caseNumber-1; ++i) {
        string inputString;
        cin >> inputString;
        for (int i = 0; i < inputString.size(); ++i) {
            compareTable[inputString.at(i)]++;
        }

        int sumResult = 0;
        for (int i = 0; i < 91; ++i) {
            sumResult += abs(compareTable[i] - targetTable[i]);
        }

        if (sumResult <= 2) answer++;
        memset(compareTable, 0, sizeof(int) * 91);
    }

    cout << answer << endl;

    return 0;
}