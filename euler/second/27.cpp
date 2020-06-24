#include <iostream>

using namespace std;

/*
n^2 + a*n + b
n(n + a) + b = C
*/

bool isPrime(const int& number) {
    if (number == 1) {
        return false;
    }
    else if (number == 2) {
        return true;
    }

    for (int idx = 3; idx*idx < number; idx++) {
        if (number % idx == 0) return false;
    }

    return true;
}

int main() {

    int n = 0;
    int currentCnt = 0, answerA = 0, answerB = 0; 

    for (int a = -999; a <= 999; a++) {
        for (int b = -999; b <= 999; b++) {

            int cnt = 0;
            int target = n * (n + a) + b;

            while (isPrime(target) && target > 0) {
                cnt++;
                n++;
                target = n * (n + a) + b;
            }
            
            if (cnt > currentCnt) {
                currentCnt = cnt;
                answerA = a;
                answerB = b;
            }

            n = 0;
        }
    }
    cout << answerA << " " << answerB << endl;
    cout << answerA * answerB << endl;

    return 0;
}