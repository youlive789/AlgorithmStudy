#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int count;
    cin >> count;

    vector<int> container;
    while (count--) {
        int tmp;
        cin >> tmp;
        container.push_back(tmp);
    }

    sort(container.begin(), container.end(), greater<int>());

    for (auto ele : container) {
        cout << ele << "\n";
    }

    return 0;
}