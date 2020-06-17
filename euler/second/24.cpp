#include <iostream>
#include <string>

using namespace std;

bool numTable[10];

void comb(int cnt, string p) {
    if (cnt == 3) {
        cout << p << endl;
    }

    int index = (p != "") ? p[p.size()-1] - '0' : 0;

    for (int idx = index; idx < 3; idx++) {
        
            numTable[idx] = true;
            comb(cnt + 1, p.append(to_string(idx)));
            numTable[idx] = false;
                
    }
}

int main() {

    comb(0, "");

    return 0;
}