#include <iostream>
#include <string>
#include <vector>
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

    string input;
    getline(cin, input);

    vector<string> splited = split(input, ' ');

    int last = -9999999;
    bool result = true;
    for (auto number : splited) {
        if (last > stoi(number)) {
            result = false;
            break;
        }
        last = stoi(number);
    }

    if (result) {
        cout << "Good" << endl;
    }
    else {
        cout << "Bad" << endl;
    }

    return 0;
}