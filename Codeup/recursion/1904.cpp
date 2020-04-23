#include <iostream>

using namespace std;

void print(int idx, int last) {
    if (idx > last) return;
    if (idx % 2 == 1) {
        cout << idx << endl;
    }
    print(idx+1, last);
}

int main() {

    int start, last;
    cin >> start >> last;

    print(start ,last);

    return 0;
}