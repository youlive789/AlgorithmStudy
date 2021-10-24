#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {

    int index = 1;
    while (true) {
        int r, w, l;
        cin >> r;
        if (r == 0) break;
        cin >> w >> l;

        double diagonal = sqrt(w*w + l*l);
        if (2*r >= diagonal) {
            cout << "Pizza " << index <<" fits on the table." << "\n";
        }
        else {
            cout << "Pizza " << index <<" does not fit on the table." << "\n";
        }

        index++;
    }

    return 0;
}