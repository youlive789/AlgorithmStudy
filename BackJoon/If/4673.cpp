#include <iostream>


int calcSumNumber(const int& number) {
    int sum = 0;
    int temp = number;

    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }
    sum += number;

    return sum;
}

int main() {
    bool numberTable[10001];
    for (int index = 0; index <= 10001; ++index) {
        numberTable[index] = true;
    }

    // <= 10000 범위에서 완전탐색
    for (int index = 1; index <=10001; ++index) {
        int calcNumber = calcSumNumber(index);
        if ( calcNumber <= 10000) {
            numberTable[calcNumber] = false;
        }
    }

    // 셀프넘버 출력
    for (int index = 1; index <=10000; ++index) {
        if (numberTable[index]) {
            std::cout << index << std::endl;
        }
    }

    return 0;
}