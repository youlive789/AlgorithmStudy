#include <iostream>

/**
 * 일반적인 더하기 함수
 * 1. 입력받은 숫자까지의 자연수가 필요하다.
 *  N, N-1, ... , 1 
 * 2. 해당 숫자들을 더하고 리턴한다.
*/
int sum(int number) {
    int sum = 0;
    while (number >= 1) {
        sum += number;
        number--;
    }
    return sum;
}

/**
 * 재귀호출 더하기 함수
 * 1. 입력받은 숫자까지의 수열을 구하는 과정을 재귀호출한다.
*/
int recursiveSum(const int& number) {
    if (number == 1) {
        return number;
    }
    return number + recursiveSum(number - 1);
}

/**
 * NOTE : 재귀호출을 설계할 때 입력과 반복부분을 먼저 생각해보자.
*/
int main() {

    using namespace std;
    cout << "일반적인 더하기 함수 : " << sum(10) << endl;
    cout << "재귀호출 더하기 함수 : " << recursiveSum(10) << endl;

    return 0;
}