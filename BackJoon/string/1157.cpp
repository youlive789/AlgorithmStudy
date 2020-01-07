#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    map<int, int> alphabetTable;

    string inputStr;
    cin >> inputStr;

    int lenthInputStr = inputStr.length();

    // 알파벳 테이블에서 키를 이용해 현재 단어를 찾는다.
    for (int index = 0; index < lenthInputStr; index++) {
        int currentAlphabet = static_cast<int>(inputStr[index]);

        // 소문자를 대문자로 변경
        if (currentAlphabet >= 97) {
            currentAlphabet -= 32;
        }

        // 키가 없다면 테이블에 키값과 회수 1을 세팅한다.
        if (alphabetTable.find(currentAlphabet) == alphabetTable.end()) {
            alphabetTable.insert(make_pair(currentAlphabet, 1));
        }
        // 키가 있다면 회수 1을 더한다.
        else {
            alphabetTable[currentAlphabet] += 1;
        }
    }

    // 최대값을 찾는다. 
    // 최대값이 두개 이상이라면 ? 출력
    int maxValue = 0;
    int maxKey = 0;
    bool redundant = false;
    for (auto iter = alphabetTable.begin(); iter != alphabetTable.end(); iter++) {
        if (iter->second > maxValue) {
            maxKey = iter->first;
            maxValue = iter->second;
            redundant = false;
        }
        else if (iter->second == maxValue) {
            redundant = true;
        }
    }

    if (redundant) {
        cout << "?" << endl;
    }
    else {
        cout << static_cast<char>(maxKey) << endl;
    }

    return 0;
}