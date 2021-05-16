#include <iostream>
#include <string>

using namespace std;

int main() {

    string haystack, needle;
    cin >> haystack >> needle;

    bool exitFlag = false;
    int haystackIndex = 0, foundLength = 0;
    for (auto c : needle) {
        for (int i = haystackIndex; i < haystack.size(); ++i) {
            if (haystack.at(i) == c) {
                haystackIndex = i+1;
                foundLength++;
                break;
            }
            else if (!isdigit(haystack.at(i))) {
                exitFlag = true;
            }
        }
        if (exitFlag) break;
    }

    if (foundLength == needle.size()) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}