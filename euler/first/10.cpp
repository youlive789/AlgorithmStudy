#include <iostream>

using namespace std; 

bool grid[2000003];

void eratos() {
    for (int i = 2; i < 2000003; i++) {
        if (grid[i]) {
            for (int j = i * 2; j < 2000003; j += i) {
                grid[j] = false;
            }
        }
    }
}

int main() {
    for (int i = 2; i < 2000003; i++)
        grid[i] = true;

    eratos();

    long long sum = 0;
    for (int i = 2; i <= 2000000; i++) {
        if (grid[i]) {
            sum += i;
        }
    }

    cout << sum << endl;
}