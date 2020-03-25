#include <iostream>

using namespace std;

int main() {

    int cases;
    cin >> cases;
    int* numbers = new int[cases];

    int index = 0;
    int length = cases;
    while (cases--) {
        cin >> numbers[index];
        index++;
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (int idx = 0; idx < length; idx++) {
        cout << numbers[idx] << endl;
    }

    delete[] numbers;
    return 0;
}