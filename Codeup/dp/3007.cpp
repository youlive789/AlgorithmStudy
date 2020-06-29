#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

int lastStartIdx, lastEndIdx;

int main() {

    for (int i = 0; i < 1000001; i++)
        cache[i] = -9999999;

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

        cout << sum << endl;
    }
    

    return 0;
}