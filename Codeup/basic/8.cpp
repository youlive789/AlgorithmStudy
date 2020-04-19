#include <iostream>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void move(int arr[][10], int x, int y) {
    if (arr[y][x] == 2) {
        arr[y][x] = 9;
        return;
    }

    arr[y][x] = 9;

    if (arr[y][x+1] != 1) {
        move(arr, x+1, y);
    } 
    else if (arr[y+1][x] != 1 && arr[y][x+1] != 0) {
       move(arr, x, y+1);
    }
    
}

int main() {

    int table[10][10];

    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            int t;
            cin >> t;
            table[i][j] = t;
        }
    }

    move(table, 1, 1);

    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}