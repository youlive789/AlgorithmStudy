#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}

int main() {

    long long result = 0;

    string target, s;
    while (getline(cin, s)) {
        target += s;
    }

    vector<string> splited = split(target, ',');
    for (auto ele : splited) {
        if (!ele.empty()) {
            result += stoi(ele);
        }
    }

    cout << result << endl;
    return 0;
}