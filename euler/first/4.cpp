#include <iostream>
#include <string>

using namespace std;

bool palindrome(int num) {

    string target = to_string(num);
    int targetSize = target.size();

    string front, back;
    if (targetSize % 2 == 0) {
        front = target.substr(0, targetSize / 2);
        back = target.substr(targetSize / 2, targetSize / 2);
    }
    else {
        front = target.substr(0, targetSize / 2);
        back = target.substr(targetSize / 2 + 1, targetSize / 2);
    };

    int frontIdx = 0, backIdx = (targetSize / 2) - 1;
    while (backIdx >= 0) {
        if (front[frontIdx] != back[backIdx]) return false;
        frontIdx++;
        backIdx--;
    }

    return true;
}

int main() {

    int max = -999999;
    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > 99; j--) {
            int num = i * j;
            if (palindrome(num)) {
                if (num > max) max = num;
            }
        }
    }

    cout << max << endl;

    return 0;
}