#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int count;
    cin >> count;

    int a[3];

    for (int idx = 1; idx <= count; ++idx) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);

        cout << "Scenario #" << idx << ":\n";
        if (a[2] * a[2] == (a[1] * a[1]) + (a[0] * a[0])) {
            cout << "yes\n\n";
        }
        else {
            cout << "no\n\n";
        }
    }

    return 0;
}