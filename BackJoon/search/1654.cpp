#include <iostream>
#include <algorithm>

using namespace std;

long long lines[10001];

bool validLineCount(long long mid, int lineCount, int targetCount) {
    int count = 0;
    for (int idx = 0; idx < lineCount; ++idx) {
        count += (lines[idx] / mid);
    }

    if (count >= targetCount) {
        return true;
    }
    return false;
}

int main() {

    int lineCount, targetCount;
    cin >> lineCount >> targetCount;

    for (int idx = 0; idx < lineCount; ++idx) {
        cin >> lines[idx];
    }

    long long result = 0;
    long long low = 1, high = *max_element(lines, lines + lineCount);
    while (low <= high) {

        long long mid = (low + high) / 2;

        if (validLineCount(mid, lineCount, targetCount)) {
            if (result < mid) {
                result = mid;
            }
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    
    return 0;
}