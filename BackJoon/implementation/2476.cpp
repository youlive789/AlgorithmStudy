#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    int answer = 0;
    while (cases--) {
        int a, b, c;
        cin >> a >> b >> c;

        int sum = 0;
        if (a == b && b == c) {
            sum += 10000;
            sum += a * 1000;
            answer = max(sum, answer);
            continue;
        }

        if (a == b) {
            sum += 1000;
            sum += a * 100;
            answer = max(sum, answer);
            continue;
        } else if (b == c) {
            sum += 1000;
            sum += b * 100;
            answer = max(sum, answer);
            continue;
        } else if (c == a) {
            sum += 1000;
            sum += a * 100;
            answer = max(sum, answer);
            continue;
        } else {
            int temp = max(a, b);
            temp = max(temp, c);
            sum += temp * 100;
            answer = max(sum, answer);
            continue;
        }
    }

    cout << answer << endl;

    return 0;
}