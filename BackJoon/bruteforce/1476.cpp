#include <iostream>

using namespace std;

int main() {

    int elimit, slimit, mlimit;
    cin >> elimit >> slimit >> mlimit;

    int year = 1;
    int e = 1, s = 1, m = 1;
    while (true) {

        if (e == elimit && s == slimit && m == mlimit) break;

        year++;
        e++;
        s++;
        m++;

        if (e > 15) {
            e = 1;
        }

        if (s > 28) {
            s = 1;
        }

        if (m > 19) {
            m = 1;
        }
        
    }

    cout << year << endl;

    return 0;
}