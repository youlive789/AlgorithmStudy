#include <iostream>
#include <string>
#include <iterator>
#include <regex>

using namespace std;

int main() {

    string sentence;
    cin >> sentence;

    regex happyFace(":-)");
    auto happyFaceBegin = sregex_iterator(sentence.begin(), sentence.end(), happyFace);
    auto happyFaceEnd = sregex_iterator();
    auto happyFaceCount = distance(happyFaceBegin, happyFaceEnd);

    regex sadFace(":-(");
    auto sadFaceBegin = sregex_iterator(sentence.begin(), sentence.end(), sadFace);
    auto sadFaceEnd = sregex_iterator();
    auto sadFaceCount = distance(sadFaceBegin, sadFaceEnd);

    if (happyFaceCount == 0 && sadFaceCount == 0) {
        cout << "none" << endl;
        exit(0);
    }

    if (happyFaceCount > sadFaceCount) {
        cout << "happy" << endl;
    }
    else if (happyFaceCount < sadFaceCount) {
        cout << "sad" << endl;
    }
    else {
        cout << "unsure" << endl;
    }

    return 0;
}