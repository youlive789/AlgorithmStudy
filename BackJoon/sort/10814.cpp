#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    // 나이순으로 먼저 정렬한다.
    if (a.first != b.first) {
        return a.first < b.first;
    }
    // 나이가 같다면
    else {
        // 가입 순서로 정렬한다.
        return a.second < b.second;
    }
    return false;
}

int main() {

    int cases;
    cin >> cases;
    vector<pair<int, int>> container;
    vector<string> names;

    int index = 0;
    while (cases--) {
        int age;
        string name;
        scanf("%d", &age);
        cin >> name;

        container.push_back(make_pair(age, index));
        names.push_back(name);
        index++;
    }

    sort(container.begin(), container.end(), compare);

    for (auto ele : container) {
        printf("%d %s\n", ele.first, names[ele.second].c_str());
        //cout << ele.first << " " << names[ele.second] << endl;
    }

    return 0;
}