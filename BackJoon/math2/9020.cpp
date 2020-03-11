#include <iostream>
#include <vector>

using namespace std;

/*
골드바흐 파티션
4 = 2 + 2
6 = 3 + 3

1. 주어진 범위의 에라토스 채를 생성
2. 두 개의 루프를 순회하면서 골드바흐 파티션 탐색
*/

void findPartition(const int& testNumber, const bool* eratos, const int& lengthEratos) {
    int diffPartition = 999999;
    int answer1 = 0, answer2 = 0;
    for (int i = 2;  i <= lengthEratos; i++) {
        if (eratos[i]) {
            for (int j = i; j <= lengthEratos; j++) {
                bool prime = eratos[j];
                bool partition = (i + j == testNumber) ? true : false;
                if (prime && partition) {
                    if (diffPartition > j - i) {
                        answer1 = i, answer2 = j;
                    }
                }
            }
        }
    }
    if (answer1 != 0 && answer2 != 0) {
        cout << answer1 << " " << answer2 << endl;
    }
}

int main() {

    int cases;
    cin >> cases;
    while (cases--) {
        int testNumber;
        cin >> testNumber;

        bool eratosGrid[testNumber + 1];
        for (int index = 0; index < testNumber + 1; index ++) {
            eratosGrid[index] = true;
        }

        int i = 2, j = 4;
        while (i * i <= testNumber) {
            if (eratosGrid[i]) {
                while (j <= testNumber) {
                    eratosGrid[j] = false;
                    j += i;
                }
            }
            i += 1;
            j = i * 2;
        }
        findPartition(testNumber, eratosGrid, sizeof(eratosGrid)/sizeof(bool));
    }
    return 0;
}