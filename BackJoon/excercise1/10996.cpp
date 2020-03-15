#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    if (N == 1) {
        cout << "*";
        return 0;
    }

    for (int j = 0; j < 2 * N; j++) {
        for (int i = 0; i < N; i++) {
            // row가 짝수라면
            if (j % 2 == 0) {
                if (i % 2 == 0) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            // row가 홀수라면
            else {
                if (i % 2 == 0) {
                    cout << " ";
                }
                else {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }

    return 0;
}