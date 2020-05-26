#include <iostream>

using namespace std;

int main() {

    // 1000보다 작은 3 또는 5의 배수를 모두 더하기
    int sum = 0;
    for (int num = 3; num < 1000; num++) {
        if (num % 3 == 0 || num % 5 == 0) {
            sum += num;
        }
    }
    cout << sum << endl;

    return 0;
}