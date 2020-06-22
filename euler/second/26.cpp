#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numlist;

    int q = 10, r = 0, t = 3;
    for (int t = 1; t < 10; t ++) {
        numlist.push_back(q / t);
        q = q % t * 10;
    }
    
    for (auto t : numlist) {
        cout << t;
    }
    cout << endl;

    return 0;
}