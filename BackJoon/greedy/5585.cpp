#include <iostream>

using namespace std;

int main() {

    // 500, 100, 50, 10, 5, 1
    int price;
    cin >> price;

    int answer = 0;
    int change = 1000 - price;

    while (change > 0) {
        if (change / 500 > 0) {
            answer += 1;
            change -= 500;
        }
        else if (change / 100 > 0) {
            answer += 1;
            change -= 100;
        }
        else if (change / 50 > 0) {
            answer += 1;
            change -= 50;
        }
        else if (change / 10 > 0) {
            answer += 1;
            change -= 10;
        }
        else if (change / 5 > 0) {
            answer += 1;
            change -= 5;
        }
        else if (change > 0) {
            answer += 1;
            change -= 1;
        }
    }

    cout << answer << endl;

    return 0;
}