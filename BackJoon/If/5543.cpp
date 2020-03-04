#include <iostream>

int main() {
    using namespace std;

    int burgers[3];
    int beverages[2];

    for (int index = 0; index < 3; index++) {
        cin >> burgers[index];
    }

    for (int index = 0; index < 2; index++) {
        cin>> beverages[index];
    }
    
    int answer = 99999999;
    int currentSum = 0;
    for (auto burger : burgers) {
        for (auto beverage : beverages) {
            currentSum = burger + beverage - 50;
            if (answer > currentSum) answer = currentSum;
        }
    }

    cout << answer << endl;
}