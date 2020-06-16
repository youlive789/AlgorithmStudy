#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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
    
    cout << nameString << endl;

    return 0;
}