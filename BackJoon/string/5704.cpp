#include <iostream>
#include <string>
#include <map>

using namespace std;

void initCharTable(map<char, bool>& charTable) {
    for (int charIdx = 97; charIdx <= 122; ++charIdx) {
        char targetChar = (char) charIdx;
        charTable[targetChar] = false;
    }
}

int main() {

    map<char, bool> charTable;

    while (true) {
        string check;
        getline(cin, check);

        if (check == "*") break;

        initCharTable(charTable);

        for (auto checkChar: check) {
            if (checkChar == ' ') continue;
            charTable[checkChar] = true;
        }

        bool isPangram = true;
        for (auto tableElement: charTable) {
            if (!tableElement.second) {
                isPangram = false;
            }
        }

        if (isPangram) {
            cout << "Y" << "\n";
        }
        else {
            cout << "N" << "\n";
        }
    }
}