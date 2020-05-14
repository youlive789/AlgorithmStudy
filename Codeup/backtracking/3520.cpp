#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
bool chess[13][13];

void queen(int col, int N) {
    
}

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            chess[i][j] = true;
        }
    }

    queen(0, N);
    cout << answer << endl;

    return 0;
}