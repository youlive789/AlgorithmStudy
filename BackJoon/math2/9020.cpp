#include <iostream>
#include <cstring>

using namespace std;

/*
골드바흐 파티션
4 = 2 + 2
6 = 3 + 3

1. 주어진 숫자보다 작은 모든 소수를 구한다.
2. 구한 소수들의 조합 중 가능 작은 차이의 조합을 찾는다.

*/

bool* getEratos() {
    static bool eratos[10001];
    memset(eratos, true, sizeof(eratos));

    int i = 2, j = 4;
    while (i * i <= 10000) {
        if (eratos[i]) {
            while (j <= 10000) {
                eratos[j] = false;
                j += i;
            }
        }
        i++;
        j = i * 2;
    }

    return eratos;
}

int main() {
    
    bool* eratosGrid = getEratos();

    int cases;
    cin >> cases;

    while (cases--) {

        int testNumber;
        cin >> testNumber;

        for (int index = testNumber / 2; index > 1; index--) {
            bool bothPrime = (eratosGrid[index] && eratosGrid[testNumber - index]);
            if (bothPrime) {
                cout << index << " " << testNumber - index << endl;
                break;
            }
        }

    }
    return 0;
}