#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    vector<int> a;
    a.push_back(2);

    int cases = 999;
    while (cases--) {
        for (int idx = 0; idx < a.size(); idx++) a[idx] *= 2;
        for (int idx = 0; idx <= a.size() - 1; idx++) {
            if (a[idx] >= 10) {
                if (idx == a.size() - 1) {
                    int tmp = a[idx] / 10;
                    a.push_back(tmp);
                    a[idx] %= 10;
                }
                else {
                    int tmp = a[idx] / 10;
                    a[idx+1] += tmp;
                    a[idx] %= 10;
                }
            }
        }
    }

    int sum = 0;
    for (int num : a) {
        sum += num;
    }

    cout << sum << endl;

    return 0;
}