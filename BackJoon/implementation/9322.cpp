#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insertWords(const int& wordCount, vector<string>& container) {
    for (int i = 0; i < wordCount; ++i) {
        string target;
        cin >> target;
        container.push_back(target);
    }
}

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        int wordCount;
        cin >> wordCount;

        vector<string> firstKey, secondKey, secret;
        insertWords(wordCount, firstKey);
        insertWords(wordCount, secondKey);
        insertWords(wordCount, secret);
        
        vector<int> code;
        for (auto secondWord : secondKey) {
            for (int idx = 0; idx < wordCount; ++idx) {
                if (secondWord == firstKey[idx]) {
                    code.push_back(idx);
                }
            }
        }

        int secretIndex = 0;
        for (int i = 0; i < wordCount; ++i) {
            for (int idx = wordCount - 1; idx >= 0; --idx) {
                if (secretIndex == code[idx]) {
                    cout << secret.at(idx) << " ";
                    secretIndex++;
                }
            }
        }
        cout << "\n";
    }

    return 0;
}