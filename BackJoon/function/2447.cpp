#include <iostream>

using namespace std;

// 모양틀 초기화
bool shape[2187][2187] = {false};

// 모양 형성
void makeShape(const int& height, const int& x, const int& y) {
    if (height == 3) {
        shape[y][x] = true;
        shape[y][x+1] = true;
        shape[y][x+2] = true;
        shape[y+1][x] = true;
        shape[y+1][x+2] = true;
        shape[y+2][x] = true;
        shape[y+2][x+1] = true;
        shape[y+2][x+2] = true;
        return;
    }
    makeShape(height / 2, x + 3, y);
}

int main() {

    // 높이 입력
    int height = 0;
    cin >> height;

    makeShape(height, 0, 0);

    for (int yIndex = 0; yIndex < height; ++yIndex) {
        for (int xIndex = 0; xIndex < height; ++xIndex) {
            if (shape[yIndex][xIndex]) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}