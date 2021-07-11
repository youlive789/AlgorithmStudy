#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VAL 100001

int poll[MAX_VAL];
int dp[MAX_VAL];

int main() {

    int pollCount;
    cin >> pollCount;

    for (int idx = 1; idx <= pollCount; ++idx) {
        cin >> poll[idx];
    }

    fill_n(dp, MAX_VAL, 1);

    int answer = 1;
    for (int idx = 1; idx <= pollCount; ++idx) {
        int code = poll[idx];
        for (int j = 1; j < idx; ++j) {
            int value = poll[j];
            if (code > value) {
                dp[idx] = max(dp[idx], dp[j] + 1);
            }
        }
        answer = max(answer, dp[idx]);
    }

    cout << pollCount - answer << endl;

    return 0;
}