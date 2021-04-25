#include <iostream>

using namespace std;

int cache[51][51][51];

int w(int a, int b, int c) {

    if (a >= 0 && b >= 0 && c >= 0 && cache[a][b][c]) {
        return cache[a][b][c];
    }
    else {
        if (a <= 0 || b <= 0 || c <= 0) {
            return 1;
        }

        if (a > 20 || b > 20 || c > 20) {
            cache[20][20][20] = w(20, 20, 20);
            return cache[20][20][20];
        }

        if (a < b && b < c) {
            cache[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
            return cache[a][b][c];
        }

        cache[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return cache[a][b][c];
    }
}

int main() {

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) break;

        int result = w(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
    }

    return 0;
}