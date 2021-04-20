#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int count;
    cin >> count;

    vector<int> cords;
    cords.reserve(count);
    for (int i = 0; i < count; ++i) {
        cin >> cords[i];
    }

    sort(cords.begin(), cords.end());
    

    return 0;
}