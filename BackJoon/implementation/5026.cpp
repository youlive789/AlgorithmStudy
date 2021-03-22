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

    int count;
    cin >> count;

    string equation;
    while (count--) {
        cin >> equation;
        if (equation != "P=NP") {
            
            vector<string> splited = split(equation, '+');

            int first, second, answer;
            first = stoi(splited.at(0));
            second = stoi(splited.at(1));
            answer = first + second;
            cout << answer << endl;
        }
        else {
            cout << "skipped" << endl;
        }
    }

    return 0;
}