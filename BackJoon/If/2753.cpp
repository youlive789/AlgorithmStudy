#include <iostream>

using namespace std;

int main() {

    int year;
    cin >> year;

    bool yoon = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

    if (yoon) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}