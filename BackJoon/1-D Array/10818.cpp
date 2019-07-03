#include <iostream>

using namespace std;

int main() {

    int numberCount;
    cin >> numberCount;

    // 입력처리
    int numberList[numberCount];
    for (int index = 0; index < numberCount; ++index) {
        int temp;
        cin >> temp;
        numberList[index] = temp;
    }

    // 최대 최소
    int min = numberList[0];
    int max = numberList[0];
    for (int index = 0; index < numberCount; ++index) {
        if (max < numberList[index]) {
            max = numberList[index];
        }

        if (min > numberList[index]) {
            min = numberList[index];
        }
    }

    cout << min << " " << max << endl;

    return 0;
}