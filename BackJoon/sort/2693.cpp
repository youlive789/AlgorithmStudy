#include <iostream>
#include <algorithm>

using namespace std;

int numbers[10];

int main() {

    int testCase;
    cin >> testCase;

    while (testCase--) {
        for (int i = 0; i < 10; ++i) {
            cin >> numbers[i];
        }

        sort(numbers, numbers + 10);

        cout << numbers[7] << "\n";
    }

    return 0;
}