#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    for (int i = 0; i < caseCount; i++) {

        int itemCount;
        map<string, set<string>> fashion;
        cin >> itemCount;

        while (itemCount--) {
            string item, category;
            cin >> item >> category;

            if (!fashion.count(category)) {
                fashion[category] = set<string>();
            }
            fashion[category].insert(item);
        }
        int answer = 1;
        for (auto x : fashion) {
            answer *= (x.second.size() + 1);
        }
        cout << answer - 1 << endl;
    }

    return 0;
}