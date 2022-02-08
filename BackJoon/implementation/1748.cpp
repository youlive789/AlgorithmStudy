#include <iostream>

using namespace std;

int main() {

    int target;
    cin >> target;

    int sum = 0, divider = 10, n = 1;
    for (int i = 1; i <= target; ++i) {
        if (i / divider >= 1) {
            divider *= 10;
            n++;
        }
        sum += n;
    }

    cout << sum << endl;

    return 0;
}