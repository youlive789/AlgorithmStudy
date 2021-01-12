#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isPrime(const int& number) {
    if (number == 1) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    bool answer = true;
    int limit = static_cast<int>(sqrt(number));
    for (int idx = 2; idx <= limit; idx++) {
        if (number % idx == 0) {
            answer = false;
            break;
        }
    }

    return answer;
}

bool isPalindrome(const int& number) {
    int targetNumber = number;
    string target = to_string(targetNumber);
    
    int length = target.length();
    int halfLength = length / 2;

    bool answer = true;
    for (int idx = 0; idx < halfLength; idx++) {
        if (target[idx] != target[length - idx - 1]) {
            answer = false;
            break;
        }
    }

    return answer;
}

int main() {

    int number;
    cin >> number;

    while (true) {
        if (isPrime(number) && isPalindrome(number)) {
            break;
        }
        number++;
    }

    cout << number << endl;

    return 0;
}