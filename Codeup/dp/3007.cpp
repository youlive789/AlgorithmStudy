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
        startIdx--;
        endIdx--;

        int sum = 0;

        if (startIdx - endIdx == 0) {
            sum = numbers[startIdx];
        }
        else {
            for (int i = startIdx; i <= endIdx; i++) {
                sum += numbers[i];
            }
        }

        printf("%d\n", sum);
    }
    

    return 0;
}