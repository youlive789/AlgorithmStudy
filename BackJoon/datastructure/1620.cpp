#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    map<string, int> m;
    map<int, string> s;

    int targetCount, caseCount;
    cin >> targetCount >> caseCount;

    for (int idx = 0; idx < targetCount; idx++) {
        string name;
        cin >> name;
        m[name] = idx + 1;
        s[idx + 1] = name;
    }

    for (int idx = 0; idx < caseCount; idx++) {
        string target;
        cin >> target;
        if (all_of(target.begin(), target.end(), ::isdigit)) {
            cout << s[stoi(target)] << "\n";
        }
        else {
            cout << m[target] << "\n";
        }
    }

    return 0;
}