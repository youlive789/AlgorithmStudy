#include <iostream>

using namespace std;

int main() {

    int sums = 0;
    for (int idx = 0; idx < 4; idx++) {
        int temp;
        cin >> temp;
        sums += temp;
    }

    cout << sums / 60 << endl;
    cout << sums % 60 << endl;

    return 0;
}