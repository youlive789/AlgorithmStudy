#include <iostream>
#include <cmath>

using namespace std;

int answer = 0;
int printCount = 0;
int chess[13];

bool search(int row, int N) {
    for (int i = 0; i < row; i++) {
        if (chess[i] == chess[row]) return false;
        if (abs(chess[i] - chess[row]) == abs(i - row)) return false;
    }
    return true;
}

void queen(int row, int N) {

    if (row == N) {
        if (printCount < 3) {
            printCount++;
            for (int i = 0; i < N; i++) {              
                cout << chess[i] + 1 << " ";
            }    
            cout << endl;       
        }
        answer++;
        return;
    }
    
    for (int i = 0; i < N; i++) {
        chess[row] = i;
        if (search(row, N)) {
            queen(row+1, N);
        }
    }
}

int main() {

    int N;
    cin >> N;

    queen(0, N);
    cout << answer << endl;

    return 0;
}