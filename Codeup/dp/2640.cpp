#include <iostream>

using namespace std;

int cache[100000000];

int mul(int n, int k) {
    if (k == 0) {
        return 1;
    }
    else if (k == 1) {
        return n;
    }
    else {
        int oddTrigger = 0;
        if (k % 2 == 1) oddTrigger = 1;

        long long left, right;

        if (cache[(k / 2) + oddTrigger]) {
            left = cache[(k / 2) + oddTrigger];
        }
        else {
            cache[(k / 2) + oddTrigger] = left = mul(n, (k / 2) + oddTrigger);    
        }

        if (cache[(k / 2)]) {
            right = cache[(k / 2)];
        }
        else {
            cache[(k / 2)] = right = mul(n, (k / 2));    
        }

        return (left * right) %  1000000007;
    }
}

int main() {

    int n, k;
    cin >> n >> k;
    cout << mul(n, k) << endl;

    return 0;
}
// 100000 100000000