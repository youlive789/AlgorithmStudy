#include <iostream>

using namespace std;

char board[100][100];

int main() {

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> board[i][j];
        }
    }

    int command;
    cin >> command;

    if (command == 3) {
        for (int j = size; j >= size; j--) {
            for (int i = size; i >= 0; i--) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    else if (command == 2) {
        for (int i = 0; i < size; i++) {
            for (int j = size; j >= 0; j--) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}