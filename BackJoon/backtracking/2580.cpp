#include <iostream>
#include <string>
using namespace std;

int board[9][9];

int printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    // 초기화
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
            
    

    return 0;
}