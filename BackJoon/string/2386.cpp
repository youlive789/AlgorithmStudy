#include <iostream>
#include <string>

using namespace std;

int main() {

    while (true) {
        string target;
        getline(cin, target);
        if (target == "#") break;

        int count = 0;
        char findChar = target[0];
        for (int idx = 1; idx < target.size(); ++idx) {
            if (target[idx] == findChar || target[idx] == findChar-32) {
                count++;
            }
        }

        cout << findChar << " " << count << "\n";
    }

    return 0;
}