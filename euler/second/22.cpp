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

    cout << (int)'Z' - 64 << endl;

    return 0;
}