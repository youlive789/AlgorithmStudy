#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    for (int j = 0; j < 2 * N - 1; j++) {
        int size = 0;
        if (j < N - 1) {
            size = 2 * N - 1 - j;
        }
        else if (j >= N - 1) {
            size = j - N + 2;
        }
        for (int i = 0; i < size; i++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}