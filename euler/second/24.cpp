#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int globalCnt = 0;

void comb(int cnt, vector<int> p) {
    if (cnt == 10) {
        globalCnt++;
        if (globalCnt == 1000000) {
            for (int num : p) {
                cout << num;
            }
            cout << endl;
        }
        return;
    }

    for (int idx = 0; idx < 10; idx++) {
        if (p.size() == 0 || find(p.begin(), p.end(), idx) == p.end()) {
            p.push_back(idx);
            comb(cnt + 1, p);
            p.pop_back();
        }
    }
}

int main() {

    vector<int> p;
    comb(0, p);

    return 0;
}