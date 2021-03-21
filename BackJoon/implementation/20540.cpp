#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    string input;
    cin >> input;

    map<char,char> mbti = {{'E','I'}, {'I', 'E'}, {'S', 'N'}, {'N', 'S'}, {'T', 'F'}, {'F', 'T'}, {'J', 'P'}, {'P', 'J'}};
    for (auto c : input) {
        cout << mbti[c];
    }
    cout << endl;

    return 0;
}