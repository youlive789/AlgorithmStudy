#include <iostream>

using namespace std;

#define SIZE 5
#define SIZE_T 4


int table[SIZE][SIZE];

int main() {

    int origin = (SIZE * SIZE) - SIZE_T;
    int row = 0, col = SIZE_T;
    int trigger = 0; // 0: 좌측, 1: 하단, 2: 우측, 3:상단

    int answer = 0;

    while (true) {
       
        cout << row << " " << col << endl;


        table[row][col] = origin;
        origin++;

        // 이동수행
        // 좌측으로 이동중이였다면
        if (trigger == 0) {
            col--;
        }
        // 하단으로 이동중이였다면
        else if (trigger == 1) {
            row++;
        }
        // 우측으로 이동중이였다면
        else if (trigger == 2) {
            col++;
        }
        // 상단으로 이동중이였다면
        else if (trigger == 3) {
            row--;
        }

        if (row == 500 && col == 500) break;

        // 방향설정
        // 우측으로 이동중이였다면
        if (trigger == 0) {
            // 경계조건
            if (col >= 0) {
                if (col == 0 || table[row][col] > 0) {
                    trigger = 1;
                }
            }
        }
        // 하단으로 이동중이였다면
        else if (trigger == 1) {
            // 경계조건
            if (row <= SIZE_T) {
                if (row == SIZE_T || table[row][col] > 0) {
                    trigger = 2;
                }
            }
        }
        // 좌측으로 이동중이였다면
        else if (trigger == 2) {
            // 경계조건
            if (col <= SIZE_T) {
                if (col == SIZE_T || table[row][col] > 0) {
                    trigger = 3;
                }
            }
        }
        // 상단으로 이동중이였다면
        else if (trigger == 3) {
            // 경계조건
            if (row >= 0) {
                if (row == 0 || table[row][col] > 0) {
                    trigger = 0;
                }
            }
        }


    }

    // for (int row = 0; row < 1001; row++)
    //     for (int col = 0; col < 1001; col++)
    //         cout << table[row][col] << " ";
    //     cout << endl;


    return 0;
}