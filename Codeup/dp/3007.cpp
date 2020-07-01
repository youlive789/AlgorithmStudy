#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

int * numbers;
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

    numbers = new int[numberCnt];

    for (int i = 0; i < numberCnt; i++) {
        int tmp;
        cin >> tmp;
        numbers[i] = tmp;
    }

    while (cases--) {
        int startIdx, endIdx;
        cin >> startIdx >> endIdx;

        startIdx--;
        endIdx--;

        cout << sums(startIdx, endIdx) << endl;
    }

    return 0;
}

/*
6 3
3 5 2 1 4 3 
2 4
1 1
1 3
*/