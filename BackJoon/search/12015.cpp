#include <iostream>
#include <algorithm>

using namespace std;

int numbers[1000001];

int main() {

    int count;
    cin >> count;

    for (int idx = 0; idx < count; ++idx) {
        cin >> numbers[idx];
    }

    int lastValue = 0, length = 0;
    for (int idx = 0; idx < count; ++idx) {
        if (numbers[idx] > lastValue) {
            length++;
            lastValue = numbers[idx];
        }
    }

    cout << length << endl;

    return 0;
}