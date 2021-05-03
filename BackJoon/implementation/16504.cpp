#include <iostream>

using namespace std;

int main() {

    int count;
    cin >> count;

    long long sum = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
    }

    cout << sum << endl;

    return 0;
}