#include <iostream>
#include <string>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    unsigned long long answer = 0;
    for (char a_char: a) {
        for (char b_char: b) {
            answer += (a_char - 48) * (b_char - 48);
        }
    }

    cout << answer << endl;

    return 0;
}