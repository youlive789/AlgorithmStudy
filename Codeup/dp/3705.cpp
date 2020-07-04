#include <cstdio>

using namespace std;

int sumTable[100000];

int main() {

    int cases;
    scanf("%d", cases);

    int sum = 0;
    for (int i = 0; i < cases; i++) {
        int tmp;
        scanf("%d", &tmp);
        
        sum += tmp;
        sumTable[i] = sum;
    }

    return 0;
}