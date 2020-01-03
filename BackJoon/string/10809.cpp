#include <iostream>
#include <string>

using namespace std;

int main() {

    string inputStr;
    cin >> inputStr;

    int charTable[123];
    int strLength = inputStr.length();

    // 97번부터 시작
    for (int index = 0; index < 123; index++) {
        charTable[index] = -1;
    }

    for (int index = 0; index < strLength; index++) {
        for (int charIndex = 97; charIndex < 123; charIndex++) {
            if (static_cast<int>(inputStr[index]) == charIndex && charTable[charIndex] == -1) {
                charTable[charIndex] = index;
            }
        }
    }
    
    for (int index = 97; index < 123; index++) {
        cout << charTable[index] << " ";
    }

    return 0;
}