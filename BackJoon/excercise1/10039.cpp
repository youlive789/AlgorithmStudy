#include <iostream>

using namespace std;

int main() {
    
    int sum = 0, count = 5;
    int score;
    while (count--) {
        cin >> score;
        if (score < 40) score = 40;
        sum += score;
    }
    sum /= 5;
    cout << sum << endl;

    return 0;
}