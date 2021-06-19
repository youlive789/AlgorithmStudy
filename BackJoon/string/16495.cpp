#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    string column;
    cin >> column;

    long long answer = 0;
    int length = column.length();
    for (auto pos : column) {
        answer += (pos - 'A' + 1) * (long long) pow(26, length-1);
        length--;
    }

    cout << answer << endl;

    return 0;
}