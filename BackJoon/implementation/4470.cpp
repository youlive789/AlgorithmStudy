#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector<string> texts;

    int lineCount;
    cin >> lineCount;
    cin.ignore();

    for (int i = 0; i < lineCount; i++) {
        string tmp;
        getline(cin, tmp);
        texts.push_back(tmp);
    }

    for (int i = 0; i < texts.size(); ++i) {
        cout << i+1 << ". " << texts.at(i) << endl;
    }

    return 0;
}