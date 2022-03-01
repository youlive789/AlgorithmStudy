#include <iostream>
#include <algorithm>

using namespace std;

int numbers[3];

int main() {

    for (int i = 0; i < 3; ++i) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + 3);

    for (int i = 0; i < 3; ++i) {
        cout << numbers[i] << " ";
    }

    return 0;
}