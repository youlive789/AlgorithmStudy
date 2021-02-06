#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

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

        if (isdigit(target[0])) {
            cout << s[stoi(target)] << "\n";
        }
        else {
            cout << m[target] << "\n";
        }
    }

    return 0;
}