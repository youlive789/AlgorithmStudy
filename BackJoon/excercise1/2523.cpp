#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    for (int j = 0; j < (2 * N - 1); j++) {

        int size = 0;
        // index < N 이라면
        if (j < N) {
            // index 개수 만큼 별을 찍는다.
            size = j + 1;
        }
        // index >= N 이라면
        else {
            // (2N - 1) - index 만큼 별을 찍는다.
            size = 2 * N - 1 - j;
        }

        for (int i = 0; i < size; i++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}