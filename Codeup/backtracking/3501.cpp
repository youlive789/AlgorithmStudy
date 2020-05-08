#include <iostream>
#include <algorithm>

using namespace std;

int colors[15][3] = {-1};

int rgb(int cnt, int sum, int cases, int last) {
    if (cnt >= cases) {
        return sum;
    }

    int r, b, m;
    switch (last) {
        case 0:
            m = min(rgb(cnt + 1, sum + colors[cnt][1], cases, 1), rgb(cnt + 1, sum + colors[cnt][2], cases, 2));
            break;
        case 1:
            m = min(rgb(cnt + 1, sum + colors[cnt][0], cases, 0), rgb(cnt + 1, sum + colors[cnt][2], cases, 2));
            break;
        case 2:
            m = min(rgb(cnt + 1, sum + colors[cnt][0], cases, 0), rgb(cnt + 1, sum + colors[cnt][1], cases, 1));
            break;
        default: 
            r = min(rgb(cnt + 1, sum + colors[cnt][0], cases, 0), rgb(cnt + 1, sum + colors[cnt][1], cases, 1));
            b = min(r, rgb(cnt + 1, sum + colors[cnt][2], cases, 2));
            m = min(r, b);
            break;
    }

    return m;
}

int main() {

    int cases;
    cin >> cases;

    for (int idx = 0; idx < cases; idx++) {
        cin >> colors[idx][0] >> colors[idx][1] >> colors[idx][2];
    }

    cout << rgb(0, 0, cases, -1) << endl;

    return 0;
}