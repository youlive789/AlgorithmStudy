#include <iostream>
#include <math.h>

using namespace std;

#define SIZE 1001
#define SIZE_T 1000


int table[SIZE][SIZE];

int main() {

    int origin = (SIZE * SIZE);
    int row = 0, col = SIZE_T;
    int trigger = 0; // 0: 좌측, 1: 하단, 2: 우측, 3:상단

    long long unsigned int answer = 0;

    int step = SIZE * SIZE;

    while (step--) {
       
        if (abs(row - col) == 0 || abs(row + col) == SIZE_T) answer += origin;

        table[row][col] = origin;
        origin--;

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

        // 방향설정
        // 우측으로 이동중이였다면
        if (trigger == 0) {
            // 경계조건
            if (col == 0 || table[row][col-1] > 0) {
                trigger = 1;
            }
            
        }
        // 하단으로 이동중이였다면
        else if (trigger == 1) {
            // 경계조건
            if (row == SIZE_T || table[row+1][col] > 0) {
                trigger = 2;
            }
        }
        // 좌측으로 이동중이였다면
        else if (trigger == 2) {
            // 경계조건
            if (col == SIZE_T || table[row][col+1] > 0) {
                trigger = 3;
            }
        }
        // 상단으로 이동중이였다면
        else if (trigger == 3) {
            // 경계조건
            if (row == 0 || table[row-1][col] > 0) {
                trigger = 0;
            }
        }
    }

    cout << answer << endl;

    return 0;
}