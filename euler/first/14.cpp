#include <iostream>

using namespace std;

unsigned int grid[500000000];

unsigned int colatz(unsigned int N) {
    if (N == 1) return 1;
    
    if (N < 500000000) {
        if (grid[N]) {
            return grid[N];
        }
        else {
            if (N % 2 == 0) {
                return grid[N] = colatz(N / 2) + 1;
            }
            else {
                return grid[N] = colatz(3 * N + 1) + 1;
            }
        }
    }
    else {
        if (N % 2 == 0) {
            return colatz(N / 2) + 1;
        }
        else {
            return colatz(3 * N + 1) + 1;
        }
    }
}

int main() {

    int answer = 0;
    int result = -999;
    for (int i = 1000000; i >= 1; i--) {
        int num = colatz(i);
        if (result < num) {
            result = num;
            answer = i;
        }
    }

    cout << "정답 : " << answer << endl;

    return 0;
}