#include <iostream>

using namespace std;

char origin[50][50];
char enlarged[250][250];

int main() {

    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> origin[i][j];
        }
    }

    int lr = r * zr;
    int lc = c * zc;
    for (int i = 0; i < lr; ++i) {
        for (int j = 0; j < lc; ++j) {
            enlarged[i][j] = origin[i / zr][j / zc];
            cout << enlarged[i][j];
        }
        cout << "\n";
    }

    return 0;
}