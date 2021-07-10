#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    map<char, int> charCount;
    for (int idx = 0; idx < caseCount; ++idx) {
        string target;
        cin >> target;

        char first = target.at(0);
        if (charCount.find(first) == charCount.end()) {
            charCount[first] = 1;
        }
        else {
            charCount[first]++;
        }
    }

    if (charCount.size() > 1) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    }

    return 0;
}