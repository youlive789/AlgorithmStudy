#include <iostream>
#include <string>
#include <set>

using namespace std;

string getString(int nowIndex, int distance, string target) {
    string result = "";
    result += target[nowIndex];
    result += target[nowIndex+distance];
    return result;
}

int main() {

    while (true) {
        string target;
        cin >> target;
        if (target == "*") break;

        bool notSuprise = false;

        for (int distance = 1; distance <= target.size()-1; ++distance) {

            set<string> checker;
            for (int idx = 0; idx <= target.size()-1-distance; ++idx) {
                string sub = getString(idx, distance, target);
                if (checker.find(sub) == checker.end()) {
                    checker.insert(sub);
                }
                else {
                    notSuprise = true;
                }
            }
        }

        if (notSuprise) {
            cout << target << " is NOT surprising." << "\n";
        }
        else {
            cout << target << " is surprising." << "\n";
        }
    }

    return 0;
}