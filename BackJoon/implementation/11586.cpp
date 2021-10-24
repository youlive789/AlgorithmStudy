#include <iostream>
#include <algorithm>

using namespace std;

char phase[100][100];

int main() {

    int size;
    cin >> size;

    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < size; ++k) {
            cin >> phase[i][k];
        }
    }

    int cmd;
    cin >> cmd;

    switch (cmd)
    {
    case 2:
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size / 2; ++k) {
                swap(phase[i][k], phase[i][size - k - 1]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size / 2; ++k) {
                swap(phase[k][i], phase[size - k - 1][i]);
            }
        }
        break;
    default:
        break;
    }

    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < size; ++k) {
            cout << phase[i][k];
        }
        cout << "\n";
    }

    return 0;
}