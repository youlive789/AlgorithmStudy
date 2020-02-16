#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    
    int numCount;
    cin >> numCount;

    int cntGroupWord = 0;

    while (numCount--) {
        string targetStr;
        cin >> targetStr;

        set<char> excludeChar;
        bool groupWord = true;
        char lastChar;
        for (int strIndex = 0; strIndex < targetStr.size(); strIndex++) {
            char curChar = targetStr[strIndex];

            // 처음보는 문자라면
            if (excludeChar.find(curChar) == excludeChar.end()) {
                excludeChar.insert(curChar);
                lastChar = curChar;
                continue;
            }
            // 제외집합에 포함되지만 바로 이전에 나왔던 글자라면
            else if (curChar == lastChar) {
                lastChar = curChar;
                continue;
            }
            // 그 외의 경우라면
            else {
                lastChar = curChar;
                groupWord = false;
                break;
            }
        }

        if (groupWord) {
            ++cntGroupWord;
        }
    }

    cout << cntGroupWord << endl;

    return 0;
}