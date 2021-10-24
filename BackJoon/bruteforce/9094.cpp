#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int count;
    cin >> count;

    while (count--) {
        int n, m;
        cin >> n >> m;

        int answer = 0;
        for (double b = 2; b < n; b++) {
            for (double a = 1; a < b; a++) {
                double result = (pow(b, 2) + pow(a, 2) + m) / (a * b);
                if (result - (int)result == 0) {
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}