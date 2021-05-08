#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<long long, long long> val;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int count;
    scanf("%d", &count);

    priority_queue<val, vector<val>, greater<val>> q;

    while (count--) {
        long long number;
        scanf("%lld", &number);

        if (number != 0) {
            val value = make_pair(abs(number), number);
            q.push(value);
        }
        else {
            if (q.empty()) {
                printf("0\n");
            }
            else {
                printf("%lld\n", q.top().second);
                q.pop();
            }
        }
    }

    return 0;
}