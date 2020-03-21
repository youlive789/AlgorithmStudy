#include <iostream>

using namespace std;

int cntPos(int number) {
    int cnt = 0;
    while (number) {
        number /= 10;
        cnt++;
    }
    return cnt;
}

int sumPosNumbers(int number) {
    int sum = 0;
    while (number) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {

    int number;
    cin >> number;
    
    int originPart = number - (cntPos(number) * 9);
    for (int index = originPart; index <= number; index++) {
        int testNum = index + sumPosNumbers(index);
        if (testNum == number) {
            cout << index << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}