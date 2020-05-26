#include <iostream>

using namespace std;

bool grid[10000000];

void eratos() {
    for (int i = 2; i < 10000000; i++) {
        if (grid[i]) {
            for (int j = i * 2; j < 10000000; j += i) {
                grid[j] = false;
            }
        }
    }
}

int main() {

    for (int i = 2; i < 10000000; i++) {
        grid[i] = true;
    }

    eratos();

    int answer = 0;
    for (int i = 2; i < 10000000; i++) {
        if (grid[i]) answer++;
        if (answer == 10001) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}