#include <iostream>

using namespace std;

int eratos(const int& size) {

    if (size == 1) return 1;

    bool eratosGrid[2*size + 1];
    for (int index = 0; index < 2*size + 1; index++) {
        eratosGrid[index] = true;
    }

    // 에라토스 테네스의 채
    int i = 2, j = 4;
    while ( i * i <= 2*size) {
        if (eratosGrid[i]) {
            while (j <= 2*size) {
                eratosGrid[j] = false;
                j += i;
            }
        }
        i += 1;
        j = i * 2;
    }

    int count = 0;
    for (int index = size + 1; index <= 2*size; index++) {
        if (eratosGrid[index]) {
            count++;
        }
    }

    return count;
}

int main() {

    int inputNumber = 1;
    while (inputNumber) {
        cin >> inputNumber;
        if (inputNumber == 0) break;
        cout << eratos(inputNumber) << endl;
    }

    return 0;
}