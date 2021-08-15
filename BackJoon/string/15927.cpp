#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string target;
    cin >> target;

    int length = -1;
    for (int idx = 0; idx < target.size(); ++idx) {
        for (int subSize = 1; subSize <= target.size() - idx; ++subSize) {

            string currentSubstring = target.substr(idx, subSize);
            for (int i = 0; i < currentSubstring.size() / 2; ++i) {
                if (currentSubstring[i] != currentSubstring[currentSubstring.size() - i - 1]) {
                    length = max(length, subSize);
                    break;
                }
            }
        }
    }

    cout << length << endl;

    return 0;
}