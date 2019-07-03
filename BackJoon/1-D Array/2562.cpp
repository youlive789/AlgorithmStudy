#include <iostream>

using namespace std;

int main() {

    int numberCount = 9;
    int numberList[numberCount];

    for (int index = 0; index < numberCount; ++index) {
        cin >> numberList[index];
    }

    int max = numberList[0];
    int maxIndex = 0;
    for (int index = 1; index < numberCount; ++index) {
        if (max < numberList[index]) {
            max = numberList[index];
            maxIndex = index;
        }
    }

    cout << max << endl;
    cout << maxIndex + 1 << endl;

    return 0;
}