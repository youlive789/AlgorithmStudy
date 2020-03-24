#include <iostream>

using namespace std;

int getMovie(const int& number) {
    int start = 665;
    int count = number;
    while (true) {
        if (count == 0) break;
        start++;
        int temp = start;
        while (temp) {            
            if (temp % 1000 == 666) {
                count--;
                break;
            }
            else {
                temp /= 10;
            }
        }
    }
    return start;
}

int main() {

    int testNumber;
    cin >> testNumber;
    cout << getMovie(testNumber) << endl;

    return 0;
}