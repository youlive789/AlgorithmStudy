#include <iostream>

using namespace std;

int main() {
    int num = 21;
    while (true) {
        for (int i = 2; i <= 20; i++) {
            if (num % i != 0) break;
            if (i == 20) {
                cout << num << endl;
                exit(0);
            }
        }
        num++;
    }
    return 0;
}