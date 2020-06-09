#include <iostream>
#include <map>
#include <cassert>

using namespace std;

map<int, int> cardinal = {
    {1, 3}, {2, 3}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 5}, {8, 5}, {9, 4}, {10, 3},
    {11, 6}, {12, 6}, {13, 8}, {14, 8}, {15, 7}, {16, 7}, {17, 9}, {18, 8}, {19, 8},
    {20, 6}, {30, 6}, {40, 5}, {50, 5}, {60, 5}, {70, 7}, {80, 6}, {90, 6}, {100, 7}
};

int getWordNumber(const int& num) {

    int number = num;
    int cnt = 0;

    // 100 이상인 경우
    if (number / 100 > 0) {
        cnt += cardinal[100] + cardinal[number / 100];
        number %= 100;
        if (number > 0) cnt += 3;       
    }

    if (number < 20) {
        cnt += cardinal[number];
    }
    else {
        cnt += cardinal[(number / 10) * 10];
        number %= ((number / 10) * 10);
        cnt += cardinal[number];
    }

    return cnt;
}

int main() {
    
    assert(getWordNumber(342) == 23);
    assert(getWordNumber(115) == 20);
    assert(getWordNumber(999) == 24);

    assert(getWordNumber(100) == 10);
    assert(getWordNumber(101) == 16);
    assert(getWordNumber(20) == 6);
    assert(getWordNumber(40) == 5);
    
    int test = 0;
    for (int i = 1; i <= 5; i++) {
        test += getWordNumber(i);
    }

    assert(test == 19);

    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        int nowNum = getWordNumber(i);
        cout << i << " " << nowNum << endl;
        sum += nowNum;
    }
    sum += 11;

    cout << sum << endl;
    
    return 0;
}