#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string& str, const char& delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}

int main() {

    string inputStr;
    cin.ignore();
    getline(cin, inputStr);

    vector<string> results = split(inputStr, ' ');

    cout << results.size() << endl;

    return 0;
}