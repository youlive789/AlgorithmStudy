#include <iostream>
#include <string>

using namespace std;

int main() {

    while (true) {
        string target;
        getline(cin, target);
        if (target == "#") break;

        long long checksum = 0;
        for (int idx = 0; idx < target.size(); idx++) {
            char character = target[idx];
            if (character != ' ') {
                checksum += (target[idx] - 'A' + 1) * (idx + 1);
            }
        }
        cout << checksum << '\n';
    }

    return 0;
}