#include <iostream>
#include <queue>

using namespace std;

int main() {
    unsigned long long initNumber, targetNumber;
    cin >> initNumber >> targetNumber;

    queue<pair<unsigned long long, unsigned long long>> q;
    q.push(make_pair(initNumber, 1));

    unsigned long long answer = 999999;
    while (!q.empty()) {
        pair<unsigned long long, unsigned long long> poped = q.front();
        q.pop();

        if (poped.first == targetNumber) {
            answer = min(answer, poped.second);
            break;
        }
        
        unsigned long long mul = poped.first * 2;
        unsigned long long oneAdd = poped.first * 10 + 1;

        if (mul <= targetNumber) {
            q.push(make_pair(mul, poped.second + 1));
        }

        if (oneAdd <= targetNumber) {
            q.push(make_pair(oneAdd, poped.second + 1));
        }
    }

    if (answer != 999999) {
        cout << answer << endl;
    }
    else {
        cout << -1 << endl;
    }
}