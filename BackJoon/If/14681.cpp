#include <iostream>

using namespace std;

int main() {

    int x, y;
    cin >> x >> y;

    bool _x = x > 0;
    bool _y = y > 0;
    if (_x && _y) {
        cout << 1 << endl;
    }
    else if (!_x && _y) {
        cout << 2 << endl;
    }
    else if (!_x && !_y) {
        cout << 3 << endl;
    }
    else if (_x && !_y) {
        cout << 4 << endl;
    }

    return 0;
}