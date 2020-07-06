#include <iostream>

using namespace std;

unsigned long cache[100000];

unsigned long dfs(short number) {

    if (number == 0) {
        return 1;
    }

    if (cache[number]) {
        return cache[number];
    }
    else {
        unsigned long sum = 0;
        for (int idx = 1; idx <= number; idx++) {
            sum += cache[number - idx] = dfs(number - idx);
        }

        return sum;
    }
}

int main() {

    short number;
    cin >> number;

    cout << dfs(number) - 1 << endl;

    return 0;
}