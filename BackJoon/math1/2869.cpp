#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int ascentLength, descentLength, targetLength;
    cin >> ascentLength >> descentLength >> targetLength;

    if (descentLength >= ascentLength) {
        cout << 0 << endl;
        return 0;
    }

    int days = (targetLength - descentLength - 1) / (ascentLength - descentLength) + 1;
    if (days == 0) days++;
    cout << days << endl;

    return 0;
}