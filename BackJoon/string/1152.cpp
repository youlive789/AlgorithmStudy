#include <iostream>
#include <string>
#include <string.h>
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

    char* inputStr;
    scanf("%[^\n]\n", inputStr); 

    int cnt = 0;
    char* token;

    while (token != NULL) {
        
        token = strtok(inputStr, " ");
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}