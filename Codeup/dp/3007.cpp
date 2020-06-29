#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> numbers;

int main() {

    int numberCnt, cases;
    cin >> numberCnt >> cases;

    for (int i = 0; i < numberCnt; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    while (cases--) {
        int startIdx, endIdx;
        cin >> startIdx >> endIdx;
    }
    

    return 0;
}