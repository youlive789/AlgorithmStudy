#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

    while (true) {
        int count;
        cin >> count;

        if (count == 0) break;

        vector<pair<string,string>> list;
        for (int idx = 0; idx < count; ++idx) {
            string origin;
            cin >> origin;

            string lower = origin;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            
            list.push_back(make_pair(lower, origin));
        }

        sort(list.begin(), list.end());
        cout << list[0].second << "\n";
    }

    return 0;
}