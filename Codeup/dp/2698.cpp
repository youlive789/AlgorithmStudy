#include <iostream>
#include <cstdio>

using namespace std;

int result = 0;

void move(int N, char start, char to) {
    printf("%d : %c->%c\n", N, start, to);
    result++;
}

void hanoi(int N, char start, char via, char to) {
    if (N == 1) {
        move(N, start, via);
        move(N, via, to);
    }
    else {
        hanoi(N-1, start, via, to);
        move(N, start, via);
        hanoi(N-1, to, via, start);
        move(N, via, to);
        hanoi(N-1, start, via, to);
    }
}

int main() {
    int N;
    cin >> N;
    hanoi(N, 'A', 'B', 'C');
    cout << result << endl;
    return 0;
}