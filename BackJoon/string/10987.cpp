#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<char> charContainer = {'a', 'e', 'i', 'o', 'u'};

    string target;
    cin >> target;

    int ans = 0;
    for (int i = 0; i < target.size(); ++i) {
        auto it = find(charContainer.begin(), charContainer.end(), target.at(i));
        if (it != charContainer.end()) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}