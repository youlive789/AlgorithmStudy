#include <iostream>

using namespace std;

int countTable[1001] = {0};

int main() {

    int mean = 0;
    for (int i = 0; i < 10; ++i) {
        int inputNumber;
        cin >> inputNumber;

        countTable[inputNumber]++;
        mean += inputNumber;
    }
    mean /= 10;

    int mode = 0, count = 0;
    for (int i = 0; i < 1001; ++i) {
        
        if (countTable[i] > count) {
            mode = i;
            count = countTable[i];
        }
    }

    cout << mean << endl;
    cout << mode << endl;

    return 0;
}