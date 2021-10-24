#include <iostream>
#include <string>

using namespace std;

int main() {

    int length;
    cin >> length;

    string target;
    bool isEven = length % 2 == 0 ? true : false;
    if (isEven) {
        for (int i = 0; i < length; ++i) {
            target += 'a';
        }
    }
    else {
        for (int i = 0; i < length; ++i) {
            if (i == (length / 2)) {
                target += 'b';
            }
            else {
                target += 'a';
            }
        }
    }

    cout << target << endl;

    return 0;
}