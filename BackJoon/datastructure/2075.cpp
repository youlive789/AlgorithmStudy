#include <iostream>
#include <queue>

using namespace std;

int main() {

    priority_queue<long long> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        long long temp;
        cin >> temp;
        pq.push(-temp);
        if (pq.size() > n) {
            pq.pop();
        }
        
    }

    cout << -pq.top() << endl;

    return 0;
}