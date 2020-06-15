#include <iostream>

using namespace std;

int divisorSum(int n) {
    int sum = 0;
    for (int i = 1; i < n - 1; i++) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

int main() {

    int answer = 0;
    for (int num = 1; num <= 10000; num++) {
        int d = divisorSum(num);
        if (num == divisorSum(d) && d != num) {
            answer += num;
        }
    }

    cout << answer << endl;

    return 0;
}