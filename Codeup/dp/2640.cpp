#include <iostream>

using namespace std;

unsigned int cache[50000001];

unsigned int mul(unsigned int n, unsigned int k) {
    if (k == 0) {
        return 1;
    }
    else if (k == 1) {
        return n;
    }
    else {
        unsigned int oddTrigger = 0;
        if (k % 2 == 1) oddTrigger = 1;

        unsigned long long left, right;

        // cout << (k / 2) + oddTrigger << " " << (k / 2)  << endl;

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

    unsigned int n, k;
    cin >> n >> k;
    cout << mul(n, k) << endl;

    return 0;
}
// 100000 100000000