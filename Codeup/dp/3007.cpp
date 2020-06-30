#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> numbers;
map<string, int> cache;

int sums(int start, int end) {
    if (start == end) {
        return numbers[start];
    }
    else {
        string nowIndex = to_string(start) + to_string(end);
        if (cache[nowIndex]) {
            return cache[nowIndex];
        }
        else {
            return cache[nowIndex] = numbers[start] + sums(start + 1, end);
        }
    }
}

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

        cout << sums(startIdx, endIdx) << endl;
    }

    // cout << sums(0, 2) << endl;

    return 0;
}