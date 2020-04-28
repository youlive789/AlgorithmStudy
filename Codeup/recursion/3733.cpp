#include <iostream>

using namespace std;

int currentNum = 99999;
int currentCnt = -99999;

bool cache[10000001][1000][10000001] = {false};

void colatz(int n, int cnt, int origin) {
    if (n == 1) {
        if (cnt > currentCnt) {
            currentCnt = cnt;
            currentNum = origin;
        }
        return;
    }

    if (cache[n][cnt][origin]) return;

    if (n % 2 == 1) {
        colatz(3 * n + 1, cnt + 1, origin);
    }
    else {
        colatz(n / 2, cnt + 1, origin);
    }
}

int main() {

    int a, b;
    cin >> a >> b;

    for (a; a <= b; a++) {
        cout << a << endl;
        colatz(a, 1, a);
    }

    cout << currentNum << " " << currentCnt << endl;

    return 0;
}