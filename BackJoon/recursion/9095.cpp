#include <iostream>

using namespace std;

int sumMethod(int number) {

    int answer = 0;

    // 기저사례
    if (number == 1) return 1;
    if (number == 2) return 2;
    if (number == 3) return 4;

    if (number == 0) {
        return 1;
    }
    else if (number < 0) {
        return 0;
    }

    for (int idxChoice = 1; idxChoice <= 3; idxChoice++) {
        answer += sumMethod(number - idxChoice);
    }

    return answer;
}

int main() {

    int cases;
    cin >> cases;

    while (cases--) {
        int number;
        cin >> number;
        cout << sumMethod(number) << endl;
    }

    return 0;
}