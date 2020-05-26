#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float k;
    for (int i = 1; i <= 1000; i++) {
        for (int j = i + 1; j <= 1000; j++) {
            k = sqrt(pow(i,2) + pow(j, 2));
            if (k - (int)k == 0) {
                if (i + j + k == 1000) {
                    cout << (int)(i * j * k) << endl;
                    exit(0);
                }
            }
        }
    }

    return 0;
}