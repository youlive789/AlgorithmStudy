#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {

    long long lineCount, targetCount;
    cin >> lineCount >> targetCount;

    vector<int> lines;
    lines.resize(lineCount);
    for (int idx = 0; idx < lineCount; ++idx) {
        scanf("%d", &lines[idx]);
    }

    long long low = 1, high = 539;
    while (low <= high) {
        long long mid = (low + high) / 2;

        long long splitedLineCount = 0;
        for (auto line : lines) {
            splitedLineCount += (line / mid);
        }

        if (splitedLineCount < targetCount) {
            high = mid;
        }
        else if (splitedLineCount > targetCount) {
            low = mid;
        }
        else {
            if (high - low <= 1) {
                break;
            }
            else {
                low = mid;
            }
        }   
    }

    cout << low << endl;

    return 0;
}