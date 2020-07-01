#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int numberCnt, cases;
    cin >> numberCnt >> cases;

    int* sumTable = new int[numberCnt];

    for (int i = 0; i < numberCnt; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (i == 0) {
            sumTable[i] = tmp;
        }
        else {
            sumTable[i] = sumTable[i-1] + tmp;
        }
    }

    while (cases--) {
        int startIdx, endIdx;
        scanf("%d %d", &startIdx, &endIdx);
        printf("%d\n", sumTable[endIdx-1] - sumTable[startIdx-2]);
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