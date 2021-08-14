#include <iostream>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        int numCount;
        cin >> numCount;

        int sum = 0;
        for (int i = 0; i < numCount; ++i) {
            int num;
            cin >> num;
            sum += num;
        }
        cout << sum << "\n";
    }
}