#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    map<string, string> addressTable;

    int addressCount, targetCount;
    cin >> addressCount >> targetCount;

    for (int idx = 0; idx < addressCount; idx++) {
        string address, password;
        cin >> address >> password;

        addressTable[address] = password;
    }

    for (int idx = 0; idx < targetCount; idx++) {
        string targetAddress;
        cin >> targetAddress;

        cout << addressTable[targetAddress] << "\n";
    }

    return 0;
}