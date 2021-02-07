#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    for (int idx = 0; idx < caseCount; idx++) {
        int nameSize;
        cin >> nameSize;
        vector<pair<string, int>> nameTable;

        for (int i = 0; i < nameSize; i++) {
            unsigned long long salary;
            string name;
            cin >> salary >> name;
            nameTable.push_back(make_pair(name, salary));
        }

        sort(nameTable.begin(), nameTable.end(), [](pair<string, int> a, pair<string, int> b){
            if (a.second < b.second) {
                return false;
            }
            else {
                return true;
            }
        });

        cout << nameTable[0].first << "\n";

    }

    return 0;
}