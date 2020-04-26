#include <iostream>
#include <cstdio>

using namespace std;

int supersum(int k, int n) {
    if (k == 0) return n;
    int answer = 0;
    for (int i = 1; i <=n; i++) {
        answer += supersum(k-1, i);
    }
    return answer;
}

int main() {
    int k, n;
    while ( scanf("%d %d", &k, &n) != EOF)
        printf("%d\n", supersum(k, n));

    return 0;
}