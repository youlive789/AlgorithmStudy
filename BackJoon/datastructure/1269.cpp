#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    int aCount, bCount;
    cin >> aCount >> bCount;

    set<int> a, b, c;

    while (aCount--) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }

    while (bCount--) {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }

    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));

    cout << c.size() << endl;

    return 0;
}