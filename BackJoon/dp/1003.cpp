#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>

using namespace std;

int cache[41];

long fibo(int n) {
    if (n == 0) {
        cache[n] = 1;
        return 0;
    }
    else if (n == 1) {
        cache[n] = 1;
        return 1;
    }
    else {
        if (cache[n] != -1) return cache[n];
        return cache[n] = fibo(n - 1) + fibo(n - 2);
    }
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int temp;
        cin >> temp;

        memset(cache, -1, sizeof(cache));

        fibo(temp);
        if (temp == 0) {
            printf("%d %d\n", 1, 0);
        }
        else if (temp == 1) {
            printf("%d %d\n", 0, 1);
        }
        else {
            printf("%d %d\n", cache[temp-1], cache[temp]);
        }
        
    }
    return 0;
}