#include <iostream>
#include <string>
#include <set>

using namespace std;

string getSubString(int nowIndex, int distance, string target) {
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

        /**
         * distance와 인덱스 루프 순서를 바꿔야함!!!!
         */

        for (int idx = 0; idx < target.size()-1; ++idx) {

            set<string> checker;
            set<string>::iterator notFound = checker.end();

            string nowTarget = target.substr(idx);

            for (int distance = 1; distance <= nowTarget.size()-1;  ++distance) {
                string sub = getSubString(0, distance, nowTarget);
                cout << idx << ":" << distance << " " << sub << endl;
                if (checker.find(sub) == notFound) {
                    checker.insert(sub);
                }
                else {
                    notSuprise = true;
                }
            }

            if (notSuprise) break;
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