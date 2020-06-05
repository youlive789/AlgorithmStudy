#include <iostream>
#include <vector>

using namespace std;

int cache[100000003];

int mul(int n, int k) {
    if (k == 1) {
        return n;
    }
    else {
        return n * mul(n, k-1);
    }
}

int main() {

    int n, k;
    cin >> n >> k;


    return 0;
}
// 100000 100000000