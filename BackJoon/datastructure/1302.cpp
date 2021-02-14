#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    int count;
    cin >> count;

    map<string, int> m;

    for (int i = 0; i < count; i++) {
        string tmp;
        cin >> tmp;

        if (!m.count(tmp)) {
            m[tmp] = 1;
        }
        m[tmp] += 1;
    }

    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [] (pair<string, int> a, pair<string, int> b) {
        if (a.second > b.second) {
            return false;
        }
        else if (a.second < b.second) {
            return true;
        }
        else {
            return a.first < b.first;
        }
    });

    pair<string, int> max_val = *max_element(vec.begin(), vec.end(), [](auto a, auto b){
        return a.second < b.second;
    });

    for (auto item : vec) {
        if (item.second == max_val.second) {
            cout << item.first << endl;
            break;
        }
    }

    return 0;
}