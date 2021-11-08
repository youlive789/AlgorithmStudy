#include <iostream>
#include <algorithm>

using namespace std;

int series[1000000];
int dp[1000000] = {0};

int main() {

    int seriesSize;
    cin >> seriesSize;
    for (int i = 0; i < seriesSize; ++i) {
        cin >> series[i];
    }

    int answer = 0;
    for (int i = 0; i < seriesSize; ++i) {
        int now = 0;
        for (int j = 0; j < i; ++j) {
            if (series[i] > series[j]) {
                now = max(now, dp[j]);
            }
        }
        dp[i] = now + 1;
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}