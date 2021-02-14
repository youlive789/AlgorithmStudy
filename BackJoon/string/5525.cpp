#include <iostream>
#include <string>

using namespace std;

int main() {

    int repeatNumber;
    cin >> repeatNumber;

    string ioi;
    ioi.reserve(3000000);
    ioi.append("IOI");
    for (int idx = 1; idx < repeatNumber; idx++) {
        ioi.append("OI");
    }

    int length;
    string target;
    cin >> length >> target;

    int answer = 0;
    for (int idx = 0; idx < length - ioi.size(); idx++) {
        if (target.substr(idx, ioi.size()) == ioi) {
            answer++;
        }
    }
    
    cout << answer << endl;

    return 0;
}