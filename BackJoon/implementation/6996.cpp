#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        string a, b;
        cin >> a >> b;

        int aCharacter[26] = {0,};
        int bCharacter[26] = {0,};

        for (char aChar : a) {
            aCharacter[aChar-'0'-49]++;
        }

        for (char bChar : b) {
            bCharacter[bChar-'0'-49]++;
        }

        string back = " are anagrams.";
        for (int idx = 0; idx < 26; idx++) {
            if (aCharacter[idx] != bCharacter[idx]) {
                back = " are NOT anagrams.";
                break;
            }
        }

        cout << a << " & " << b << back << endl;
    }

    return 0;
}