#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string & a, const string & b) {
    // 길이를 비교하여 짧은 문자열이 우선되도록 한다.
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    // 길이가 같다면
    else {
        // 문자를 비교하다 작은값이 우선되도록 한다.
        for (int idx = 0; idx < a.size(); idx++) {
            if (a.at(idx) == b.at(idx)) continue;
            return a.at(idx) < b.at(idx);
        }
    }

    return false;
}

int main() {

    int cases;
    cin >> cases;
    vector<string> container;

    while (cases--) {
        string temp;
        cin >> temp;
        container.push_back(temp);
    }

    sort(container.begin(), container.end(), compare);

    string last;
    for (auto word : container) {
        if (word == last) continue;
        cout << word << endl;
        last = word;
    }

    return 0;
}