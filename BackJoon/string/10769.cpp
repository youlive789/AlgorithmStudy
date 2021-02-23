#include <iostream>
#include <string>

using namespace std;

int main() {

    string sentence;
    getline(cin, sentence);

    string answer;
    int sentenceLength = sentence.length();
    if (sentenceLength <= 2) {
        cout << "none" << endl;
        exit(0);
    }

    int happyCount = 0, sadCount = 0;
    for (int i = 0; i < sentenceLength - 2; i++) {
        if (sentence.at(i) == ':' && sentence.at(i+1) == '-' && sentence.at(i+2) == ')') {
            happyCount++;
            continue;
        }

        if (sentence.at(i) == ':' && sentence.at(i+1) == '-' && sentence.at(i+2) == '(') {
            sadCount++;
            continue;
        }
    }
   
    if (happyCount == 0 && sadCount == 0) {
        cout << "none" << endl;
    }
    else if (happyCount > sadCount) {
        cout << "happy" << endl;
    }
    else if (happyCount < sadCount) {
        cout << "sad" << endl;
    }
    else {
        cout << "unsure" << endl;
    }

    return 0;
}