#include <iostream>

using namespace std;

int cache[100000];

int dfs(int number) {

    if (number == 0) {
        return 1;
    }

    int sum = 0;
    for (int idx = 1; idx <= number; idx++) {
        sum += dfs(number - idx);
    }

    return sum;
}

int main() {

    int number;
    cin >> number;

    cout << dfs(number) - 1 << endl;

    return 0;
}