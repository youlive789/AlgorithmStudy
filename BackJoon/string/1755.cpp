#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, string> numberMap = {
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"},
    {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"},
    {8, "eight"}, {9, "nine"}
};

int main() {

    int m, n;
    cin >> m >> n;

    map<int, string> container;
    for (int i = m; i <= n; ++i) {
        string target = "";
        int first = i / 10;
        int second = i % 10;
        
        if (first != 0) {
            target += numberMap[first] + " ";
        }
        target += numberMap[second];

        container[i] = target;
    }

    vector<pair<int, string>> vec(container.begin(), container.end());
    sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b){
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int counter = 0;
    for (auto pair : vec) {
        cout << pair.first << " ";
        counter++;
        if (counter % 10 == 0) cout << "\n";
    }

    return 0;
}