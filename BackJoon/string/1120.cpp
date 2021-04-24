#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    int aLength = a.size();
    int bLength = b.size();
    int difference = bLength - aLength;

    int differScore = INT32_MAX;
    if (difference > 0) {
        for (int bIndex = 0; bIndex <= difference; ++bIndex) {
            int nowDifferScore = 0;
            for (int aIndex = 0; aIndex < aLength; ++aIndex) {
                if (a[aIndex] != b[bIndex + aIndex]) {
                    nowDifferScore++;
                }
            }
            differScore = min(differScore, nowDifferScore);
        }
    }
    else {
        int nowDifferScore = 0;
        for (int aIndex = 0; aIndex < aLength; ++aIndex) {
            if (a[aIndex] != b[aIndex]) {
                nowDifferScore++;
            }
        }
        differScore = min(differScore, nowDifferScore);
    }

    cout << differScore << endl;

    return 0;
}