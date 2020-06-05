#include <iostream>
#include <vector>

using namespace std;

vector<int> target;


int main() {

    int n, k;
    cin >> n >> k;
    k--;
    target.push_back(n);
    while (k--) {
        for (int idx = 0; idx < target.size(); idx++) {
            target[idx] *= n;
        }
            
        for (int idx = 0; idx < target.size(); idx++) {
            if (target[idx] >= 10) {
                if (idx == target.size() - 1) {
                    int tmp = target[idx] / 10;
                    target.push_back(tmp);
                    target[idx] %= 10;
                }
                else {
                    int tmp = target[idx] / 10;
                    target[idx+1] += tmp;
                    target[idx] %= 10;
                }
            }
        }
    }

    for (int idx = target.size() - 1; idx >= 0; idx--) {
        cout << target[idx];
    }
    cout << endl;

    return 0;
}
// 100000 100000000