#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define TRIM_SPACE " \t\n\v"

using namespace std;

inline string trim(string& s,const string& drop = TRIM_SPACE) {
    string r=s.erase(s.find_last_not_of(drop)+1);
    return r.erase(0,r.find_first_not_of(drop));
}

int main() {

    int answer = 0;

    string inputStr;
    getline(cin, inputStr);

    inputStr = trim(inputStr);
    
    istringstream iss(inputStr);

    string target;
    while ( getline( iss, target, ' ' ) ) {
        ++answer;   
    }

    cout << answer << endl;

    return 0;
}