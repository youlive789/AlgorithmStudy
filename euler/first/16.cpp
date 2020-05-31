#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    // double test = 11;
    // double tmp = floor(11/2);
    // double rest = test - (tmp * 2);
    // cout << tmp << " " << rest << endl;

    string a = "2";
    string b = "2";
    string c = "0";

    int cnt = 10;
    while (cnt--) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                c[i + j] += (a[i] - '0') * (b[j] - '0');
                if (c[i + j] - '0' > 9) {
                    c[i + j + 1] += ((c[i + j] - '0') / 10) + '0';
                    c[i + j] = ((c[i + j] - '0') % 10) + '0';
                }
            }
        }
        a = c;
        cout << a << " " << b << " " << c << endl;
    }

    cout << c << endl;

    // while (cnt--) {
    //     t.at()
    // }

    return 0;
}