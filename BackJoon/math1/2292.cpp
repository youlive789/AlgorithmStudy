#include <iostream>
#include <cmath>

using namespace std;

int getNextTableNumber(const int& index, const int& firstNum, const int& firstDiff) {
    if (index < 3) throw logic_error("인덱스는 3보다 커야합니다!");
    return firstNum + ((index - 1) * ((2 * firstDiff) + (index - 2) * 6) / 2);
}

int main() {

    int tableSize;
    cin >> tableSize;

    int tableRows = static_cast<int>(ceil(static_cast<double>(tableSize) / 6));

    for (int tableIndex = 2; tableIndex < tableSize; tableIndex++) {
    
    }

    return 0;
}