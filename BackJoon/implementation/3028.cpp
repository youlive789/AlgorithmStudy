#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int cupHolders[3] = {1, 0, 0};

    string changeOrder;
    cin >> changeOrder;

    for (auto change : changeOrder) {
        switch (change)
        {
        case 'A':
            swap(cupHolders[0], cupHolders[1]);
            break;
        case 'B':
            swap(cupHolders[1], cupHolders[2]);
            break;
        case 'C':
            swap(cupHolders[0], cupHolders[2]);
            break;
        default:
            break;
        }
    }

    for (int index = 0; index < 3; ++index) {
        if (cupHolders[index] == 1) {
            cout << index+1 << endl;
        }
    }

    return 0;
}