#include <iostream>
#include <queue>

using namespace std;

int main() {

    int numberCount, changeCount;
    cin >> numberCount >> changeCount;

    priority_queue<long long> q;
    for (int i = 0; i < numberCount; ++i) {
        long long tmp;
        cin >> tmp;
        q.push(-tmp);
    }

    for (int i = 0; i < changeCount; ++i) {
        long long first = q.top();
        q.pop();

        long long second = q.top();
        q.pop();

        q.push(first + second);
        q.push(first + second);
    }

    long long sum = 0;
    while (!q.empty()) {
        sum += q.top();
        q.pop();
    }

    cout << -sum << endl;

    return 0;
}