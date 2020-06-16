#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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

    string nameString;
    ifstream fp("names.txt");
    while (getline(fp, nameString)) {}
    
    vector<string> nameTable = split(nameString, ',');
    sort(nameTable.begin(), nameTable.end());

    int idx = 1, answer = 0;
    for (string name : nameTable) {
        int res = 0;
        for (char c : name) {
            res += ((int)c - 64);
        }
        answer += res * idx;
        idx++;
    }

    cout << answer << endl;

    return 0;
}