#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {

    string targetStr;
    cin >> targetStr;

    regex regexExp("(c=)|(c-)|(dz=)|(d-)|(lj)|(nj)|(s=)|(z=)");
    sregex_iterator iter(targetStr.begin(), targetStr.end(), regexExp);
    sregex_iterator end;

    int answer = 0;
    while(iter != end) {
        smatch match = *iter;
        ++answer ;
        ++iter;
    }

    targetStr = regex_replace(targetStr, regexExp, "");
    answer += targetStr.size();

    cout << answer << endl;
    return 0;
}