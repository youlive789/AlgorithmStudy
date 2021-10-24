#include <iostream>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    if (m <= 2) {
        cout << "NEWBIE!" << endl;
    }
    else if (m <= n && m > 2) {
        cout << "OLDBIE!" << endl;
    }
    else {
        cout << "TLE!" << endl;
    }

    return 0;
}