#include <cstdio>

using namespace std;

unsigned long combCache[100][100];

unsigned long comb(int n, int r) {
    if (n == r || r == 0 || n == 0) {
        return 1;
    }
    else {
        if (combCache[n][r]) {
            return combCache[n][r];
        }
        else {
            return combCache[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
        }
    }
}

void pascal(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%lu ", comb(i, j));
        }
        printf("\n");
    }
}

int main() {

    int n;
    scanf("%d", &n);

    pascal(n);

    return 0;
}